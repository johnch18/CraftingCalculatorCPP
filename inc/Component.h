//
// Created by johnch18 on 2/17/22.
// GPL License, don't be a dick
//

#ifndef CRAFTINGCALCULATOR_COMPONENT_H
#define CRAFTINGCALCULATOR_COMPONENT_H


#include <string>
#include "NbtData.h"
#include "Recipe.h"


class Component;
class Recipe;


typedef std::map<unsigned, Component *> ComponentMap;


class Component
{
  /*
   * The component class is an abstraction of both fluids and items.
   * It contains information such as name, ID number, metadata, nbt data, and whether it's a fluid.
   * Also contains recipe information and ore dictionary entry.
   * */
private:
  // Stores all components in existence
  static ComponentMap   REGISTRY;
  // Fields
  std::string           name;
  unsigned              idNumber,
                        metadata;
  NBTData               *nbtData;
  bool                  isFluid;
  std::vector<Recipe *> recipes;
  // Initializer hidden
  Component() = default;
public:
  // TODO Disable copy constructor
  // This is how components will be created
  static Component *create_component(std::string, unsigned, unsigned, NBTData*, bool=false);
  // This is how they will be destroyed
  static void destroy_components();
  // Get hash of component for convenience
  static unsigned long get_hash(std::string name, unsigned idNum, unsigned metadata, NBTData *nbt, bool isFluid);
  unsigned long get_hash();
};


#endif //CRAFTINGCALCULATOR_COMPONENT_H
