#include "MatrixException.h"




MatrixException::MatrixException(std::string err_msg)
{
	msg = err_msg;
}


MatrixException::~MatrixException()
{
}

std::string MatrixException::getErrMsg()
{
	return msg;
}
