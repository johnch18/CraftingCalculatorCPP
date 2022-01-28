//
// Created by johnch18 on 1/25/22.
// GPL License, don't be a dick
//

#ifndef CRAFTINGCALCULATORC___RECIPE_H
#define CRAFTINGCALCULATORC___RECIPE_H


#include <vector>
#include "Ingredient.h"
#include "IngredientList.h"

class Ingredient;
class IngredientList;

class Recipe
{
private:
  IngredientList *inputs, *outputs;
  bool enabled;
public:
  explicit Recipe();
  bool is_enabled() const;
  void set_enabled(bool isEnabled);
  void add_input(Ingredient ingredient);
  void add_output(Ingredient ingredient);
  void get_cost(Ingredient, IngredientList*, IngredientList*);
  Ingredient *get_output_ingredient(Ingredient& ingredient);
};


#endif //CRAFTINGCALCULATORC___RECIPE_H
