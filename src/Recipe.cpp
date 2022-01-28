//
// Created by johnch18 on 1/25/22.
// GPL License, don't be a dick
//

#include <cmath>
#include <iostream>
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
  inputs  = new IngredientList();
  outputs = new IngredientList();
}

Ingredient *Recipe::get_output_ingredient(Ingredient ingredient)
{
  std::map<std::string, Ingredient>::iterator it;
  for (it = outputs->begin(); it != outputs->end(); it++)
  {
    if (it->first == ingredient.get_component()->get_name())
    {
      return &it->second;
    }
  }
  return nullptr;
}

void Recipe::get_cost(Ingredient ing, IngredientList *cache)
{
  Ingredient *target = get_output_ingredient(ing);
  if (target == nullptr)
  {
    throw std::exception();
  }
  unsigned numCrafts = ceil(static_cast<double>(ing.get_amount()) / target
    ->get_amount());

  for (auto &_ingredient: *inputs)
  {
    Ingredient &ingredient = _ingredient.second;
    Recipe *recipe = ingredient.get_component()->get_active_recipe();
    ingredient.multiply(numCrafts);
    if (recipe == nullptr) {
      cache->add_ingredient(ingredient);
      continue;
    }
    recipe->get_cost(ingredient, cache);
  }
}

bool Recipe::is_enabled() const
{
  return enabled;
}

void Recipe::set_enabled(bool isEnabled)
{
  Recipe::enabled = isEnabled;
}

