//
// Created by johnch18 on 1/25/22.
// GPL License, don't be a dick
//

#ifndef CRAFTINGCALCULATORC___RECIPE_H
#define CRAFTINGCALCULATORC___RECIPE_H


#include <vector>
#include "Ingredient.h"

class Ingredient;

class Recipe
{
private:
  std::vector<Ingredient> inputs, outputs;
public:
  void add_input(Ingredient ingredient);
  void add_output(Ingredient ingredient);
};


#endif //CRAFTINGCALCULATORC___RECIPE_H
