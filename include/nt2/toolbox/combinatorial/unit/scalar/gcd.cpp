//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 combinatorial toolbox - gcd/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of combinatorial components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 30/11/2010
/// modified by jt the 15/02/2011
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/toolbox/combinatorial/include/gcd.hpp>

NT2_TEST_CASE_TPL ( gcd_real__2,  NT2_REAL_TYPES)
{
  using nt2::gcd;
  using nt2::tag::gcd_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<gcd_(T,T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename std::tr1::result_of<nt2::meta::arithmetic(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(  gcd(120,80), 40, 0);
  NT2_TEST_ULP_EQUAL(  gcd(3,15), 3, 0);
  NT2_TEST_ULP_EQUAL(  gcd(3,5), 1, 0);
  NT2_TEST_ULP_EQUAL(  gcd(6,15), 3, 0);
  NT2_TEST_ULP_EQUAL(  gcd(nt2::Inf<T>(), nt2::Inf<T>()), nt2::Nan<T>(), 0);
  NT2_TEST_ULP_EQUAL(  gcd(nt2::Minf<T>(), nt2::Minf<T>()), nt2::Nan<T>(), 0);
  NT2_TEST_ULP_EQUAL(  gcd(nt2::Mone<T>(), nt2::Mone<T>()), nt2::Mone<T>(), 0);
  NT2_TEST_ULP_EQUAL(  gcd(nt2::Nan<T>(), nt2::Nan<T>()), nt2::Nan<T>(), 0);
  NT2_TEST_ULP_EQUAL(  gcd(nt2::One<T>(), nt2::One<T>()), nt2::One<T>(), 0);
  NT2_TEST_ULP_EQUAL(  gcd(nt2::Zero<T>(), nt2::Zero<T>()), nt2::Zero<T>(), 0);
} // end of test for real_

NT2_TEST_CASE_TPL ( gcd_unsigned_int__2,  NT2_UNSIGNED_TYPES)
{
  using nt2::gcd;
  using nt2::tag::gcd_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<gcd_(T,T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename std::tr1::result_of<nt2::meta::arithmetic(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(  gcd(nt2::One<T>(), nt2::One<T>()), nt2::One<T>(), 0);
  NT2_TEST_ULP_EQUAL(  gcd(nt2::Zero<T>(), nt2::Zero<T>()), nt2::Zero<T>(), 0);
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( gcd_signed_int__2,  NT2_INTEGRAL_SIGNED_TYPES)
{
  using nt2::gcd;
  using nt2::tag::gcd_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<gcd_(T,T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename std::tr1::result_of<nt2::meta::arithmetic(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(  gcd(nt2::Mone<T>(), nt2::Mone<T>()), nt2::Mone<T>(), 0);
  NT2_TEST_ULP_EQUAL(  gcd(nt2::One<T>(), nt2::One<T>()), nt2::One<T>(), 0);
  NT2_TEST_ULP_EQUAL(  gcd(nt2::Zero<T>(), nt2::Zero<T>()), nt2::Zero<T>(), 0);
} // end of test for signed_int_