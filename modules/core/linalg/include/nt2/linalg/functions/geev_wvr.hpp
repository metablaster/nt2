//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_LINALG_FUNCTIONS_GEEV_WVR_HPP_INCLUDED
#define NT2_LINALG_FUNCTIONS_GEEV_WVR_HPP_INCLUDED

/*!
  @file
  @brief Defines and implements geev_wvr function
**/

#include <nt2/include/functor.hpp>

namespace nt2
{
  namespace tag
  {
    /// @brief Defines geev_wvr function tag
    struct geev_wvr_ : ext::abstract_<geev_wvr_>
    {
      /// INTERNAL ONLY
      typedef ext::abstract_<geev_wvr_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_geev_wvr_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
    template<class Site>
    BOOST_FORCEINLINE generic_dispatcher<tag::geev_wvr_, Site> dispatching_geev_wvr_(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
    {
      return generic_dispatcher<tag::geev_wvr_, Site>();
    }
    template<class... Args>
    struct impl_geev_wvr_;
  }

  /*!
    @brief piece of interface to lapack 's/d/c/zgeev' routines used by eig

    @param
    @param

    @return
  **/
  NT2_FUNCTION_IMPLEMENTATION_TPL (tag::geev_wvr_, geev_wvr
                                  , (A0&)(A1&)(A2&)
                                  , 3
                                  );

  NT2_FUNCTION_IMPLEMENTATION_TPL (tag::geev_wvr_, geev_wvr
                                  , (A0&)(A1&)(A2&)(A3&)
                                  , 4
                                  );
}

#endif

