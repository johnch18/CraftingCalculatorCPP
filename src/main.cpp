#include <iostream>
#include <Component.h>
#include <cassert>


void test() {
  std::string name = "woodPlank";
  Component *woodPlanks = Component::get_component(name, false);
  Component *woodPlanks2 = Component::get_component(name, false);
  assert(woodPlanks == woodPlanks2);
}


int main()
{
  std::cout << "Hello, World!" << std::endl;
  test();
  std::cout << "Goodbye, World!" << std::endl;
  return 0;
}
