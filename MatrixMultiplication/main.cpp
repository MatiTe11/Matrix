///vector of strings containing equations is converted into Matrix objects, which then can be multiplied using operator* (Jacobi parallel)
#include "Matrix.h"
#include <iostream>
#include <string>

int main()
{
	try
	{
		Matrix<int> o("A.txt");
		Matrix<int> t("B.txt");

		auto x = o * t;
		x.print();
	}
	catch (MatrixException e)
	{
		std::cout << e.getErrMsg();
	}
	
	char p;
	std::cin >> p;
}