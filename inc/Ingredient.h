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
  bool      enabled = true;
  void init_from_string(std::string);
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
  Ingredient add(unsigned) const;
  Ingredient subtract(unsigned) const;
  Ingredient multiply(unsigned) const;
  Ingredient divide(unsigned) const;
  void add_in_place(unsigned);
  void sub_in_place(unsigned);
  void multiply_in_place(unsigned);
  void divide_in_place(unsigned);
  bool isValid() const;
  std::string get_str();
  bool is_same_as(Ingredient &);
};


#endif //CRAFTINGCALCULATORC___INGREDIENT_H
