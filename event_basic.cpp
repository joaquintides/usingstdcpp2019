/* Copyright 2019 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See https://github.com/joaquintides/usingstdcpp2019 for talk material.
 */
 
#include <iostream>
#include <string>
#include "urp.hpp"

int main()
{
  using namespace usingstdcpp2019::urp;

  trigger<std::string> s;
  auto n=s|map([](const std::string& s){return s.size();});
  auto e=combine(s,n)
        |filter([](const auto& p){return std::get<1>(p)>=4;})
        |map([](const auto& p){return std::get<0>(p);})
        |accumulate(std::string{},std::plus<>{});
    
  e.connect([](const auto&,const std::string& str){
    std::cout<<str<<" ";
  });
  
  for(const auto& str:{"welcome","to","using","std","cpp","2019"}){
    s=str;
  }
}
