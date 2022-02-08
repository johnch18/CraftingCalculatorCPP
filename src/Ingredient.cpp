//
// Created by johnch18 on 1/25/22.
// GPL License, don't be a dick
//

#include <cmath>
#include <sstream>
#include <iostream>
#include "Ingredient.h"


unsigned int Ingredient::get_amount() const
{
  return amount;
}

Component *Ingredient::get_component() const
{
  return component;
}

Ingredient Ingredient::add(unsigned num) const
{
  return Ingredient{get_component(), amount + num};
}

Ingredient Ingredient::subtract(unsigned num) const
{
  return Ingredient{get_component(), amount - num};
}

Ingredient Ingredient::multiply(unsigned num) const
{
  return Ingredient{get_component(), amount * num};
}

Ingredient Ingredient::divide(unsigned num) const
{
  return Ingredient{get_component(),
                    static_cast<unsigned>(ceil(static_cast<double>(amount) /
                                               num))};
}

Ingredient::Ingredient(Component *component, unsigned amount)
  : Ingredient(component, amount, 1.0)
{

}

bool Ingredient::isValid() const
{
  return component != nullptr && amount > 0;
}

Ingredient::Ingredient(Component *component, unsigned int amount,
                       double chance)
  : component(component),
    amount(amount),
    chance(chance)
{

}

double Ingredient::get_chance() const
{
  return chance;
}

std::string Ingredient::get_str()
{
  std::stringstream stream;
  stream << component->get_name() << ":" << amount;
  return stream.str();
}

Ingredient::Ingredient(std::string name, unsigned amount)
  : Ingredient(name,
               amount,
               1.0)
{

}

Ingredient::Ingredient(std::string name, unsigned amount, double chance)
  : Ingredient(Component::get_component(name), amount, chance)
{

}

Ingredient::Ingredient(std::string name)
  : Ingredient(name, 1, 1.0)
{
  if (name.find(':') != std::string::npos)
  {
    init_from_string(name);
  }
}

Ingredient::Ingredient(Component *component)
  : Ingredient(component, 1, 1.0)
{

}

void Ingredient::init_from_string(std::string name)
{
  std::stringstream        stream(name);
  std::vector<std::string> tokens;
  std::string              temp;
  // Split string
  while (std::getline(stream, temp, ':'))
  {
    tokens.push_back(temp);
  }
  //
  std::string iName = tokens.at(0);
  unsigned    iAmt;
  double      iChn;
  // Get chance
  if (tokens.size() < 3)
  {
    iChn = 1.0;
  }
  else
  {
    iChn = std::stod(tokens.at(2));
  }
  // Get amount
  if (tokens.size() < 2)
  {
    iAmt = 1;
  }
  else
  {
    iAmt = std::stoi(tokens.at(1));
  }
  //
  this->component = Component::get_component(iName);
  this->amount    = iAmt;
  this->chance    = iChn;
}

bool Ingredient::is_same_as(Ingredient &other)
{
  return component == other.component;
}

void Ingredient::add_in_place(unsigned value)
{
  amount += value;
}

void Ingredient::sub_in_place(unsigned value)
{
  amount -= value;
}

void Ingredient::multiply_in_place(unsigned value)
{
  amount *= value;
}

void Ingredient::divide_in_place(unsigned value)
{
  amount /= value;
}
