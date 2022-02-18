//
// Created by johnch18 on 2/17/22.
// GPL License, don't be a dick
//

#include "IngredientList.h"


void IngredientList::add_ingredient(IIngredient *ingredient)
{
  // Check if ingredient is already in there
  auto key = ingredient->get_component()->get_hash();
  auto found = find(key);
  if (found != end()) {
    // Combine them
    found->second->combine_with(ingredient);
    // Return
    return;
  }
  this->at(key) = ingredient;
}
