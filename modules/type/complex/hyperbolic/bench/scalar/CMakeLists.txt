##############################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################

SET( SOURCES
  acosh.cpp
  acoth.cpp
  acsch.cpp
  asech.cpp
  asinh.cpp
  atanh.cpp
  cosh.cpp
  coth.cpp
  csch.cpp
  sech.cpp
#  sinhc.cpp
  sinhcosh.cpp
  sinh.cpp
  tanh.cpp
  # List of scalar test files for toolbox exponential
  )

nt2_module_add_tests(type.complex.hyperbolic.scalar.bench ${SOURCES})
