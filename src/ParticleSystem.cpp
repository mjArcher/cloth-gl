#include "Vector3.h"
#include "ParticleSystem.h"

// Verlet integration step
void ParticleSystem::Verlet() {
  for(int i=0; i<NUM_PARTICLES; i++) {
    Vector3& x = m_x[i];
    Vector3 temp = x;
    Vector3& oldx = m_oldx[i];
    Vector3& a = m_a[i];
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

// Here constraints should be satisfied
void ParticleSystem::SatisfyConstraints() {
  // Ignore this function for now
}


void ParticleSystem::TimeStep() {
  AccumulateForces();
  Verlet();
  SatisfyConstraints();
}


