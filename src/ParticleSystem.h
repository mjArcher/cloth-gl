#ifndef PARTCILESYSTEM
#define PARTICLESYSTEM

#include "Vector3.h"
#include <cmath>
#include <vector>

struct Constraint {
  int   particleA, particleB;
  float restLength;

  //default constructor
  Constraint(){};
  Constraint(int a, int b, float rl) : 
    particleA(a), particleB(b), restLength(rl) {}
};

class ParticleSystem {
  const static int NUM_PARTICLES = 36;
  const static int NUM_CONSTRAINTS = 60;
  const static int NUM_ITERATIONS = 1;

  std::vector<Constraint>     m_constraints;
  
  Vector3<float>     m_x[NUM_PARTICLES]; // Current positions
  Vector3<float>     m_oldx[NUM_PARTICLES]; // Previous positions
  Vector3<float>     m_a[NUM_PARTICLES]; // Force accumulators
  Vector3<float>     m_vGravity; // Gravity
  float              m_fTimeStep;

  public:
  int                xnodes,ynodes;
  void               TimeStep();

  ParticleSystem(int nodes);

  private:
  void               Verlet();
  void               SatisfyConstraints();
  void               AccumulateForces();
  Vector3<float>     getParticlefromIndex(int, int);
  void               initialiseParticleArray(int);
  void               initialiseConnectivity(int);


};

// first idea:
// N isn't correct here.
// horizontal followed by vertical connections n * n square arrayA
// where n corresponds to the number of nodes 
// number of edges is N = n - 1
// offset = 0 to n 
//
// determine connectivity all  column 0-1, 1-2, 2-3, 3-4, 4-5
//                                       n - n+1, n+1-n+2, n+2-n+3,
// n = 6,12,18,24,30
//                                      
// determine connectivity all row:  0-6, 6-12, 12-18, 18-24, 24-30
//                                       1-7, 7-13, 13-19, 19-25, 25-31
// 
// 
// number from left to right, bottom to top
// there should be 60 constraints for N x N = 36  where N = 6

// second idea:
// write array class and connectivity just comes out of how we index

// Here constraints should be satisfied

// nodes correspond to the number of 

//         5 -- 11-- 17-- * -- * -- 36 
//         |    |    |    |    |    | 
//         4 -- 10-- 16-- * -- * -- *
//         |    |    |    |    |    | 
//         3 -- 9 -- 15-- * -- * -- *
//         |    |    |    |    |    | 
//         2 -- 8 -- 14-- * -- * -- *
//         |    |    |    |    |    | 
//         1 -- 7 -- 13-- * -- * -- *
//         |    |    |    |    |    | 
//         0 -- 6 -- 12-- * -- * -- * 
// 36 nodes, 30 horizontal edges, 30 vertical edges

#endif
