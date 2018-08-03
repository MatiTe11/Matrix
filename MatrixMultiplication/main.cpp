///vector of strings containing equations is converted int Matrix objects, which then can be multiplied using operator* (Jacobi parallel)
#include "Matrix.h"
#include "Matrix.cpp"

int main()
{
	Matrix<int> m(7,7);
	auto x = m.getvalue();
}