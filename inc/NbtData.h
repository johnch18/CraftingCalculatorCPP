//
// Created by johnch18 on 2/17/22.
// GPL License, don't be a dick
//

#ifndef CRAFTINGCALCULATOR_NBTDATA_H
#define CRAFTINGCALCULATOR_NBTDATA_H


#include <string>
#include <vector>
#include <map>

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
  union NBTPackage
  {
    /*
     * Stores the actual NBT data
     * */
    unsigned char     byteData;
    short             shortData;
    int               intData;
    long              longData;
    float             floatData;
    std::string       stringData;
    NBTList           listData;
    NBTTagMap         compoundData;
    std::vector<char> byteArrayData;
    std::vector<int>  intArrayData;
    std::vector<long> longArrayData;
    bool              boolData;
  };
  //
  enum class NBTMode
  {
    /*
     * Catalogs what the NBT is storing
     * */
    Null, // Invalid state, shouldn't happen
    Byte,
    Short,
    Int,
    Long, // Redundant?
    Float,
    Double, // Redundant?
    String,
    List,
    Compound, // Basically just more NBT data
    ByteArray,
    IntArray,
    LongArray, // Redundant?
    Boolean
  };
  //
private:
  // Mode
  NBTMode    mode = NBTMode::Null;
  // Data
  NBTPackage package;
public:

};


#endif //CRAFTINGCALCULATOR_NBTDATA_H
