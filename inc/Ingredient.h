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
  Ingredient(std::string);
  Ingredient(std::string, unsigned);
  Ingredient(std::string, unsigned, double);
  Ingredient(Component *component);
  Ingredient(Component *component, unsigned amount);
  Ingredient(Component *component, unsigned amount, double chance);
  //
  double get_chance() const;
  Component *get_component() const;
  unsigned int get_amount() const;
  void add(unsigned);
  void subtract(unsigned);
  void multiply(unsigned);
  void divide(unsigned);
  bool isValid() const;
  std::string get_str();
};


#endif //CRAFTINGCALCULATORC___INGREDIENT_H
