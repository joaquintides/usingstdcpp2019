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
    
  value x=0;
    
  auto f=[](int x){return x+1;};
  auto g=[](int x){return 2*x;};
  auto h=[](int x){return x*(x+1);};
    
  auto  y=x|f;
  auto  w=y|g;
  auto  z=w|h;

  auto  y1=function{f,x};
  auto  w1=function{g,y1};
  auto  z1=function{h,w1};

  auto  z2=x|f|g|h;
    
  auto  z3=function{h,function{g,function{f,x}}};

  x=2;
  std::cout<<"z ="<<z.get() <<"\n"
           <<"z1="<<z1.get()<<"\n"
           <<"z2="<<z2.get()<<"\n"
           <<"z3="<<z3.get()<<"\n";
}
