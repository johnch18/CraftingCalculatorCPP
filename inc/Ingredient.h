//
// Created by johnch18 on 2/17/22.
// GPL License, don't be a dick
//

#ifndef CRAFTINGCALCULATOR_INGREDIENT_H
#define CRAFTINGCALCULATOR_INGREDIENT_H


#include "IIngredient.h"


class Ingredient : public IIngredient
{
  /*
   * Straightforward, just points to a component
   * */
private:
  // Component
  Component *component;
public:
  // Add RAII methods back
  Ingredient();
  ~Ingredient() override;
  // Getter for component, simply returns it
  Component *get_component() override;
};


#endif //CRAFTINGCALCULATOR_INGREDIENT_H
