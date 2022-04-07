//
// Created by johnch18 on 2/17/22.
// GPL License, don't be a dick
//

#ifndef CRAFTINGCALCULATOR_IINGREDIENT_H
#define CRAFTINGCALCULATOR_IINGREDIENT_H


#include "Component.h"

class Component;


class IIngredient
{
  /*
   * Interface to manage ingredients, which are essentially equivalent to ItemStacks
   * */
private:
  // How much, either items or liters
  unsigned amount;
  // Whether the ingredient is active
  bool     isEnabled = true;
  // The odds of the ingredient being produced
  double   chance    = 1.0;
public:
  // Rule of 0
  /*IIngredient() = 0;
  virtual ~IIngredient() = 0;
  IIngredient(const IIngredient &) = 0;
  IIngredient &operator=(const IIngredient &) = 0;
  IIngredient &operator=(IIngredient &&) = 0;*/
  // Getter for component, will be different depending on the ingredient type
  virtual Component *get_component() = 0;
  virtual void combine_with(IIngredient *other) = 0;
};


#endif //CRAFTINGCALCULATOR_IINGREDIENT_H
