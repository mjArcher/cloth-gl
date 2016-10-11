#include "Vector3.h"
#include <limits>

template <class T>
const Vector3<T> Vector3<T>::Zero = Vector3(0,0,0);

template <class T>
const T Vector3<T>::Epsilon = std::numeric_limits<T>::epsilon();

template <class T>
Vector3<T>::Vector3()
{
}

template <class T>
Vector3<T>::Vector3(T x, T y, T z) : X( x ) , Y( y ) , Z( z )
{
}

template <class T>
Vector3<T>& Vector3<T>::operator+=(const Vector3& vec)
{
  X += vec.X;
  Y += vec.Y;
  Z += vec.Z;
  return *this;
}

template <class T>
Vector3<T>& Vector3<T>::operator-=(const Vector3& vec)
{
  X -= vec.X;
  Y -= vec.Y;
  Z -= vec.Z;
  return *this;
}

template <class T>
Vector3<T>& Vector3<T>::operator*=(T num)
{
  X *= num;
  Y *= num;
  Z *= num;
  return *this;
}

template <class T>
Vector3<T>& Vector3<T>::operator/=(T num)
{
  this->X /= num;
  this->Y /= num;
  this->Z /= num;
  return *this;
}

/* template <class T> */
/* ostream& operator<<(ostream& os, const Vector3<T>& vec) */
/* { */
/*   os.precision(3); */
/*   os << vec.X << " " << vec.Y << " " << vec.Z  << endl; */
/*   return os; */
/* } */

/* template <typename float> ostream& operator<< <float>(ostream& os, const Vector3<float>& vec); */

template class Vector3<float>;
