#include <iostream>
#include <cassert>
#include <Component.h>


void test()
{
  std::string name           = "woodPlank";
  Component   *woodPlanks    = Component::get_component(name, false);
  std::string name2          = "craftingBench";
  Component   *craftingBench = Component::get_component(name2, false);
  std::string name3          = "woodLog";
  Component *woodLog = Component::get_component(name3, false);
  Recipe      woodPlanksRecipe;
  Recipe      craftingBenchRecipe;
  craftingBenchRecipe.add_input(Ingredient(woodPlanks, 4));
  craftingBenchRecipe.add_output(Ingredient(craftingBench, 1));
  woodPlanksRecipe.add_input(Ingredient(woodLog, 1));
  woodPlanksRecipe.add_output(Ingredient(woodPlanks, 4));
  //
  craftingBench->add_recipe(&craftingBenchRecipe);
  woodPlanks->add_recipe(&woodPlanksRecipe);
  auto target = Ingredient(craftingBench, 256);
  auto *list  = new IngredientList();
  craftingBenchRecipe.get_cost(target, list);
  for (auto const&[ingName, ing]: *list)
  {
    if (ing.isValid())
      std::cout << ingName << ":" << ing.get_amount() << std::endl;
  }
}


int main()
{
  std::cout << "Hello, World!" << std::endl;
  test();
  std::cout << "Goodbye, World!" << std::endl;
  return 0;
}
