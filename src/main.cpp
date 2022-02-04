#include <iostream>
#include <Component.h>


void test_recursive()
{
  Recipe         netherStarRecipe{
    {"netherStar:2"},
    {"tinyNetherStarDust", "magmaCream"}
  };
  Recipe         tinyNetherStarDustRecipe{
    {"tinyNetherStarDust:9"},
    {"netherStarDust"}
  };
  Recipe         netherStarDustRecipe{
    {"netherStarDust"},
    {"netherStar"}
  };
  //
  auto           target = Ingredient{"netherStar:64"};
  auto           result = netherStarRecipe.get_cost(target,
                                                    {"tinyNetherStarDust:1"});
  IngredientList cost   = result.first;
  for (auto &[name, ingredient]: cost)
  {
    std::cout << ingredient.get_str() << std::endl;
  }
  //
  Component::memory_cleanup();
}

void test()
{
  Recipe     woodPickaxeRecipe{
    {"woodPickaxe"},
    {"woodPlank:3", "stick:2"}
  };
  Recipe     woodPlankRecipe{
    {"woodPlank:4"},
    {"woodLog:1"}
  };
  Recipe     stickRecipe{
    {"stick:4"},
    {"woodPlank:2"}
  };
  //
  Ingredient target{"woodPickaxe:64"};
  woodPickaxeRecipe.get_cost(target);
  Component::memory_cleanup();
}


int main()
{
  std::cout << "Hello, World!" << std::endl;
  test_recursive();
  std::cout << "Goodbye, World!" << std::endl;
  return 0;
}
