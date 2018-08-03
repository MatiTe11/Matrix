#include "Matrix.h"

template < class T >
Matrix<T>::Matrix(int sizeX, int sizeY)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;

}

template < class T >
Matrix<T>::~Matrix()
{
	//delete A;
}

template < class T >
T Matrix<T>::getvalue()
{
	return 7;
}
