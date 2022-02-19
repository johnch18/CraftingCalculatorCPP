//
// Created by johnch18 on 2/17/22.
// GPL License, don't be a dick
//

#include "Component.h"


// Initialize registry
ComponentMap Component::REGISTRY = ComponentMap();

unsigned long Component::get_hash()
{
  return Component::get_hash(name, idNumber, metadata, nbtData, isFluid);
}

Component *Component::create_component(std::string name, unsigned idNum, unsigned metadata, NBTData *nbt, bool isFluid)
{
  unsigned long hash = Component::get_hash(name, idNum, metadata, nbt, isFluid);
  if (REGISTRY.find(hash) == REGISTRY.end())
  {

  }

}

unsigned long Component::get_hash(std::string name, unsigned idNum, unsigned metadata, NBTData *nbt, bool isFluid)
{
  unsigned long hash = 0;
  for (auto     c: name)
  {
    hash += static_cast<unsigned>(c);
  }
  hash += idNum;
  hash += metadata;
  hash += static_cast<unsigned>(isFluid);
  // TODO: Figure out NBT data
  return hash;
}



