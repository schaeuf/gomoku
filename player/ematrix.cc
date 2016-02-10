#include "matrix.cc"
#include "ematrix.h"

template<class T>
EMatrix<T>::EMatrix(T &defValue)
{
  one.setDefault(defValue);
  two.setDefault(defValue);
  three.setDefault(defValue);
  four.setDefault(defValue);
}

template <class T>
void 
EMatrix<T>::set(short row, short col, T value)
{
  if (row >= 0)
    if (col >= 0)
      one.set(row, col, value);
    else
      two.set(row, -(col+1), value);
  else
    if (col >= 0)
      four.set(-(row+1), col, value);
    else
      three.set(-(row+1), -(col+1), value);
      
}

template <class T>
& EMatrix<T>::get(short row, short col)
{
  if (row >= 0)
    if (col >= 0)
      return one.get(row, col);
    else
      return two.get(row, -(col+1));
  else
    if (col >= 0)
      return four.get(-(row+1), col);
    else
      return three.get(-(row+1), -(col+1));
}


