#pragma once
#ifndef _MATRIX_H_
#define _MATRIX_H_
#include "MatrixException.h"
#include <iostream>

template < class T > 
class Matrix
{
	private:
		int sizeCollumns, sizeRows;
		T** values;

	public:
		Matrix(int rows, int collumns)
		{
			this->sizeCollumns = collumns;
			this->sizeRows = rows;
			values = new T*[rows];
			for (int i = 0; i < rows; i++)
			{
				values[i] = new T[collumns];
			}
		}

		Matrix(int rows, int collumns, T** vals)
		{
			this->sizeCollumns = collumns;
			this->sizeRows = rows;
			values = new T*[rows];
			for (int i = 0; i < rows; i++)
			{
				values[i] = new T[collumns];
			}

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < collumns; j++)
				{
					values[i][j] = vals[i][j];
				}
			}
		}

		Matrix(const Matrix<T> &m)
		{
			this->sizeCollumns = m.getSizeCollumns();
			this->sizeRows = m.getSizeRows();

			values = new T*[sizeCollumns];
			for (int i = 0; i < sizeCollumns; i++)
			{
				values[i] = new T[sizeRows];
			}

			for (int i = 0; i < sizeCollumns; i++)
			{
				for (int j = 0; j < sizeRows; j++)
				{
					values[i][j] = m.getValue(j, i);
				}
			}
		}

		~Matrix()
		{
			for (int i = 0; i < sizeCollumns; i++)
			{
				delete[] values[i];
			}
			delete[] values;
		}

		int getSizeCollumns() const
		{
			return sizeCollumns;
		}

		int getSizeRows() const
		{
			return sizeRows;
		}

		T getValue(int row, int collumn) const
		{
			return values[row][collumn];
		}

		void setValue(int row, int collumn, T value_) 
		{
			values[row][collumn] = value_;
		}

		T dotProduct(const Matrix<T> &second, int row, int collumn)
		{
			T result = 0;
			auto rows = second.getSizeRows();

			for (int i = 0; i < rows; i++)
			{
				result += (getValue(row, i) * second.getValue(i, collumn));
			}
			return result;
		}

		Matrix<T> operator* (Matrix<T> &right)
		{
			if (getSizeCollumns() != right.getSizeRows())
				throw MatrixException();

			Matrix<T> solution(getSizeRows(), right.getSizeCollumns());

			for (int i = 0; i < right.getSizeCollumns(); i++)
			{
				for (int j = 0; j < getSizeRows(); j++)
				{
					solution.setValue(j, i, dotProduct(right, j, i));
				}
			}
			return solution;
		}


		Matrix<T> operator+ (Matrix<T> &right)
		{
			if (this->sizeCollumns != right.getSizeCollumns() && this->sizeRows != right.getSizeRows())
				throw MatrixException();

			Matrix<T> solution(right.getSizeCollumns(), this->sizeRows);

			for (int i = 0; i < sizeCollumns; i++)
			{
				for (int j = 0; j < sizeRows; j++)
				{
					//solution[i][j] = values[i][j] + right.getValue(j, i);
					solution.setValue(j, i, (values[i][j] + right.getValue(j, i)));
				}
			}
			return solution;
		}

		void print()
		{
			for (int i = 0; i < sizeRows; i++)
			{
				for (int j = 0; j < sizeCollumns; j++)
				{
					std::cout << values[i][j] << " ";
				}
				std::cout << std::endl;
			}
		}
};
#endif