#include "DomoUI.h"

namespace DomoUI
{

Exception::Exception(const enum ExceptionType _Type, const std::string _Comment):Type(_Type), Comment(_Comment)
{
}

Exception::~Exception()
{
}

Exception *NewCorruptFileExcept(const std::string Filename, int linenb)
{
	return new Exception(Exception::Except_CorruptFile, std::string("File:")+Filename+" is corrupt line:"+std::to_string(linenb));
}

Exception *NewFileNotFoundExcept(const std::string FileName)
{
	return new Exception(Exception::Except_FileNotFound, std::string("File:")+FileName+" is not found" );
}

const std::string Exception::getComment()
{
	return Comment;
}

}