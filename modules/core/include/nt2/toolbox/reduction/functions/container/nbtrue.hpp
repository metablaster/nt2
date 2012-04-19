//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_COMMON_NBTRUE_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_COMMON_NBTRUE_HPP_INCLUDED

#include <boost/simd/toolbox/reduction/functions/nbtrue.hpp>
#include <nt2/core/container/dsl/details/reduction.hpp>
#include <nt2/core/container/dsl/size.hpp>

namespace nt2 { namespace container { namespace ext
{
  template<class Domain, class Expr>
  struct size_of<boost::simd::tag::nbtrue_,Domain,1,Expr>
    : reduction_size_of<boost::simd::tag::nbtrue_, 1, Expr>{};

  template<class Domain, class Expr>
  struct size_of<boost::simd::tag::nbtrue_,Domain,2,Expr>
    : reduction_size_of<boost::simd::tag::nbtrue_, 2, Expr>{};

  template<class Domain, int N, class Expr>
  struct generator<boost::simd::tag::nbtrue_,Domain,N,Expr>
    : reduction_generator<boost::simd::tag::nbtrue_,N,Expr> {};
} } }

#endif
