//==============================================================================
//     Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//     Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//      Distributed under the Boost Software License, Version 1.0.
//         See accompanying file LICENSE.txt or copy at
//             http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TOOLBOX_CONSTANT_CONSTANT_HPP_INCLUDED
#define NT2_TOOLBOX_CONSTANT_CONSTANT_HPP_INCLUDED

#include <boost/simd/toolbox/constant/constant.hpp>

namespace nt2
{
  namespace tag
  {
    using boost::simd::tag::digit_;
    using boost::simd::tag::eps__;
    using boost::simd::tag::half_eps__;
    using boost::simd::tag::_3_x_eps_;
    using boost::simd::tag::sqrt_eps_;
    using boost::simd::tag::forth_root_eps_;
    using boost::simd::tag::third_root_eps_;
    using boost::simd::tag::mlog_eps_2_;
    using boost::simd::tag::min_denormal_;
    using boost::simd::tag::smallest_pos_val_;
    using boost::simd::tag::false_;
    using boost::simd::tag::ldexp_mask_;
    using boost::simd::tag::nb_mantissa_bits_;
    using boost::simd::tag::max_exponent_;
    using boost::simd::tag::nb_digits_;
    using boost::simd::tag::nb_exponent_bits_;
    using boost::simd::tag::min_exponent_;
    using boost::simd::tag::inf_;
    using boost::simd::tag::m_inf_;
    using boost::simd::tag::nan_;
    using boost::simd::tag::max_left_shift_;
    using boost::simd::tag::pi_;
    using boost::simd::tag::sqrt_2_o_2_;
    using boost::simd::tag::sqrt_2_;
    using boost::simd::tag::gold_;
    using boost::simd::tag::c_gold_;
    using boost::simd::tag::m_half_;
    using boost::simd::tag::m_zero_;
    using boost::simd::tag::half_;
    using boost::simd::tag::third_;
    using boost::simd::tag::quarter_;
    using boost::simd::tag::two_to_m10_;
    using boost::simd::tag::two_to_nmb_;
    using boost::simd::tag::split_factor_;
    using boost::simd::tag::signmask_;
    using boost::simd::tag::true_;
    using boost::simd::tag::val_max_;
    using boost::simd::tag::val_min_;
  }
    
  using boost::simd::Mten;
  using boost::simd::Mnine;
  using boost::simd::Meight;
  using boost::simd::Mseven;
  using boost::simd::Msix;
  using boost::simd::Mfive;
  using boost::simd::Mfour;
  using boost::simd::Mthree;
  using boost::simd::Mtwo;
  using boost::simd::Mone;
  using boost::simd::Zero;
  using boost::simd::One;
  using boost::simd::Two;
  using boost::simd::Three;
  using boost::simd::Four;
  using boost::simd::Five;
  using boost::simd::Six;
  using boost::simd::Seven;
  using boost::simd::Eight;
  using boost::simd::Nine;
  using boost::simd::Ten;
  using boost::simd::Twenty;
  using boost::simd::Hundred;
  using boost::simd::Thousand;
  using boost::simd::Fortyfive;
  using boost::simd::Ninety;
  using boost::simd::Onehundredeighty;
  using boost::simd::C_180;
  using boost::simd::_45;
  using boost::simd::_90;
  using boost::simd::_180;
  using boost::simd::integral_constant;
  
  using boost::simd::Eps;
  using boost::simd::Halfeps;
  using boost::simd::Threeeps;
  using boost::simd::Sqrteps;
  using boost::simd::Fourthrooteps;
  using boost::simd::Thirdrooteps;
  using boost::simd::Mlogeps2;
  using boost::simd::Mindenormal;
  using boost::simd::Smallestposval;
  
  using boost::simd::False;
  
  using boost::simd::Ldexpmask;
  using boost::simd::Nbmantissabits;
  using boost::simd::Nbexponentbits;
  using boost::simd::Maxexponent;
  using boost::simd::Minexponent;
  using boost::simd::Nbdigits;
  
  using boost::simd::Inf;
  using boost::simd::Minf;
  using boost::simd::Nan;
  
  using boost::simd::Maxleftshift;
  
  using boost::simd::Mhalf;
  using boost::simd::Mzero;
  using boost::simd::Half;
  using boost::simd::Third;
  using boost::simd::Quarter;
  using boost::simd::Twotom10;
  using boost::simd::Two2nmb;
  using boost::simd::Pi;
  using boost::simd::Splitfactor;
  using boost::simd::Sqrt_2o_2;
  using boost::simd::Sqrt_2;
  using boost::simd::Gold;
  using boost::simd::Cgold;
  
  using boost::simd::real_constant;
  using boost::simd::single_constant;
  using boost::simd::double_constant;
  using boost::simd::Const;
  
  using boost::simd::Signmask;
  
  using boost::simd::True;
  
  using boost::simd::Valmin;
  using boost::simd::Valmax;
  
}

#endif
