//
// Created by johnch18 on 2/17/22.
// GPL License, don't be a dick
//

#ifndef CRAFTINGCALCULATOR_NBTDATA_H
#define CRAFTINGCALCULATOR_NBTDATA_H


#include <string>
#include <vector>
#include <map>
#include <variant>


class NBTData;


// Useful for iteration and whatnot
typedef std::pair<std::string, NBTData *> NBTTagPair;
typedef std::vector<NBTData *>            NBTList;
typedef std::map<std::string, NBTData *>  NBTTagMap;


class NBTData
{
  /*
   * Stores NBTData. I would just use json but according to the minecraft wiki there are a couple compat issues.
   * */
public:
  typedef std::variant<unsigned char, short, int, long, float, std::string, NBTList, NBTTagMap, std::vector<char>,
    std::vector<int>, std::vector<long>, bool> NBTPackage;
  //
private:
  // Data
  NBTPackage package;
public:

};


#endif //CRAFTINGCALCULATOR_NBTDATA_H
