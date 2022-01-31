//
// Created by johnch18 on 1/25/22.
// GPL License, don't be a dick
//

#include <algorithm>
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

Ingredient *Recipe::get_output_ingredient(Ingredient &ingredient)
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

void Recipe::get_cost(Ingredient ing, IngredientList *inputList,
                      IngredientList *cache)
{
  Ingredient *target = get_output_ingredient(ing);
  if (target == nullptr)
  {
    throw std::exception();
  }

  if (cache->contains(ing)) {
    unsigned n = std::min(ing.get_amount(), cache->at(ing.get_component()
    ->get_name()).get_amount());
    cache->at(ing.get_component()->get_name()).subtract(n);
    ing.subtract(n);
  }

  auto ingAmount = static_cast<double>(ing.get_amount());
  unsigned numCrafts = ceil(ingAmount / (target->get_amount() *
    target->get_chance()));

  for (auto &_ingredient: *inputs)
  {
    Ingredient &ingredient = _ingredient.second;
    Recipe     *recipe     = ingredient.get_component()->get_active_recipe();
    ingredient.multiply(numCrafts);
    if (recipe == nullptr)
    {
      inputList->add_ingredient(ingredient);
      continue;
    }
    recipe->get_cost(ingredient, inputList, cache);
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

Recipe::Recipe(std::initializer_list<Ingredient> outputs,
  std::initializer_list<Ingredient> inputs)
{
  for (auto& output : outputs) {
    this->outputs->add_ingredient(output);
  }
  for (auto& input : inputs) {
    this->inputs->add_ingredient(input);
  }
}


