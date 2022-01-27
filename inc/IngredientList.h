//
// Created by johnch18 on 1/26/22.
// GPL License, don't be a dick
//

#ifndef CRAFTINGCALCULATORC___INGREDIENTLIST_H
#define CRAFTINGCALCULATORC___INGREDIENTLIST_H


#include "Ingredient.h"

class Ingredient;

class IngredientList: public std::map<std::string, Ingredient>
{
private:
public:
  Ingredient *add_ingredient(Ingredient&);
};


#endif //CRAFTINGCALCULATORC___INGREDIENTLIST_H
