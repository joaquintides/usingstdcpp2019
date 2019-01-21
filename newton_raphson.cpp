/* Copyright 2019 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See https://github.com/joaquintides/usingstdcpp2019 for talk material.
 */
 
#include <iostream>
#include "urp.hpp"

int main()
{
  using namespace usingstdcpp2019::urp;
    
  value x=1.0;
  auto  y=x/2+882/x;
  
  // create a cycle
  y.connect([&](const auto& y){x=y.get();});

  x=10.0; // should segfault, right?
  std::cout<<"y="<<y.get()<<"\n";
}
