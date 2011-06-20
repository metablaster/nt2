//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_CRLIBM_FUNCTION_SCALAR_LOG10_HPP_INCLUDED
#define NT2_TOOLBOX_CRLIBM_FUNCTION_SCALAR_LOG10_HPP_INCLUDED
#include <nt2/sdk/meta/upgrade.hpp>

  extern "C"{
    extern double log10_rn ( double );
    extern double log10_rd ( double );
    extern double log10_rz ( double );
    extern double log10_ru ( double );
  };


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(crlibm::tag::log10_<Rounding>, tag::cpu_,
                       (A0)(Rounding),
                       (arithmetic_<A0>)
                      )

namespace nt2 { namespace ext
{
  template<class Rounding,class Dummy>
  struct call<crlibm::tag::log10_<Rounding>(tag::arithmetic_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> :
      meta::result_of<meta::floating(A0)>{};

     template<class A0, class R> struct inner_log;
    NT2_CRLIBM_INNER_STRUCT(rn, log, rn)
    NT2_CRLIBM_INNER_STRUCT(rd, log, rd)
    NT2_CRLIBM_INNER_STRUCT(ru, log, ru)
    NT2_CRLIBM_INNER_STRUCT(rz, log, rd)
    NT2_FUNCTOR_CALL(1)
    {
      typedef typename NT2_RETURN_TYPE(1)::type   base;
      typedef typename meta::upgrade<base>::type  type;
      return nt2::crlibm::log10<Rounding>(type(a0));
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(crlibm::tag::log10_<Rounding>, tag::cpu_,
                       (A0)(Rounding),
                       (double_<A0>)
                      )

namespace nt2 { namespace ext
{
  template<class Rounding,class Dummy>
  struct call<crlibm::tag::log10_<Rounding>(tag::double_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> :
      meta::result_of<meta::floating(A0)>{};

    template<class A0, class R> struct inner_log10;
    NT2_CRLIBM_INNER_STRUCT(rn, log10, rn)
    NT2_CRLIBM_INNER_STRUCT(rd, log10, rd)
    NT2_CRLIBM_INNER_STRUCT(ru, log10, ru)
    NT2_CRLIBM_INNER_STRUCT(rz, log10, rd)

    NT2_FUNCTOR_CALL(1)
      {return inner_log10<A0,Rounding>::eval(a0, Rounding()); }
  };
} }

#endif
