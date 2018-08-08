///vector of strings containing equations is converted int Matrix objects, which then can be multiplied using operator* (Jacobi parallel)
#include "Matrix.h"
#include <iostream>
//#include "Matrix.cpp"

int main()
{
	int one[3][2] = { 1,2,
					1,2,
					1,2 };
	int two[3][2] = { 3,4,
					3, 4,
					3, 4 };
	int** on, **tw;
	on = new int*[3];
	tw = new int*[3];
	for (size_t i = 0; i < 3; i++)
	{
		on[i] = new int[2];
		tw[i] = new int[2];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			on[i][j] = one[i][j];
			tw[i][j] = two[i][j];
		}
	}
	//std::cout << on[2][0];

	Matrix<int> o(3,2,on);
	Matrix<int> t(3, 2, tw);
	Matrix<int> l(3, 2);

	auto x = o + t;
	x.print();
	//t.print();
}