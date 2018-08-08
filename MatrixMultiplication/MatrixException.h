#pragma once
#include <exception>
class MatrixException : public std::exception
{
public:
	MatrixException();
	~MatrixException();
};

