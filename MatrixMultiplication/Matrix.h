#pragma once
#ifndef _MATRIX_H_
#define _MATRIX_H_
template < class T > // dodaj ograniczenia
class Matrix
{
private:
	int sizeX, sizeY;
	T** values;

public:
	Matrix(int sizeX, int sizeY);
	~Matrix();
	T getvalue();

};
//#include "Matrix.cpp"
#endif

