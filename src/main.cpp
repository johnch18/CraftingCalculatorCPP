#include <iostream>
#include <Component.h>

void test()
{
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
  Ingredient     test{"woodPickaxe:64"};
  auto           output = woodPickaxeRecipe.get_cost(test);
  IngredientList list   = output.first;
  IngredientList excess = output.second;
  std::cout << test.get_str() << " requires:" << std::endl;
  for (auto &[name, ingredient]: list)
  {
    std::cout << "\t" << ingredient.get_str() << std::endl;
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
