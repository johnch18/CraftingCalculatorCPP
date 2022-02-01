#include <iostream>
#include <cassert>
#include <Component.h>


void test()
{
  //
  Recipe         woodPickaxeRecipe{
    {"woodPickaxe"},
    {"woodPlank:3", "stick:2"}
  };
  Recipe         stickRecipe{
    {"stick:4"},
    {"woodPlank:2"}
  };
  Recipe         woodPlankRecipe{
    {"woodPlank:4"},
    {"woodLog"}
  };
  //
  auto           output = woodPickaxeRecipe.get_cost({"woodPickaxe:64"});
  IngredientList list   = output.first;
  IngredientList excess = output.second;
  for (auto const &[name, ingredient]: list)
  {
    std::cout << name << ":" << ingredient.get_amount() << std::endl;
  }
  Component::memory_cleanup();
}


int main()
{
  std::cout << "Hello, World!" << std::endl;
  test();
  std::cout << "Goodbye, World!" << std::endl;
  return 0;
}
