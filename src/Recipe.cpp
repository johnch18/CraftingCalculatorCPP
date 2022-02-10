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
  ingredient.get_component()->add_recipe(this);
}

Recipe::Recipe()
{
  inputs  = new IngredientList{};
  outputs = new IngredientList{};
}

Ingredient *Recipe::get_output_ingredient(Ingredient &ingredient)
{
  auto                                        name = ingredient.get_component()->get_name();
  std::map<std::string, Ingredient>::iterator it;
  for (it = outputs->begin(); it != outputs->end(); it++)
  {
    // std::cout << it->first << " " << name << std::endl;
    if (it->first == name)
    {
      return &it->second;
    }
  }
  return nullptr;
}

void Recipe::get_cost_rec(Ingredient initialIngredient, IngredientList *inputList,
                          IngredientList *cache, unsigned depth)
{
  // Check if setup is valid
  if (depth > Recipe::MAX_REC || inputList == nullptr || cache == nullptr)
    return;
  // Get the output ingredient and validate
  Ingredient *targetIngredient = get_output_ingredient(initialIngredient);
  if (targetIngredient == nullptr)
    return;
  // Adjust if ingredient in cache
  for (auto &[name, cacheIngredient]: *cache)
  {
    if (cacheIngredient.is_same_as(initialIngredient))
    {
      // Possible bug here
      unsigned n = std::min(initialIngredient.get_amount(),
                            cacheIngredient.get_amount());
      initialIngredient.sub_in_place(n);
      cacheIngredient.sub_in_place(n);
    }
  }
  // Ignore if request satisfied
  if (initialIngredient.get_amount() <= 0)
    return;
  // Calculate factors
  double   amount         = targetIngredient->get_amount();
  double   chance         = targetIngredient->get_chance();
  double   factor         = amount * chance;
  unsigned numberOfCrafts = ceil(initialIngredient.get_amount() / factor);
  // Iterate through inputs
  for (auto &[name, inputIngredient]: *inputs)
  {
    auto newInputIngredient = inputIngredient.multiply(numberOfCrafts);
    auto *component         = newInputIngredient.get_component();
    auto *recipe            = component->get_active_recipe();
    // Check if an active recipe exists
    // If not, add the ingredient as itself and continue
    if (recipe == nullptr || !recipe->enabled)
    {
      inputList->add_ingredient(newInputIngredient);
      continue;
    }
    // Recurse
    recipe->get_cost_rec(newInputIngredient, inputList, cache, depth + 1);
  }
  // Deal with excess outputs
  for (auto &[name, outputIngredient]: *outputs)
  {
    // Ignore initialIngredient
    if (!outputIngredient.is_same_as(initialIngredient))
    {
      cache->add_ingredient(outputIngredient);
    }
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
  : Recipe()
{
  for (auto &output: outputs)
  {
    this->add_output(output);
  }
  for (auto &input: inputs)
  {
    this->add_input(input);
  }
}

std::pair<IngredientList, IngredientList> Recipe::get_cost(Ingredient inp)
{
  return get_cost(inp, IngredientList());
}

Recipe::Recipe(std::initializer_list<std::string> outputs,
               std::initializer_list<std::string> inputs)
  : Recipe()
{
  for (auto input: inputs)
  {
    this->add_input(Ingredient{input});
  }
  for (auto output: outputs)
  {
    this->add_output(Ingredient{output});
  }
}

std::pair<IngredientList, IngredientList> Recipe::get_cost(Ingredient inp,
                                                           IngredientList
                                                           preCache)
{
  std::pair<IngredientList, IngredientList> result = {IngredientList{},
                                                      IngredientList{}};
  result.second.combine_with(preCache);
  get_cost_rec(inp, &result.first, &result.second);
  return result;
}


