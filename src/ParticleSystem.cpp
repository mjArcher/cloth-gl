#include "Vector3.h"
#include "stdio.h"
#include "ParticleSystem.h"
#include <iostream>
#include <fstream>
#include <iomanip>      // std::setfill, std::setw


#define NUM_ITERATIONS 1

ParticleSystem::ParticleSystem(int nodes)
{

  //we can calculate the number of constraints here.
  /* vector<Constraint> temp(NUM_CONSTRAINTS); */
  /* m_constraints = temp; */

  cout << "initial size " << m_constraints.size() << endl;



  initialiseParticleArray(nodes/6);
  cout << "initialised particle array" << endl;
  initialiseConnectivity(nodes/6); //assume square array of nodes.
  cout << "initialised connectivity " << endl;
  cout << "number of constraints " <<  m_constraints.size() << endl;
}

void ParticleSystem::initialiseParticleArray(int nodes) {
  float len = 5.0;
  //problem with this is that there is implicit ordering
  float x, y;
  int counter = 0;
  xnodes=nodes, ynodes=nodes;
  
  for (int i = 0; i < ynodes; i++){
    y = i*len;
    for (int j = 0; j < xnodes; j++){ // 
      x = j*len;
      Vector3<float> particle(x, y, 0);
      m_x[counter] = particle;
      counter++;
    }
  } 
  //output the particle array
  ofstream out;
  out.open ("particleArray.txt");
  out << "Particle array.\n";

  for(int i=ynodes-1; i>=0; i--) {
    cout << "\n";
    for (int j=0; j<xnodes; j++){
      /* printf("(%d, %d)\t",j,i); */
      cout << setw(5) << "(" << j << "," << i << ")" << '\t';
    }
  }

  for(int i=ynodes-1; i>=0; i--) {
    cout << "\n";
    for (int j=0; j<xnodes; j++) {
      /* printf("(%d, %d)\t",j,i); */
      cout << setw(5) << "(" << getParticlefromIndex(j, i) << ")" << '\t';
    }
  }
  out.close();
}

// fill on an xrow basis 
// i = row
// j = column

Vector3<float> ParticleSystem::getParticlefromIndex(int j, int i)
{
  int coord = i * xnodes + j;
  /* cout << "\n" << coord << endl; */
  return m_x[coord];
}

void ParticleSystem::initialiseConnectivity(int nodes) {
  
  // initialise all column connections and positions
  // nested for loop
  float len = 5.;
  int a, b, offset, n;
  n = nodes - 1;
  //all column
  //n = 5
  for(int off=0; off <= n; off++) {
    offset = off*n;
    for(int i=0; i<n; i++) {
      a = i + offset; 
      b = i + offset + 1;
      Constraint con(a, b, len);
      m_constraints.push_back(con);
    }
  }  

  //all row (from bottom)
  for(int i=0; i<=n; i++) {
    for(int off=0; off < n; off++) {
      offset = off*n; 
      a = offset + i;
      b = (off+1)*n + i;
      Constraint con(a, b, len);
      m_constraints.push_back(con);
    }  
  }

  cout << "Number of constraints " << endl;
  cout << m_constraints.size() << endl;

  // initialise all row connections 
  // there should be 60 constraints 
}


// Verlet time integration step
void ParticleSystem::Verlet() {

  for(int i=0; i<NUM_PARTICLES; i++) {
    Vector3<float>& x    = m_x[i];
    Vector3<float> temp  = x;
    Vector3<float>& oldx = m_oldx[i];
    Vector3<float>& a    = m_a[i];
    x += x-oldx+a*m_fTimeStep*m_fTimeStep;
    oldx = temp;
  }
}

// This function should accumulate forces for each particle
void ParticleSystem::AccumulateForces()
{    
  // All particles are influenced by gravity
  for(int i=0; i<NUM_PARTICLES; i++)  
    m_a[i] = m_vGravity;
}



void ParticleSystem::SatisfyConstraints() {

  //temp vectors
  Vector3<float> x1, x2;

  for(int j=0; j<NUM_ITERATIONS; j++) {
    for(int i=0; i<NUM_CONSTRAINTS; i++) {
      Constraint& c = m_constraints[i];
      Vector3<float>& x1 = m_x[c.particleA];
      Vector3<float>& x2 = m_x[c.particleB];
      Vector3<float> delta = x2-x1;
      float deltaLength = sqrt(dot(delta,delta)); // replace this sqr root
      float diff=(deltaLength-c.restLength)/deltaLength;
      x1 += delta*0.5*diff;
      x2 -= delta*0.5*diff;
    }

    // Constrain one particle of the cloth to origo
    m_x[0] = Vector3<float>(0,0,0);
  }
}


void ParticleSystem::TimeStep() {
  AccumulateForces();
  Verlet();
  SatisfyConstraints();
}


