//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TRIGONOMETRIC_FUNCTIONS_D_FAST_TAND_HPP_INCLUDED
#define NT2_TRIGONOMETRIC_FUNCTIONS_D_FAST_TAND_HPP_INCLUDED
#include <nt2/include/functor.hpp>


namespace nt2 { namespace tag
  {
   /*!
     @brief d_fast_tand generic tag

     Represents the d_fast_tand function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct d_fast_tand_ : ext::elementwise_<d_fast_tand_>
    {
      /// @brief Parent hierarchy
       typedef ext::elementwise_<d_fast_tand_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_d_fast_tand_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
   template<class Site>
   BOOST_FORCEINLINE generic_dispatcher<tag::d_fast_tand_, Site> dispatching_d_fast_tand_(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
   {
     return generic_dispatcher<tag::d_fast_tand_, Site>();
   }
   template<class... Args>
   struct impl_d_fast_tand_;
  }
  /*!
    tangent of the angle in degree, in the interval \f$[-45, 45]\f$, nan outside.

    @par Semantic:

    For every parameter of floating type T0

    @code
    T0 r = d_fast_tand(x);
    @endcode

    is similar to:

    @code
    T0 r = tand(x);
    @endcode

    @see  @funcref{tand}, @funcref{tan}
    @param a0

    @return a value of the same type as the parameter
  **/
  NT2_FUNCTION_IMPLEMENTATION(tag::d_fast_tand_, d_fast_tand, 1)
}

#endif


