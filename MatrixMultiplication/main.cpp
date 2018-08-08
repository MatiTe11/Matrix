///vector of strings containing equations is converted int Matrix objects, which then can be multiplied using operator* (Jacobi parallel)
#include "Matrix.h"
#include <iostream>
//#include "Matrix.cpp"

int main()
{
	int one[3][2] = { 1,2,
					1,2,
					1,2 };
	int two[2][3] = { 3,3,3,
					4,4,4};
	int** on, **tw;
	on = new int*[3];
	tw = new int*[2];
	for (size_t i = 0; i < 3; i++)
	{
		on[i] = new int[2];
		if (i < 2)
			tw[i] = new int[3];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			on[i][j] = one[i][j];
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tw[i][j] = two[i][j];
		}
	}

	Matrix<int> o(3,2,on);
	Matrix<int> t(2, 3, tw);


	auto x = o * t;
	x.print();
	
}