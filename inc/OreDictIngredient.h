//
// Created by johnch18 on 2/17/22.
// GPL License, don't be a dick
//

#ifndef CRAFTINGCALCULATOR_OREDICTINGREDIENT_H
#define CRAFTINGCALCULATOR_OREDICTINGREDIENT_H


#include "IIngredient.h"
#include "OreDictEntry.h"

class OreDictIngredient : public IIngredient
{
  /*
   * Allows access to components through ore dictionary
   * */
private:
  // Pointer to the entry
  OreDictEntry *oreDictEntry;
public:
  // Checks if supplied component is in the registry
  bool is_valid_component(Component *);
  // Getter
  Component *get_component() override;
};


#endif //CRAFTINGCALCULATOR_OREDICTINGREDIENT_H
