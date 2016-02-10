// -*-c++-*-  Hey emacs, wake up, this is C++!

/* Christian Schaeufler
 * (C.) Copyright 1999, Christian Schaeufler
 */

#ifndef __EMATRIX_H
#define __EMATRIX_H

#include "matrix.h"

struct Point{
  short row;
  short col;
};

template <class T>
class EMatrix{
private:
  Matrix<T> one, two, three, four;
public:
  EMatrix(T &defValue);
  void set(short row, short col, T value);
  void set(Point point, T value) {set(point.row, point.col, value);};
  T &get(short row, short col); 
  T &get(Point point) {return get(point.row, point.col);};
};

#endif __EMATRIX_H
