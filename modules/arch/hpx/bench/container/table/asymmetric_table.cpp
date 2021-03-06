//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================

#include <nt2/sdk/bench/benchmark.hpp>
#include <nt2/sdk/unit/details/prng.hpp>
#include <nt2/sdk/bench/metric/cycles_per_element.hpp>
#include <nt2/sdk/bench/metric/speedup.hpp>
#include <nt2/sdk/bench/setup/geometric.hpp>
#include <nt2/sdk/bench/setup/constant.hpp>
#include <nt2/sdk/bench/setup/combination.hpp>
#include <nt2/sdk/bench/protocol/max_duration.hpp>
#include <nt2/sdk/bench/stats/median.hpp>

#include <nt2/include/functions/cos.hpp>
#include <nt2/include/functions/sin.hpp>
#include <nt2/include/functions/sqrt.hpp>
#include <nt2/include/functions/numel.hpp>
#include <nt2/table.hpp>

#include <vector>
#include <cmath>

using nt2::table;
using nt2::of_size;
using namespace nt2::bench;

//==============================================================================
// std::vector based plus benchmark
//==============================================================================
template<typename T>
struct small_vector
{
  small_vector() {}

  small_vector ( std::size_t n )
              : size_(n), a0(n), a1(n), a2(n)
  {
    nt2::roll(a0,-3.1415/4., 3.1415/4.);
    nt2::roll(a1,-3.1415/4., 3.1415/4.);
  }

  void operator()()
  {
    for(std::size_t i = 0; i < size_; ++i)
    {
      a2[i]  = std::sqrt(std::cos(a0[i])/std::sin(a0[i]) + a1[i]*a1[i]/a0[i] );
    }
  }

  std::size_t size() const { return size_; }

  private:
  std::size_t size_;
  std::vector<T> a0,a1,a2;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, small_vector<T> const& p)
{
  return os << "(" << p.size() << ")";
}

NT2_REGISTER_BENCHMARK_TPL( small_vector, (float)(double) )
{
  std::size_t mn = args("min" , 2   );
  std::size_t mx = args("max" , 2048);
  std::size_t s  = args("step", 2   );
  run_during_with< small_vector<T> >( 1.
                                    , geometric(mn,mx,s)
                                    , cycles_per_element<stats::median_>()
                                    );
}

//==============================================================================
// nt2::table based plus benchmark
//==============================================================================
template<typename T>
struct small_table
{
  small_table() {}

  template<typename Args>
  small_table ( Args const& n )
              : a0( nt2::_2D( boost::fusion::at_c<0>(n)
                            , boost::fusion::at_c<1>(n)
                            )
                  )
              , a1( nt2::_2D( boost::fusion::at_c<0>(n)
                            , boost::fusion::at_c<1>(n)
                            )
                  )
              , a2( nt2::_2D( boost::fusion::at_c<0>(n)
                            , boost::fusion::at_c<1>(n)
                            )
                  )
  {
    nt2::roll(a0,-3.1415/4., 3.1415/4.);
    nt2::roll(a1,-3.1415/4., 3.1415/4.);
  }

  void operator()()
  {
    a2  = nt2::sqrt ( nt2::cos(a0)/nt2::sin(a0) + a1*a1/a0 );
  }

  std::size_t size()   const { return numel(a0); }
  nt2::_2D    extent() const { return a0.extent(); }

  private:
  nt2::table<T> a0,a1,a2;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, small_table<T> const& p)
{
  return os << "(" << p.extent() << ")";
}

NT2_REGISTER_BENCHMARK_TPL( small_table, (float)(double) )
{
  std::size_t mn = args("min" , 2   );
  std::size_t mx = args("max" , 2048);
  std::size_t s  = args("step", 2   );

  run_during_with< small_table<T> >( 1.
                                  , and_( constant(1)
                                        , geometric(mn,mx,s)
                                        )
                                  , cycles_per_element<stats::median_>()
                                  , speedup < small_vector<T>
                                            , cycles_per_element< stats::median_>
                                            >()
                                  );

  run_during_with< small_table<T> >( 1.
                                  , and_( geometric(mn,mx,s)
                                        , constant(1)
                                        )
                                  , cycles_per_element<stats::median_>()
                                  , speedup < small_vector<T>
                                            , cycles_per_element< stats::median_>
                                            >()
                                  );
}
