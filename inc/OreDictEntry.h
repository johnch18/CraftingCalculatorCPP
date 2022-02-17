//
// Created by johnch18 on 2/17/22.
// GPL License, don't be a dick
//

#ifndef CRAFTINGCALCULATOR_OREDICTENTRY_H
#define CRAFTINGCALCULATOR_OREDICTENTRY_H


#include <string>
#include "Component.h"

class OreDictEntry;

typedef std::map<std::string, OreDictEntry*> OreDictionary;

class OreDictEntry
{
  /*
   * Essentially maps a name to a list of components
   * */
private:
  // Stores all ore dict entries
  static OreDictionary DICTIONARY;
  // Name of the entry
  std::string  name;
  // Members
  ComponentMap members;
public:
  // Disable constructor
  OreDictEntry() = delete;
};


#endif //CRAFTINGCALCULATOR_OREDICTENTRY_H
