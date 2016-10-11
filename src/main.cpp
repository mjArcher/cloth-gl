#include <iostream>
#include "Vector3.h"
#include "ParticleSystem.h"

using namespace std;

int main()
{
  float arr[3];
  /* for(int i = 0; i < 3; i++) */
  /*   cout << arr[i] << endl; */
  /* cout << ":w!" << endl; */
  Vector3 vec(1.0,2.0,4.0);
  Vector3 vec1(2.0,3.0,4.0);
  cout << vec << endl;
  cout << vec + vec1 << endl;

  ParticleSystem part;
  part.TimeStep();

}
