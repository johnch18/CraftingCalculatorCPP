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

void Recipe::get_cost_rec(Ingredient ing, IngredientList *inputList,
                          IngredientList *cache, unsigned depth)
{
  // std::cout << ing.get_str() << std::endl;
  // Don't go too deep
  if (depth > Recipe::MAX_REC)
  {
    return;
  }
  // Get the ingredient matching the component type of ing
  Ingredient *target      = get_output_ingredient(ing);
  // Shouldn't happen, but might
  // TODO: Add way to deal with this
  if (target == nullptr)
  {
    throw std::exception();
  }
  // Check if cache has the requested item, use what's needed
  if (cache->contains(ing))
  {
    auto     &cacheIng = cache->at(ing.get_component()->get_name());
    unsigned n         = std::min(ing.get_amount(), cacheIng.get_amount());
    cacheIng.subtract(n);
    ing.subtract(n);
  }
  // Get how many times the recipe must be executed to get the desired amount
  auto       ingAmount    = static_cast<double>(ing.get_amount());
  double     targetFactor = target->get_amount() * target->get_chance();
  unsigned   numCrafts    = ceil(ingAmount / targetFactor);
  // Iterate through inputs
  for (auto  &_ingredient: *inputs)
  {
    // Get recipe and calculate how many of the ingredient you'll need
    Ingredient ingredient = _ingredient.second;
    Recipe     *recipe    = ingredient.get_component()->get_active_recipe();
    ingredient.multiply(numCrafts);
    // Ignore ingredients without recipes or with disabled recipes
    if (recipe == nullptr || !recipe->is_enabled())
    {
      inputList->add_ingredient(ingredient);
      continue;
    }
    // Depth first traversal
    IngredientList tempIList;
    recipe->get_cost_rec(ingredient, &tempIList, cache, depth + 1);
    // Iterate through results
    for (auto &[name, i]: tempIList)
    {
      // Check if this was the target ingredient
      if (i.is_same_as(ingredient))
      {
        unsigned targetNum = ingredient.get_amount();
        unsigned actualNum = i.get_amount();
      }
      else
      {

      }
    }
    inputList->combine_with(tempIList);
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
                                                      IngredientList{"netherStar"}};
  result.second.combine_with(preCache);
  get_cost_rec(inp, &result.first, &result.second);
  return result;
}


