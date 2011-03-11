//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 exponential toolbox - log1p/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of exponential components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 08/12/2010
/// modified by jt the 23/02/2011
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/toolbox/exponential/include/log1p.hpp>
// specific includes for arity 1 tests
#include <nt2/include/functions/expm1.hpp>
#include <nt2/include/functions/sqrt1pm1.hpp>
extern "C" { long double cephes_log1pl(long double); }

NT2_TEST_CASE_TPL ( log1p_real__1,  NT2_REAL_TYPES)
{
  using nt2::log1p;
  using nt2::tag::log1p_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<log1p_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename std::tr1::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(log1p(nt2::Inf<T>()), nt2::Inf<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(log1p(nt2::Minf<T>()), nt2::Nan<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(log1p(nt2::Mone<T>()), nt2::Minf<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(log1p(nt2::Nan<T>()), nt2::Nan<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(log1p(nt2::One<T>()), nt2::Log_2<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(log1p(nt2::Zero<T>()), nt2::Zero<r_t>(), 0);
  // random verifications
  static const uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(0.1), T(10));
    double ulp0 = 0.0, ulpd = 0.0;
    T a0;
    for (int j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::log1p(a0),::cephes_log1pl(a0),0.5);
        ulp0=nt2::max(ulpd,ulp0);
        NT2_TEST_ULP_EQUAL( nt2::log1p(nt2::expm1(a0)),a0,1.5);
        ulp0=nt2::max(ulpd,ulp0);
        NT2_TEST_ULP_EQUAL( nt2::log1p(nt2::sqrt1pm1(a0)),nt2::Half<T>()*nt2::log1p(a0),1.5);
        ulp0=nt2::max(ulpd,ulp0);
     }
     std::cout << "max ulp found is: " << ulp0 << std::endl;
   }
} // end of test for real_

NT2_TEST_CASE_TPL ( log1p_unsigned_int__1,  NT2_UNSIGNED_TYPES)
{
  using nt2::log1p;
  using nt2::tag::log1p_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<log1p_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename std::tr1::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(log1p(nt2::One<T>()), nt2::Log_2<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(log1p(nt2::Zero<T>()), nt2::Zero<r_t>(), 0);
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( log1p_signed_int__1,  NT2_INTEGRAL_SIGNED_TYPES)
{
  using nt2::log1p;
  using nt2::tag::log1p_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<log1p_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename std::tr1::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(log1p(nt2::Mone<T>()), nt2::Minf<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(log1p(nt2::One<T>()), nt2::Log_2<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(log1p(nt2::Zero<T>()), nt2::Zero<r_t>(), 0);
} // end of test for signed_int_