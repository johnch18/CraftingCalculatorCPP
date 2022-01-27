//
// Created by johnch18 on 1/25/22.
// GPL License, don't be a dick
//

#include "Recipe.h"


void Recipe::add_input(Ingredient ingredient)
{
  inputs.push_back(ingredient);
}

void Recipe::add_output(Ingredient ingredient)
{
  outputs.push_back(ingredient);
}
