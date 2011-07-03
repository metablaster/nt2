//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_ELLIPTIC_FUNCTION_SIMD_COMMON_ELLIPKE_HPP_INCLUDED
#define NT2_TOOLBOX_ELLIPTIC_FUNCTION_SIMD_COMMON_ELLIPKE_HPP_INCLUDED
#include <nt2/sdk/meta/as_real.hpp>
#include <boost/fusion/tuple.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/include/functions/ldexp.hpp>
#include <nt2/include/functions/sqrt.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/include/functions/average.hpp>
#include <nt2/include/functions/oneminus.hpp>
#include <nt2/include/functions/tofloat.hpp>
#include <nt2/include/functions/any.hpp>
#include <nt2/include/functions/maximum.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/infinites.hpp>
#include <nt2/include/constants/eps_related.hpp>
/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION(tag::ellipke_, tag::cpu_,
                       (A0)(X),
                       ((simd_<arithmetic_<A0>,X>))
                      )
  {
	typedef typename meta::as_real<A0>::type         etype;
	typedef boost::fusion::tuple<etype, etype> result_type;
      
    NT2_FUNCTOR_CALL(1)
    {
      typedef typename meta::scalar_of<etype>::type setype; 
      return ellipke(tofloat(a0), Eps<setype>()); 
    }
  };

  /////////////////////////////////////////////////////////////////////////////
  //Implementation when type A0 is arithmetic_
  /////////////////////////////////////////////////////////////////////////////
  NT2_FUNCTOR_IMPLEMENTATION(tag::ellipke_, tag::cpu_,
			     (A0)(A1)(X),
			     ((simd_<arithmetic_<A0>,X>))
			     ((scalar_<real_<A1> >))
			     )
  {
    typedef typename meta::as_real<A0>::type         etype;
    typedef boost::fusion::tuple<etype, etype> result_type;
    
    NT2_FUNCTOR_CALL(2)
      {
	return ellipke(tofloat(a0), a1); 
      }
  };
  
  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is arithmetic_
  /////////////////////////////////////////////////////////////////////////////
  NT2_FUNCTOR_IMPLEMENTATION(tag::ellipke_, tag::cpu_,
			     (A0)(A1)(X),
			     ((simd_<real_<A0>,X>))
			     ((scalar_<real_<A1> >))
			     )
  {
    typedef typename meta::strip<A0>::type              etype;
    typedef boost::fusion::tuple<etype, etype>    result_type;

    NT2_FUNCTOR_CALL(2)
      {
	result_type res;
	nt2::ellipke(a0, a1, boost::fusion::at_c<0>(res), boost::fusion::at_c<1>(res)); 
	return res; 
      }
  };

  /////////////////////////////////////////////////////////////////////////////
  // reference based Implementations 1 input
  /////////////////////////////////////////////////////////////////////////////
  NT2_FUNCTOR_IMPLEMENTATION(  tag::ellipke_, tag::cpu_,
			       (A0)(A1)(X), 
			       ((simd_<arithmetic_<A0>,X >))
			       ((simd_<real_<A1>,X>))
			       ((simd_<real_<A1>,X>))
			       )
  {
    typedef void result_type;    
    inline result_type operator()(A0 const& a0,A1 & a1,A1 & a2) const
      {
	typedef typename meta::scalar_of<A1>::type sA1; 
	nt2::ellipke(tofloat(a0), Eps<sA1>(), a1, a2); 
      }
  }; 
  
  /////////////////////////////////////////////////////////////////////////////
  // reference based Implementations 2 inputs
  /////////////////////////////////////////////////////////////////////////////
  NT2_FUNCTOR_IMPLEMENTATION_IF(tag::ellipke_, tag::cpu_,
				(A0)(A1)(A2)(X), 
				(boost::mpl::equal_to < meta::cardinal_of<A0> 
			                                , meta::cardinal_of<A2>
				                        >
				), 
                                ( tag::ellipke_
                                          ( simd_<arithmetic_<A0>,X> 
					  , scalar_<real_<A1> >
				          , simd_<real_<A2>,X>
				          , simd_<real_<A2>,X>
                                          )
                                ), 
				((simd_<arithmetic_<A0>,X >))
				((scalar_<real_<A1> >))
				((simd_<real_<A2>,X >))
				((simd_<real_<A2>,X >))
			     )
  {
    typedef void result_type;    
    inline result_type operator()(A0 const& a0,
				  A1 const& a1, A0 & a2,A0 & a3) const
      {
	nt2::ellipke(tofloat(a0),a1,a2,a3); 
      }
  };
  
  /////////////////////////////////////////////////////////////////////////////
  // reference based Implementations 2 inputs
  /////////////////////////////////////////////////////////////////////////////
  NT2_FUNCTOR_IMPLEMENTATION(  tag::ellipke_, tag::cpu_,
				(A0)(A1)(X), 
				((simd_<real_<A0>,X >))
				((scalar_<real_<A1> >))
				((simd_<real_<A0>,X >))
				((simd_<real_<A0>,X >))
				)
  {
    typedef void result_type;    
    inline result_type operator()(A0 const& a0,
				  A1 const& a1, A0 & a2,A0 & a3) const
      {
	typedef typename meta::as_integer<A0>::type iA0;
	typedef typename meta::scalar_of<A0>::type sA0;
	A0 nan =  b_or(is_ltz(a0), gt(a0, One<A0>()));
	A0 m = b_andnot(a0, nan); 
	A0 aa0 = One<A0>();
	A0 bb0 = sqrt(oneminus(m));
	A0 s0 = m;
	int32_t i1 = 0;
	sA0 mm = One<sA0>();
	A0 aa1; 
	while (gt(mm, a1))
	  {
	    aa1 = average(aa0, bb0);
	    A0 bb1 = sqrt(aa0*bb0);
	    A0 cc1 = average(aa0, -bb0);
	    ++i1; 
	    A0 w1 = ldexp(sqr(cc1), splat<iA0>(i1));
	    mm =  maximum(w1); 
	    s0 += w1;
	    aa0 = aa1;
	    bb0 = bb1;
	  };
	A0 iseqm1 = eq(m, One<A0>());
	a2 = b_or(nan, sel(iseqm1,Inf<A0>(), nt2::Pio_2<A0>()/aa1));
	a3 = b_or(nan, sel(iseqm1,One<A0>(), a2*(One<A0>()-s0*Half<A0>()))); 
      }
  };
  
} }
#endif
