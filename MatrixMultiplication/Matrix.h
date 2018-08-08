#pragma once
#ifndef _MATRIX_H_
#define _MATRIX_H_
#include "MatrixException.h"
#include <iostream>

template < class T > 
class Matrix
{
	private:
		int sizeX, sizeY;
		T** values;

	public:
		Matrix(int sizeX, int sizeY)
		{
			this->sizeX = sizeX;
			this->sizeY = sizeY;
			values = new T*[sizeX];
			for (int i = 0; i < sizeX; i++)
			{
				values[i] = new T[sizeY];
			}
		}

		Matrix(int sizeX, int sizeY, T** vals)
		{
			this->sizeX = sizeX;
			this->sizeY = sizeY;
			values = new T*[sizeX];
			for (int i = 0; i < sizeX; i++)
			{
				values[i] = new T[sizeY];
			}

			for (int i = 0; i < sizeX; i++)
			{
				for (int j = 0; j < sizeY; j++)
				{
					values[i][j] = vals[i][j];
				}
			}
		}

		Matrix(const Matrix<T> &m)
		{
			this->sizeX = m.getSizeX();
			this->sizeY = m.getSizeY();

			values = new T*[sizeX];
			for (int i = 0; i < sizeX; i++)
			{
				values[i] = new T[sizeY];
			}

			for (int i = 0; i < sizeX; i++)
			{
				for (int j = 0; j < sizeY; j++)
				{
					values[i][j] = m.getValue(j, i);
				}
			}
		}

		~Matrix()
		{
			for (int i = 0; i < sizeX; i++)
			{
				delete[] values[i];
			}
			delete[] values;
		}

		int getSizeX() const
		{
			return sizeX;
		}

		int getSizeY() const
		{
			return sizeY;
		}

		T getValue(int row, int collumn) const
		{
			return values[collumn][row];
		}

		void setValue(int row, int collumn, T value_) 
		{
			values[collumn][row] = value_;
		}

		T dotProduct(Matrix<T> second, int row, int collumn)
		{
			T result = 0;
			for (int i = 0; i < second.getSizeY(); i++)
			{
				result += this->values[i][row] * second.getValue(i, collumn);
			}
			return result;
		}

		Matrix<T> operator* (Matrix<T> &right)
		{
			if (this->sizeX != right.getSizeY())
				throw MatrixException();

			Matrix<T> solution(right.getSizeX, this->sizeY);

			for (int i = 0; i < sizeX; i++)
			{
				for (int j = 0; j < sizeY; j++)
				{
					//solution[i][j] = dotProduct(right, j, i);
					solution.setValue(j, i, dotProduct(right, j, i));
				}
			}
			return solution;
		}


		Matrix<T> operator+ (Matrix<T> &right)
		{
			if (this->sizeX != right.getSizeX() && this->sizeY != right.getSizeY())
				throw MatrixException();

			Matrix<T> solution(right.getSizeX(), this->sizeY);

			for (int i = 0; i < sizeX; i++)
			{
				for (int j = 0; j < sizeY; j++)
				{
					//solution[i][j] = values[i][j] + right.getValue(j, i);
					solution.setValue(j, i, (values[i][j] + right.getValue(j, i)));
				}
			}
			return solution;
		}

		void print()
		{
			for (int i = 0; i < sizeY; i++)
			{
				for (int j = 0; j < sizeX; j++)
				{
					std::cout << values[j][i] << " ";
				}
				std::cout << std::endl;
			}
		}
};
#endif