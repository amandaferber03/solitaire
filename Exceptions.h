#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <utility>
#include <string>
#include <sstream>
#include <exception>

namespace Solitaire {
  class Exception : public std::exception
	{
	protected:
		std::string _message;
	public:
		Exception( void ) : _message( "" ) {}
		Exception(   std::string &message ) : _message( message ) {}
		  char *what( void )   noexcept { return _message.c_str(); }
	};
}
#endif
