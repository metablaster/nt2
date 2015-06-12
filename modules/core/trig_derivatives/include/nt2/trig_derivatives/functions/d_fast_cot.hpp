//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TRIGONOMETRIC_FUNCTIONS_D_FAST_COT_HPP_INCLUDED
#define NT2_TRIGONOMETRIC_FUNCTIONS_D_FAST_COT_HPP_INCLUDED
#include <nt2/include/functor.hpp>


namespace nt2 { namespace tag
  {
   /*!
     @brief d_fast_cot generic tag

     Represents the d_fast_cot function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct d_fast_cot_ : ext::elementwise_<d_fast_cot_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<d_fast_cot_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_d_fast_cot_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
   template<class Site>
   BOOST_FORCEINLINE generic_dispatcher<tag::d_fast_cot_, Site> dispatching_d_fast_cot_(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
   {
     return generic_dispatcher<tag::d_fast_cot_, Site>();
   }
   template<class... Args>
   struct impl_d_fast_cot_;
  }
  /*!
    cotangent in the interval \f$[-\pi/4, \pi/4]\f$, nan outside.

    @par Semantic:

    For every parameter of floating type T0

    @code
    T0 r = d_fast_cot(x);
    @endcode

    is similar to:

    @code
    T0 r = cot(x);
    @endcode

    provided that x belongs to \f$[-\pi/4, \pi/4]\f$

    @see @funcref{cotangent}, @funcref{cot}, @funcref{cotd}, @funcref{cotpi}
    @param a0

    @return a value of the same type as the parameter
  **/
  NT2_FUNCTION_IMPLEMENTATION(tag::d_fast_cot_, d_fast_cot, 1)
}

#endif


