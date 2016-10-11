#ifndef PARTCILESYSTEM
#define PARTICLESYSTEM

#include "Vector3.h"
#include <cmath>

class ParticleSystem {
  const static int NUM_PARTICLES = 10;

  Vector3<float>     m_x[NUM_PARTICLES]; // Current positions
  Vector3<float>     m_oldx[NUM_PARTICLES]; // Previous positions
  Vector3<float>     m_a[NUM_PARTICLES]; // Force accumulators
  Vector3<float>     m_vGravity; // Gravity
  float       m_fTimeStep;
  public:
  void        TimeStep();
  private:
  void        Verlet();
  void        SatisfyConstraints();
  void        AccumulateForces();

  //    (constructors, initialization etc. omitted)
};

#endif
