#include <iostream>
#include <Component.h>

void test() {
  Component *woodPlanks = Component::get_component((std::string &) "woodPlank", false);
}


int main()
{
  std::cout << "Hello, World!" << std::endl;
  test();
  std::cout << "Goodbye, World!" << std::endl;
  return 0;
}
