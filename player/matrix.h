// -*-c++-*-  Hey emacs, wake up, this is C++!

/* Christian Schaeufler
 * (C.) Copyright 1999, Christian Schaeufler
 */

#ifndef __MATRIX_H
#define __MATRIX_H

#include <stdio.h>
#include <string.h>

#define MIN(A,B) ((A) < (B) ? (A) : (B))

template <class T>
class Matrix{
private:
  unsigned short _rows, _cols;
  T *_defValue;			// Return defEntry if requested cell is empty
  // (NULL).
  T **_data;
  unsigned char _incStep;	// (0-[5]-255) Add incStep columns/rows
				// additional (to increase perfomance).
  newSize(unsigned short row, unsigned short col);
public:
  Matrix(T &defaultValue) : _rows(0), _cols(0), _incStep(5), \
    _defValue(&defaultValue), _data(NULL){};
  Matrix() : _rows(0), _cols(0), _incStep(5), _data(NULL) {};
  setDefault(T *defaultValue) {_defValue=defaultValue;};
  set(unsigned short row, unsigned short col, T entry);
  T &get(unsigned short row, unsigned short col);
  ~Matrix();
};


#endif
