//
// Created by johnch18 on 1/26/22.
// GPL License, don't be a dick
//

#include "IngredientList.h"


Ingredient *IngredientList::add_ingredient(Ingredient &ing)
{
  std::string name = ing.get_component()->get_name();
  if (find(name) == end()) {
    this->emplace(name, ing);
    return &ing;
  } else {
    this->at(name).add(ing.get_amount());
    return &this->at(name);
  }
}
