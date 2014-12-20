//==============================================================================
//         Copyright 2013 - 2014   Jean-Thierry Lapreste
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_BLAS_FUNCTIONS_BLAS_SCAL_HPP_INCLUDED
#define NT2_BLAS_FUNCTIONS_BLAS_SCAL_HPP_INCLUDED

/*!
  @file
  @brief Defines and implements scal function
**/

#include <nt2/include/functor.hpp>

namespace nt2 { namespace blas
{
  namespace tag
  {
    /// @brief Defines scal function tag
    struct scal_ : ext::abstract_<scal_>
    {
      /// INTERNAL ONLY
      typedef ext::abstract_<scal_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_scal_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
    template<class Site>
    BOOST_FORCEINLINE generic_dispatcher<tag::scal_, Site> dispatching_scal_(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
    {
      return generic_dispatcher<tag::scal_, Site>();
    }
    template<class... Args>
    struct impl_scal_;
  }

  /*!
    @brief scale  by alpha values of vector x

    @code
    copy ( n, alpha, x, incx)
    @endcode

    @param n number of elements to scale
    @param alpha scaling factor
    @param x  L-value to receive the vector to be scaled
    @param incx step through x

  **/
  NT2_FUNCTION_IMPLEMENTATION_TPL (tag::scal_, scal
                                  , (const A0&)(const A1&)(A2&)(const A3&)
                                  , 4
                                  );

 } }

#endif

