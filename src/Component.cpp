//
// Created by johnch18 on 1/25/22.
// GPL License, don't be a dick
//

#include "Component.h"


std::map<std::string, Component *> Component::registry =
                                     std::map<std::string, Component *>();

Component *Component::get_component(std::string newName, bool fluid)
{
  Component *result;
  if (registry.find(newName) == registry.end())
  {
    result = new Component{newName, fluid};
    registry[newName] = result;
  }
  else
  {
    return registry.at(newName);
  }
  return result;
}

Component::Component(std::string &name, bool isFluid)
  : name(name),
    isFluid(isFluid)
{

}

const std::vector<Recipe *> &Component::get_recipes()
{
  return recipes;
}

const std::string &Component::get_name() const
{
  return name;
}

bool Component::is_fluid() const
{
  return isFluid;
}

void Component::add_recipe(Recipe *recipe)
{
  recipes.push_back(recipe);
}

Recipe *Component::get_active_recipe()
{
  for (auto recipe: recipes)
  {
    if (recipe->is_enabled())
    {
      return recipe;
    }
  }
  return nullptr;
}

Component *Component::get_component(const char *str, bool fluid)
{
  return Component::get_component(std::string(str), fluid);
}

void Component::memory_cleanup()
{
  for (auto &[name, component]: Component::registry)
  {
    delete component;
  }
}
