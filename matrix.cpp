/* Copyright 2019 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See https://github.com/joaquintides/usingstdcpp2019 for talk material.
 */
 
#include <array>
#include <iostream>
#include <tuple>
#include "urp.hpp"

int main()
{
  using namespace usingstdcpp2019::urp;

  using matrix2x2=std::array<std::array<value<double>,2>,2>;

  auto mult=[](auto& m,auto& n){
    auto& [m00,m01]=std::get<0>(m);
    auto& [m10,m11]=std::get<1>(m);
    auto& [n00,n01]=std::get<0>(n);
    auto& [n10,n11]=std::get<1>(n);
      
    return std::tuple{
      std::tuple{m00*n00+m01*n10,m00*n01+m01*n11},
      std::tuple{m10*n00+m11*n10,m10*n01+m11*n11}
    };
  };
  
  auto print=[](const auto& m){
    auto& [m00,m01]=std::get<0>(m);
    auto& [m10,m11]=std::get<1>(m);      
    std::cout<<
      "/ " <<m00.get()<<"\t"<<m01.get()<<"\n"<<
      "\\ "<<m10.get()<<"\t"<<m11.get()<<"\n";
  };

  matrix2x2 m={{ {  6.0, 14.0},
                 { 21.0, 28.0} }},
            n={{ {-12.0,  6.0},
                 {  9.0, -3.0} }};
  auto      p=mult(m,n);
  
  print(p);  
  m[0][0]=7.0;
  print(p);
}
