//==============================================================================
//         Copyright 2015 J.T. Lapreste
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/derivation/include/functions/centered.hpp>

#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>
#include <nt2/sdk/unit/tests/ulp.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/sdk/config.hpp>

#include <nt2/include/functions/rec.hpp>
#include <nt2/include/constants/pi.hpp>
#include <nt2/include/constants/invpi.hpp>
#include <nt2/include/constants/sqrteps.hpp>
#include <nt2/table.hpp>

NT2_TEST_CASE_TPL ( centered, NT2_REAL_TYPES)
{
  using nt2::centered;
  using nt2::tag::centered_;
  auto f =  [](T t){return t*t;};
  T x =  T(nt2::Pi<T>());
  T r = T(2)*nt2::Pi<T>();
  T dfdx =  centered(f, x,  nt2::Derivinc<T>());
  NT2_TEST_ULP_EQUAL(dfdx, r,  nt2::rec(nt2::Sqrteps<T>()));

  dfdx =  centered(f, x,  nt2::Derivinc<T>(), nt2::pow2den_);
  NT2_TEST_ULP_EQUAL(dfdx, r, nt2::rec(nt2::Sqrteps<T>()));

  dfdx =  centered(f, x, nt2::pow2den_);
  NT2_TEST_ULP_EQUAL(dfdx, r, nt2::rec(nt2::Sqrteps<T>()));

  dfdx =  centered(f, x);
  NT2_TEST_ULP_EQUAL(dfdx, r, nt2::rec(nt2::Sqrteps<T>()));

  x = nt2::Invpi<T>();
  r = 2*x;
  dfdx =  centered(f, x,  nt2::Derivinc<T>());
  NT2_TEST_ULP_EQUAL(dfdx, r,  nt2::rec(nt2::Sqrteps<T>()));

  dfdx =  centered(f, x,  nt2::Derivinc<T>(), nt2::pow2den_);
  NT2_TEST_ULP_EQUAL(dfdx, r, nt2::rec(nt2::Sqrteps<T>()));

  dfdx =  centered(f, x, nt2::pow2den_);
  NT2_TEST_ULP_EQUAL(dfdx, r, nt2::rec(nt2::Sqrteps<T>()));

  dfdx =  centered(f, x);
  NT2_TEST_ULP_EQUAL(dfdx, r, nt2::rec(nt2::Sqrteps<T>()));
 }

NT2_TEST_CASE_TPL ( centeredrc, NT2_REAL_TYPES)
{
  using nt2::centered;
  using nt2::tag::centered_;
  typedef typename std::complex<T> cT;
  auto f =  [](T t)->cT{return cT(t*t, T(1));};
  T x =  T(nt2::Pi<T>());
  cT r = T(2)*nt2::Pi<T>();

  cT dfdx =  centered(f, x,  nt2::Derivinc<T>());
  NT2_TEST_ULP_EQUAL(dfdx, r,  nt2::rec(nt2::Sqrteps<T>()));

  dfdx =  centered(f, x,  nt2::Derivinc<T>(), nt2::pow2den_);
  NT2_TEST_ULP_EQUAL(dfdx, r, nt2::rec(nt2::Sqrteps<T>()));

  dfdx =  centered(f, x, nt2::pow2den_);
  NT2_TEST_ULP_EQUAL(dfdx, r, nt2::rec(nt2::Sqrteps<T>()));

  dfdx =  centered(f, x);
  NT2_TEST_ULP_EQUAL(dfdx, r, nt2::rec(nt2::Sqrteps<T>()));

  x = nt2::Invpi<T>();
  r = T(2)*x;
  dfdx =  centered(f, x,  nt2::Derivinc<T>());
  NT2_TEST_ULP_EQUAL(dfdx, r,  nt2::rec(nt2::Sqrteps<T>()));

  dfdx =  centered(f, x,  nt2::Derivinc<T>(), nt2::pow2den_);
  NT2_TEST_ULP_EQUAL(dfdx, r, nt2::rec(nt2::Sqrteps<T>()));

  dfdx =  centered(f, x, nt2::pow2den_);
  NT2_TEST_ULP_EQUAL(dfdx, r, nt2::rec(nt2::Sqrteps<T>()));

  dfdx =  centered(f, x);
  NT2_TEST_ULP_EQUAL(dfdx, r, nt2::rec(nt2::Sqrteps<T>()));
 }