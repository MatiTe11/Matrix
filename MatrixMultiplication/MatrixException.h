#pragma once
#include <exception>
#include <string>

class MatrixException : public std::exception
{
private:
	std::string msg;

public:
	MatrixException(std::string err_msg);
	~MatrixException();
	std::string getErrMsg();
};

