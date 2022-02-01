//
// Created by johnch18 on 1/25/22.
// GPL License, don't be a dick
//

#ifndef CRAFTINGCALCULATORC___INGREDIENT_H
#define CRAFTINGCALCULATORC___INGREDIENT_H


#include "Component.h"


class Component;


class Ingredient
{
private:
  Component *component;
  unsigned  amount;
  double    chance;
public:
  double get_chance() const;
  Component *get_component() const;
  unsigned int get_amount() const;
  void add(unsigned);
  void subtract(unsigned);
  void multiply(unsigned);
  void divide(unsigned);
  Ingredient(Component *component, unsigned amount);
  Ingredient(Component *component, unsigned amount, double chance);
  bool isValid() const;
  std::string get_str();
};


#endif //CRAFTINGCALCULATORC___INGREDIENT_H
