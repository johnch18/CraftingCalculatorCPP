//
// Created by johnch18 on 2/17/22.
// GPL License, don't be a dick
//

#ifndef CRAFTINGCALCULATOR_RECIPE_H
#define CRAFTINGCALCULATOR_RECIPE_H


#include "IngredientList.h"


class IngredientList;


class Recipe
{
  /*
   * Stores a map of inputs to outputs
   * */
private:
  // Inputs and outputs
  IngredientList *inputs,
                 *outputs;
  // Whether the recipe should be checked
  bool           isEnabled = true;
public:
  // Constructors
  Recipe();
  Recipe(std::initializer_list<IIngredient>, std::initializer_list<IIngredient>);
};


#endif //CRAFTINGCALCULATOR_RECIPE_H
