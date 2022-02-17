//
// Created by johnch18 on 2/17/22.
// GPL License, don't be a dick
//

#ifndef CRAFTINGCALCULATOR_INGREDIENTLIST_H
#define CRAFTINGCALCULATOR_INGREDIENTLIST_H


#include "Ingredient.h"


class IngredientList: public std::map<unsigned, Ingredient>
{
  /*
   * Basically just a wrapper for map that allows me to do some convenient checking
   * */
private:
public:
  // Adds the ingredient to the map
  void add_ingredient(Ingredient&);
};


#endif //CRAFTINGCALCULATOR_INGREDIENTLIST_H
