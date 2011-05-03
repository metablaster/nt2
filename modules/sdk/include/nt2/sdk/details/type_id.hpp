//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_DETAILS_TYPE_ID_HPP_INCLUDED
#define NT2_SDK_DETAILS_TYPE_ID_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
/*!
 * \file
 * Defines the type_id and display_type utility functions
 */
////////////////////////////////////////////////////////////////////////////////

#if (__GNUC__ && __cplusplus && __GNUC__ >= 3)
//==============================================================================
// Includes abi::__cxa_demangle
//==============================================================================
#include <cxxabi.h>
#endif

#include <string>
#include <cstdlib>
#include <typeinfo>
#include <iostream>
#include <nt2/sdk/details/ignore_unused.hpp>

namespace nt2 { namespace details
{
  //============================================================================
  // demangle a type name retrieved through typeid()
  //============================================================================
  inline std::string demangle(const char* name)
  {
    #if(__GNUC__ && __cplusplus && __GNUC__ >= 3)
    std::size_t len;
    int         stat;

    char* realname = ::abi::__cxa_demangle(name,NULL,&len,&stat);

    if(realname != NULL)
    {
      std::string out(realname);
      ::free(realname);
      return out;
    }
    else
    {
      return std::string("?");
    }
    #else
    std::string out(name);
    return out;
    #endif
  }
  
  std::ostream& indent(std::ostream& os, size_t depth)
  {
    for(size_t i=0; i<depth; ++i)
      os << "    ";
      
    return os;
  }
  
} }

namespace nt2
{
  //////////////////////////////////////////////////////////////////////////////
  /*!
   * Returns a string containing the demangled typename of a given type
   *
   * \param expr Expression which type is to be stringized
   * \return \c T type name as a readable \c std::string
   */
  //////////////////////////////////////////////////////////////////////////////
  template<typename T> inline std::string type_id(const T& expr = *((T*)0))
  {
    ignore_unused(expr);
    return details::demangle(typeid(T).name());
  }
  
  //////////////////////////////////////////////////////////////////////////////
  /*!
   * Display the demangled typename of a given type on the standard output.
   *
   * \param expr Expression which type is to be displayed
   */
  //////////////////////////////////////////////////////////////////////////////
  template<typename T> inline void display_type(const T& expr = *((T*)0))
  {
    std::string s = type_id<T>(expr);
    
    size_t depth = 0;
    bool prevspace = true;
    for(std::string::const_iterator it = s.begin(); it != s.end(); ++it)
    {
      switch(*it)
      {
        case '<':
          depth++;
          std::cout << *it;
          std::cout << '\n';
          details::indent(std::cout, depth);
          prevspace = true;
          break;
          
        case '>':
          depth--;
          std::cout << '\n';
          details::indent(std::cout, depth);
          std::cout << *it;
          prevspace = false;
          break;
          
        case ',':
          std::cout << *it;
          std::cout << '\n';
          details::indent(std::cout, depth);
          prevspace = true;
          break;
          
        case ' ':
          if(!prevspace)
            std::cout << *it;
          break;
          
        default:
          std::cout << *it;
          prevspace = false;
      }
    }
    std::cout << std::endl;
  }
}

#endif
