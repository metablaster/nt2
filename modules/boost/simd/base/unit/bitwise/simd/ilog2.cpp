//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.ieee toolbox - ilog2/simd Mode"

#include <boost/simd/bitwise/include/functions/ilog2.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/include/functions/ilogb.hpp>
#include <boost/simd/include/functions/abs.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/constant/constant.hpp>

NT2_TEST_CASE_TPL ( ilog2_real__1_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::ilog2;
  using boost::simd::tag::ilog2_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<ilog2_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(ilog2(boost::simd::Minf<vT>())[0], boost::simd::Zero<sr_t>());
  NT2_TEST_EQUAL(ilog2(boost::simd::Mone<vT>())[0], boost::simd::Zero<sr_t>());
  NT2_TEST_EQUAL(ilog2(boost::simd::One<vT>())[0], boost::simd::Zero<sr_t>());
  NT2_TEST_EQUAL(ilog2(boost::simd::Zero<vT>())[0], boost::simd::Zero<sr_t>());
} // end of test for floating_

NT2_TEST_CASE_TPL ( ilog2_ints__1_0,  BOOST_SIMD_SIMD_TYPES)
{
  using boost::simd::ilog2;
  using boost::simd::tag::ilog2_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<ilog2_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(ilog2(boost::simd::One<vT>())[0], boost::simd::Zero<sr_t>());
  NT2_TEST_EQUAL(ilog2(boost::simd::Two<vT>())[0], boost::simd::One<sr_t>());
  for (T i =  2;  i < boost::simd::Valmax<T>()/2; i*= 2)
    {
      NT2_TEST_EQUAL(ilog2(boost::simd::splat<vT>(i))[0], ilog2(i));
      NT2_TEST_EQUAL(ilog2(boost::simd::splat<vT>(i+1))[0], ilog2(i));
    }
} // end of test for floating_
