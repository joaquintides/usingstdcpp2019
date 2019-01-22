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
    
  value x=0,y=0;
  auto  z=(x*x)+y+1;
  
  x=6;
  y=5;
  std::cout<<"z="<<z.get()<<"\n";
}
