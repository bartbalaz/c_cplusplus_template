#ifndef BX_EXCEPTION_HPP
#define BX_EXCEPTION_HPP

#include <iostream>
#include <exception>
#include <errno>


namespace Bx {
  namespace Basic {

    class Exception: public std::exception
    {
      public:
        Exception(const char* pFileName, const int lineNum,
          const char* pFormat...)
        
        Exception(const char* pFileName, const int lineNum,
          const int errno, const char* pFormat...);

        virtual const char* what() const throw();

      private:
        enum {
          header_size = 100,
          body_size = 200,
        };
      
        char _pMsg[header_size + body_size];

    };
  }
}

#define BX_EXCEPTION (args...) \
  throw Bx::Basic::Exception(__FILE__, __LINE__, args)

#define BX_EXCEPTION_E (args...) \
  throw Bx::Basic::Exception(__FILE__, __LINE__, ::errno, args)

#define BX_ASSERT (EXPRESSION, args...) \
  if(!EXPRESSION) BX_EXCEPTION (args)

#define BX_ASSERT_E (EXPRESSION, args...) \
  if(!EXPRESSION) BX_EXCEPTION_E (args) 

#endif