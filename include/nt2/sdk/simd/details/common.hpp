/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_SIMD_DETAILS_COMMON_HPP_INCLUDED
#define NT2_SDK_SIMD_DETAILS_COMMON_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// By default, any SIMD implementaiton falls down to scalar map application if
// nothing is implemented for doing otherwise.
////////////////////////////////////////////////////////////////////////////////
#include <nt2/extension/parameters.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/sdk/details/preprocessor.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>

namespace nt2 { namespace functors
{
  //////////////////////////////////////////////////////////////////////////////
  // When in SIMD, dispatch on the scalar of argument A0
  //////////////////////////////////////////////////////////////////////////////
  template<class Tag, class C,class X, class Info>
  struct dispatch<Tag,tag::simd_(C,X),Info>
  {
    template<class A0,class A1>
    struct  apply
          : meta::scalar_of<typename meta::strip<A0>::type>
    {};
  };

  //////////////////////////////////////////////////////////////////////////////
  // If no call<> exists, try to map it sequentially
  //////////////////////////////////////////////////////////////////////////////
  template<class Tag, class C, class X,class Info>
  struct call<Tag,tag::simd_(C,X),fundamental_,Info> : callable
  {
    template<class Sig> struct result;

    #define NT2_LOCAL(z,n,t)                                              \
    template<class This,BOOST_PP_ENUM_PARAMS(n,class A)>                  \
    struct  result<This(BOOST_PP_ENUM_PARAMS(n,A))>                       \
          : meta::strip<A0> {};                                           \
                                                                          \
    template<BOOST_PP_ENUM_PARAMS(n,class A)> inline A0                   \
    operator()( BOOST_PP_ENUM_BINARY_PARAMS(n,A,const& a) ) const         \
    {                                                                     \
      A0 that = map( functor<Tag,Info>(), BOOST_PP_ENUM_PARAMS(n,a) );    \
      return that;                                                        \
    }                                                                     \
    /**/

    BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(NT2_MAX_ARITY),NT2_LOCAL,~)

    #undef NT2_LOCAL
  };
} }

#endif
