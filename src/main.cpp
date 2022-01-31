#include <iostream>
#include <cassert>
#include <Component.h>


void test()
{
  Component *stonePickaxe = Component::get_component("stonePickaxe");
  Component *cobblestone = Component::get_component("cobblestone");
  Component *stick = Component::get_component("stick");
  Component *woodPlank = Component::get_component("woodPlank");
  Component *woodLog = Component::get_component("woodLog");
  //
  Recipe stonePickaxeRecipe{
    {{stonePickaxe, 1}},
    {{cobblestone, 3}, {stick, 2}}
  };
  Recipe stickRecipe{
    {{stick, 4}},
    {{woodPlank, 2}}
  };
  Recipe woodPlankRecipe{
    {{woodPlank, 4}},
    {{woodLog, 1}}
  };
  //
  stonePickaxeRecipe.set_enabled(true);
  stonePickaxe->add_recipe(&stonePickaxeRecipe);
  //
  stickRecipe.set_enabled(true);
  stick->add_recipe(&stickRecipe);
  //
  woodPlankRecipe.set_enabled(true);
  woodPlank->add_recipe(&woodPlankRecipe);
  //
  auto list = IngredientList();
  auto cache = IngredientList();
  stonePickaxeRecipe.get_cost(Ingredient(stonePickaxe, 2), &list, &cache);
  for (auto const &[name, ingredient] : list) {
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
