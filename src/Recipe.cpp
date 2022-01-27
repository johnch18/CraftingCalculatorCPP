//
// Created by johnch18 on 1/25/22.
// GPL License, don't be a dick
//

#include "Recipe.h"


void Recipe::add_input(Ingredient ingredient)
{
  inputs->add_ingredient(ingredient);
}

void Recipe::add_output(Ingredient ingredient)
{
  outputs->add_ingredient(ingredient);
}

Recipe::Recipe()
{
  inputs = new IngredientList();
  outputs = new IngredientList();
}

IngredientList Recipe::get_cost(Ingredient ing)
{
  IngredientList list{};
  auto output = get_output_ingredient(ing);
  return list;
}

Ingredient Recipe::get_output_ingredient(Ingredient ingredient)
{
  for (auto const& [key, val] : *outputs) {
    if (key == ingredient.get_component()->get_name()) {
      return val;
    }
  }
  return {nullptr, 0};
}
