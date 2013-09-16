//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2011 - 2013   MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_SDK_CONFIG_ENFORCE_PRECISION_HPP_INCLUDED
#define BOOST_SIMD_SDK_CONFIG_ENFORCE_PRECISION_HPP_INCLUDED

#include <boost/simd/sdk/config/arch.hpp>
#include <boost/dispatch/attributes.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>

#ifdef _MSC_VER
#include <float.h>
#endif

namespace boost { namespace simd { namespace config
{
  #ifdef BOOST_SIMD_ARCH_X86
  namespace x86
  {
    template<class T>
    struct x87_precision_flag;

    template<>
    struct x87_precision_flag<float>
    {
      static const unsigned short value = 0;
    };

    template<>
    struct x87_precision_flag<double>
    {
      static const unsigned short value = 2;
    };

    template<>
    struct x87_precision_flag<long double>
    {
      static const unsigned short value = 1;
    };

    BOOST_FORCEINLINE unsigned short x87_get_control_word()
    {
    #ifdef _MSC_VER
      return _control87(0, 0);
    #elif defined(__GNUC__)
      unsigned short cw;
      __asm__ __volatile__ ("fstcw %w0" : "=m" (cw));
      return cw;
    #else
      #error unsupported compiler to manage x87 floating-point control word
    #endif
    }

    BOOST_FORCEINLINE void x87_set_control_word(unsigned short cw)
    {
    #ifdef _MSC_VER
      _control87(cw, 0xFFFF);
    #elif defined(__GNUC__)
      __asm__ __volatile__ ("fldcw %0" : : "m" (cw));
    #else
      #error unsupported compiler to manage x87 floating-point control word
    #endif
    }
  }
  #endif

  template<class T, class Enable = void>
  struct enforce_precision
  {
    BOOST_FORCEINLINE enforce_precision()
    {
    }
  };

  #if defined(BOOST_SIMD_ARCH_X86) && !defined(BOOST_SIMD_ARCH_X86_64)
  template<class T>
  struct enforce_precision<T, typename boost::enable_if< boost::is_floating_point<T> >::type>
  {
    BOOST_FORCEINLINE enforce_precision() : cw(x86::x87_get_control_word())
    {
      unsigned short new_cw = (cw & 0xFCFF) | (x86::x87_precision_flag<T>::value << 8);
      x86::x87_set_control_word(new_cw);
    }

    BOOST_FORCEINLINE ~enforce_precision()
    {
      x86::x87_set_control_word(cw);
    }

    unsigned short cw;
  };
  #endif
} } }

#endif