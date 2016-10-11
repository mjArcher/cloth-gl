#ifndef VECTOR3
#define VECTOR3

#include <cmath>
#include <iostream>
using namespace std;
const int SIZE = 3;

class Vector3
{
  public:

    float X;
    float Y;
    float Z;

    Vector3();
    Vector3(float x, float y, float z);

    Vector3         operator+(const Vector3&) const;
    Vector3         operator-(const Vector3&) const;
    Vector3         operator-() const;
    Vector3         operator*(float) const;
    Vector3         operator/(float) const;

    float&          operator[](int x) { return X; }
    Vector3&        operator+=(const Vector3&);
    Vector3&        operator-=(const Vector3&);
    Vector3&        operator*=(float);
    Vector3&        operator/=(float);

    friend ostream& operator<<(ostream& os, const Vector3&);

    bool            operator==(const Vector3&) const;
    bool            operator!=(const Vector3&) const;

		/* static const unsigned int e_size = 13; */


    static const Vector3    Zero;
    static const float      Epsilon;
};


inline bool Vector3::operator==(const Vector3& vec) const
{
  return X == vec.X && Y == vec.Y && Z == vec.Z;
}

inline bool Vector3::operator!=(const Vector3& vec) const
{
  return X != vec.X || Y != vec.Y || Z != vec.Z;
}

inline Vector3 Vector3::operator+(const Vector3& vec) const
{
  return Vector3(X + vec.X, Y + vec.Y, Z + vec.Z);
}

inline Vector3 Vector3::operator-(const Vector3& vec) const
{
  return Vector3(X - vec.X, Y - vec.Y, Z - vec.Z);
}

inline Vector3 Vector3::operator-() const
{
  return Vector3(-X,-Y,-Z);
}

inline Vector3 Vector3::operator*(float num) const
{
  return Vector3(X * num, Y * num, Z * num);
}

inline Vector3 Vector3::operator/(float num) const
{
  return Vector3(X / num, Y / num, Z / num);
}

#endif
