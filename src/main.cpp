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
  Recipe stonePickaxeRecipe{};
  Recipe stickRecipe{};
  Recipe woodPlankRecipe{};
  //
  stonePickaxeRecipe.add_input(Ingredient(cobblestone, 3));
  stonePickaxeRecipe.add_input(Ingredient(stick, 2));
  stonePickaxeRecipe.add_output(Ingredient(stonePickaxe, 1));
  stonePickaxeRecipe.set_enabled(true);
  stonePickaxe->add_recipe(&stonePickaxeRecipe);
  //
  stickRecipe.add_input(Ingredient(woodPlank, 2));
  stickRecipe.add_output(Ingredient(stick, 4));
  stickRecipe.set_enabled(true);
  stick->add_recipe(&stickRecipe);
  //
  woodPlankRecipe.add_input(Ingredient(woodLog, 1));
  woodPlankRecipe.add_output(Ingredient(woodPlank, 4));
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
