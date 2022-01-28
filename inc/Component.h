//
// Created by johnch18 on 1/25/22.
// GPL License, don't be a dick
//

#ifndef CRAFTINGCALCULATORC___COMPONENT_H
#define CRAFTINGCALCULATORC___COMPONENT_H


#include <string>
#include <map>
#include "Recipe.h"


class Recipe;


class Component
{
private:
  static std::map<std::string, Component *> registry;
  std::vector<Recipe *>                     recipes;
  std::string                               name;
  bool                                      isFluid;
  //
  Component(std::string &, bool);
public:
  //
  static Component *get_component(std::string &, bool);
  const std::string &get_name() const;
  bool is_fluid() const;

  const std::vector<Recipe *> &get_recipes();
  Recipe* get_active_recipe();

  // Yeet these mofos
  Component(const Component &) = delete;
  Component(Component &&) = delete;
  Component &operator=(const Component &) = delete;
  Component &operator=(Component &&) = delete;
  void add_recipe(Recipe *recipe);
};


#endif //CRAFTINGCALCULATORC___COMPONENT_H
