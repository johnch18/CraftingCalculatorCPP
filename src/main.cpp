#include <iostream>
#include <Component.h>

void test() {
  std::string name = "woodPlank";
  Component *woodPlanks = Component::get_component(name, false);
}


int main()
{
  std::cout << "Hello, World!" << std::endl;
  test();
  std::cout << "Goodbye, World!" << std::endl;
  return 0;
}
