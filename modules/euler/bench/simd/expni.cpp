//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 euler toolbox - expni/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of euler components in simd mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/euler/include/expni.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <cmath>
typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;

//////////////////////////////////////////////////////////////////////////////
// simd runtime benchmark for functor<expni_> from euler
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::expni_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, (V1) ,(V2))

namespace n1 {
  typedef float T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<iT,ext_t> viT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(expni_,(RS(iT,iT(-10),iT(10)))(RS(vT,T(-10),T(10))))
}
namespace n2 {
  typedef double T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<iT,ext_t> viT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(expni_,(RS(iT,iT(-10),iT(10)))(RS(vT,T(-10),T(10))))
}

#undef RS
