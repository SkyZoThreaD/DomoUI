#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "DomoUI.h"

namespace DomoUI
{
	
class Exception
{
public:
	enum ExceptionType{
		Except_FileNotFound,
		Except_CorruptFile,
	};
	
	const std::string getComment();
	
	Exception(const enum ExceptionType, const std::string);
	~Exception();
private:
	enum ExceptionType Type;
	std::string Comment;
};

Exception *NewCorruptFileExcept(const std::string Filename, int linenb);
Exception *NewFileNotFoundExcept(const std::string FileName);
}

#endif // EXCEPTION_H

