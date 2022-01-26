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
};


#endif //CRAFTINGCALCULATORC___RECIPE_H
