#include "Vector3.h"
#include <limits>

const Vector3 Vector3::Zero = Vector3(0,0,0);
const float Vector3::Epsilon = std::numeric_limits<float>::epsilon();

Vector3::Vector3()
{
}

Vector3::Vector3(float x, float y, float z) : X( x ) , Y( y ) , Z( z )
{
}

Vector3& Vector3::operator+=(const Vector3& vec)
{
  X += vec.X;
  Y += vec.Y;
  Z += vec.Z;
  return *this;
}

Vector3& Vector3::operator-=(const Vector3& vec)
{
  X -= vec.X;
  Y -= vec.Y;
  Z -= vec.Z;
  return *this;
}

Vector3& Vector3::operator*=(float num)
{
  X *= num;
  Y *= num;
  Z *= num;
  return *this;
}

Vector3& Vector3::operator/=(float num)
{
  this->X /= num;
  this->Y /= num;
  this->Z /= num;
  return *this;
}

ostream& operator<<(ostream& os, const Vector3& vec)
{
  os.precision(3);
  os << vec.X << " " << vec.Y << " " << vec.Z  << endl;
  return os;
}

