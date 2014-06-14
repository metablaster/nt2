//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_LINALG_FUNCTIONS_SCALAR_MNORM_HPP_INCLUDED
#define NT2_LINALG_FUNCTIONS_SCALAR_MNORM_HPP_INCLUDED
#include <nt2/linalg/functions/mnorm.hpp>
#include <nt2/include/functions/ismatrix.hpp>
#include <nt2/include/functions/isvector.hpp>
#include <nt2/include/functions/svd.hpp>
#include <nt2/include/functions/globalnorm2.hpp>
#include <nt2/core/container/dsl/forward.hpp>
#include <boost/assert.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/bool.hpp>
#include <nt2/core/functions/table/details/is_definitely_vector.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::mnorm_, tag::cpu_,
                              (A0),
                              ((ast_<A0, nt2::container::domain>))
                            )
  {
    typedef typename A0::value_type                   type_t;
    typedef typename meta::as_real<type_t>::type result_type;

    BOOST_FORCEINLINE result_type operator()(A0 const& a0) const
    {
      BOOST_ASSERT_MSG(nt2::ismatrix(a0), "a0 is not a matrix");
      typedef typename details::is_vector<typename A0::extent_type>::type choice_t;
      return eval(a0, choice_t());
    }

    BOOST_FORCEINLINE type_t
    eval(A0 const& a0, boost::mpl::true_ const &) const
    {
      return globalnorm2(a0);
    }

    BOOST_FORCEINLINE type_t
    eval(A0 const& a0, boost::mpl::false_ const &) const
    {
      return svd(a0)(1);
    }

    BOOST_FORCEINLINE type_t
      eval(A0 const& a0, nt2::meta::indeterminate_ const &) const
    {
      if (isvector(a0))
      {
        return globalnorm2(a0);
      }
      else
      {
        return svd(a0)(1);
      }
    }


  };
} }

#endif
