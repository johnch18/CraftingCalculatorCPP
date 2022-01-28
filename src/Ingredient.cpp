//
// Created by johnch18 on 1/25/22.
// GPL License, don't be a dick
//

#include <cmath>
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

Ingredient::Ingredient(Component *component, unsigned amount): component
(component), amount(amount)
{

}

bool Ingredient::isValid() const
{
  return component != nullptr && amount > 0;
}
