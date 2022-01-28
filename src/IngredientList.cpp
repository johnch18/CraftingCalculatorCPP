//
// Created by johnch18 on 1/26/22.
// GPL License, don't be a dick
//

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
  if (find(name) == end()) {

  } else {

  }
}

void IngredientList::combine_with(IngredientList &other)
{
  for (const auto &item: other)
  {
    add_ingredient(item.second);
  }
}

