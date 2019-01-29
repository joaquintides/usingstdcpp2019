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
  auto res=hold(
    s|group_by([](const std::string& str){return str.c_str()[0];})
     |map([](auto e){
       return hold(std::move(e)|collect());
     })
     |collect()
  );
    
  auto names={
    "John","Jack","Susan","Mary","Anne","Anthony","Bjarne","Margaret",
    "George","Barack","Sarah","Peter","Hillary","Ronda","Alice","Herbert",
  };
  for(const auto& str:names)s=str;

  for(const auto& e:res.get()){
    for(const auto& str:e.get())std::cout<<str<<" ";
    std::cout<<"\n";
  }
}
