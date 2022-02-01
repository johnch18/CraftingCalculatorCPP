//
// Created by johnch18 on 1/25/22.
// GPL License, don't be a dick
//

#include <cmath>
#include <sstream>
#include "Ingredient.h"


unsigned int Ingredient::get_amount() const
{
  return amount;
}

Component *Ingredient::get_component() const
{
  return component;
}

void Ingredient::add(unsigned num)
{
  amount += num;
}

void Ingredient::subtract(unsigned num)
{
  amount -= num;
}

void Ingredient::multiply(unsigned num)
{
  amount *= num;
}

void Ingredient::divide(unsigned num)
{
  amount = ceil(static_cast<double>(amount) / num);
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
