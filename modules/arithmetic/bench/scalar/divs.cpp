//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 arithmetic toolbox - divs/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of arithmetic components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/arithmetic/include/divs.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<divs_> from arithmetic
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::divs_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef int8_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(divs_,(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4)))(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4))))
}
namespace n2 {
  typedef int16_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(divs_,(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4)))(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4))))
}
namespace n3 {
  typedef int32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(divs_,(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4)))(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4))))
}
namespace n4 {
  typedef int64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(divs_,(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4)))(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4))))
}

#undef RS
