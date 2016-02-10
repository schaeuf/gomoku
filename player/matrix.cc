#include "matrix.h"

template <class T>
Matrix<T>::newSize(unsigned short rows, unsigned short cols)
{
  T **data = new T*[rows];	// Will become new matrix.
  unsigned short i;		// Counter for loops.

  if( _cols != cols)		// Run if number of columns have changed.
    for(i=0; i < MIN(_rows, rows); i++){ // Run through all mutuial elements
      data[i]=new T[cols]=_defValue; // 1. Create new row.
      memcpy (data[i], _data[i], MIN(_cols, cols)); //??? 2. Copy old into new.
      delete _data[i];
    }
  else				// Nummber of columns does not change.
    for(i=0; i < MIN(_rows, rows); i++) // Simply move each row of the old
      data[i]=_data[i];	// into the new matrix;

  /* Delete the remaining elements (if there are any). 
   * The elements befor have either already been delted or have been completly
   * taken over.*/
  for(i=rows; i < _rows; i++)
    delete _data[i];

  /* Analogous add the remaining elements IF the number has grown */
  for(i=_rows; i < rows; i++)
    data[i]=new T[cols]=_defValue;


 if (_data!=NULL)		// Delete the old Matrix
    delete[] *_data;

  _rows = rows;			// "Copy" back the new values
  _cols = cols;
  _data = data;

 
}


template <class T>
Matrix<T>::set(unsigned short row, unsigned short col, T entry)
{
  if (row>=_rows)			// Increase at least of rows.
    if(col>=_cols)		// Increase of rows AND columns.
      newSize(row+_incStep, col+_incStep);
    else			// Increase ONLY of rows.
      newSize(row + _incStep, _cols);
  else				// Number of rows have not increased but cols
				// may have.
    if(col>=_cols)		// ONLY number of columns increased.
      newSize(_rows, col+_incStep);
    
  _data[row][col]=entry;
}

template <class T>
& Matrix<T>::get(unsigned short row, unsigned short col)
{
  if ((row >= _rows) || (col >= _cols) || (_data == NULL))
    return _defValue;
  else
    return _data[row][col];
}

template <class T>
Matrix<T>::~Matrix()
{
  for (unsigned short i = 0; i < _rows; i++)
    delete[] _data[i];
  delete[] _data;
}










