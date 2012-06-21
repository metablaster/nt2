//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_SSE_SSE2_BITWISE_XOR_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_SSE_SSE2_BITWISE_XOR_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_SSE2_SUPPORT
#include <boost/simd/toolbox/operator/functions/bitwise_xor.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::bitwise_xor_, boost::simd::tag::sse2_
                            , (A0)(A1)
                            , ((simd_<arithmetic_<A0>,boost::simd::tag::sse_>))
                              ((simd_<arithmetic_<A1>,boost::simd::tag::sse_>))
                            )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      typedef typename dispatch::meta::as_integer<A0>::type int_type;
      return bitwise_cast<A0>( _mm_xor_si128 ( bitwise_cast<int_type>( a0 )
                                             , bitwise_cast<int_type>( a1 )
                                             )
                             );
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::bitwise_xor_, boost::simd::tag::sse2_
                            , (A0)(A1)
                            , ((simd_<double_<A0>,boost::simd::tag::sse_>))
                              ((simd_<double_<A1>,boost::simd::tag::sse_>))
                            )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      A0 that = _mm_xor_pd(a0,a1);
      return that;
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::bitwise_xor_, boost::simd::tag::sse2_
                            , (A0)(A1)
                            , ((simd_<single_<A0>,boost::simd::tag::sse_>))
                              ((simd_<single_<A1>,boost::simd::tag::sse_>))
                            )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      A0 that = _mm_xor_ps(a0,a1);
      return that;
    }
  };
} } }

#endif
#endif
