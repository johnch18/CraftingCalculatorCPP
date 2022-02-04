//
// Created by johnch18 on 1/26/22.
// GPL License, don't be a dick
//

#include <iostream>
#include "IngredientList.h"


void IngredientList::add_ingredient(Ingredient ing)
{
  std::string name = ing.get_component()->get_name();
  if (find(name) == end())
  {
    this->emplace(name, ing);
  }
  else
  {
    this->at(name).add(ing.get_amount());
  }
}

void IngredientList::subtract_ingredient(Ingredient ing)
{
  std::string name = ing.get_component()->get_name();
  if (find(name) != end()) {
    this->at(name).subtract(ing.get_amount());
  }
}

void IngredientList::combine_with(IngredientList &other)
{
  for (const auto &item: other)
  {
    add_ingredient(item.second);
  }
}

bool IngredientList::contains(Ingredient &ing)
{
  return contains(ing.get_component()->get_name());
}

bool IngredientList::contains(std::string s)
{
  return find(s) != end();
}

IngredientList::IngredientList(std::initializer_list<Ingredient> list): IngredientList()
{
  for (auto &i : list) {
    add_ingredient(i);
  }
}

IngredientList::IngredientList(std::initializer_list<std::string> list): IngredientList()
{
  for (auto &i : list) {
    add_ingredient({i});
  }
}

IngredientList::IngredientList()
{
}

