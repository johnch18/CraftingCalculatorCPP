#include <iostream>
#include <cassert>
#include <Component.h>


void test()
{
  Component *woodPickaxe = Component::get_component("woodPickaxe");
  Component *stick       = Component::get_component("stick");
  Component *woodPlank   = Component::get_component("woodPlank");
  Component *woodLog     = Component::get_component("woodLog");
  //
  Recipe    woodPickaxeRecipe{
    {{woodPickaxe, 1}},
    {{woodPlank,   3}, {stick, 2}}
  };
  Recipe    stickRecipe{
    {{stick,     4}},
    {{woodPlank, 2}}
  };
  Recipe    woodPlankRecipe{
    {{woodPlank, 4}},
    {{woodLog,   1}}
  };
  //
  woodPickaxeRecipe.set_enabled(true);
  woodPickaxe->add_recipe(&woodPickaxeRecipe);
  //
  stickRecipe.set_enabled(true);
  stick->add_recipe(&stickRecipe);
  //
  woodPlankRecipe.set_enabled(true);
  woodPlank->add_recipe(&woodPlankRecipe);
  //
  auto list  = IngredientList();
  auto cache = IngredientList();
  woodPickaxeRecipe.get_cost(Ingredient(woodPickaxe, 64), &list, &cache);
  for (auto const &[name, ingredient]: list)
  {
    std::cout << name << ":" << ingredient.get_amount() << std::endl;
  }
}


int main()
{
  std::cout << "Hello, World!" << std::endl;
  test();
  std::cout << "Goodbye, World!" << std::endl;
  return 0;
}
