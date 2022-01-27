#include <iostream>
#include <cassert>
#include <Component.h>


void test()
{
  std::string name           = "woodPlank";
  Component   *woodPlanks    = Component::get_component(name, false);
  std::string name2          = "craftingBench";
  Component   *craftingBench = Component::get_component(name2, false);
  Recipe      test;
  test.add_input(Ingredient(woodPlanks, 4));
  test.add_output(Ingredient(craftingBench, 1));
  craftingBench->add_recipe(&test);
  auto                                        list = test.get_cost(
    Ingredient(craftingBench, 256));
  std::map<std::string, Ingredient>::iterator it;
  for (auto const&[ingName, ing]: list)
  {
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
