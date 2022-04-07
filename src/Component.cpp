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
  // Check registry for hash
  auto found = REGISTRY.find(hash);
  if (found == REGISTRY.end())
  {
    // If not found, add it and return
    auto newComponent = new Component();
    newComponent->name = name;
    newComponent->idNumber = idNum;
    newComponent->metadata = metadata;
    newComponent->nbtData = nbt;
    newComponent->isFluid = isFluid;
    return newComponent;
  } else {
    // If found, return
    return found->second;
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

void Component::destroy_components()
{
  // TODO: Implement
}



