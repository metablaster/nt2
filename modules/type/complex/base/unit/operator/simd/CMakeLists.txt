##############################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################

set( SOURCES
  unary_minus.cpp
  plus.cpp
  minus.cpp
  multiplies.cpp
  imag.cpp
  real.cpp
  i.cpp
  sqrti.cpp
  divides.cpp
  is_equal.cpp
  is_not_equal.cpp
  is_less_equal.cpp
  is_less.cpp
  is_greater_equal.cpp
  is_greater.cpp
  )

nt2_module_add_tests(type.complex.base.operator.simd.unit ${SOURCES})
