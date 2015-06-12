//==============================================================================
//          Copyright 2015 J.T. Lapreste
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TRIG_DERIVATIVES_FUNCTIONS_GENERIC_D_FAST_SIN_HPP_INCLUDED
#define NT2_TRIG_DERIVATIVES_FUNCTIONS_GENERIC_D_FAST_SIN_HPP_INCLUDED
#include <nt2/trig_derivatives/functions/d_fast_sin.hpp>
#include <nt2/include/functions/simd/fast_cos.hpp>
namespace nt2 { namespace ext
{

  BOOST_DISPATCH_IMPLEMENT  ( d_fast_sin_, tag::cpu_
                            , (A0)
                            , (generic_<floating_<A0>>)
                            )
  {
    typedef A0 result_type;
    BOOST_FORCEINLINE result_type operator()(const A0& u) const
    {
      return fast_cos(u);
    }
  };
} }


#endif
