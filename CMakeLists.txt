cmake_minimum_required(VERSION 3.20)
project(craftingCalculator)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS_DEBUG "-O0")

add_executable(craftingCalculator
        src/main.cpp src/Component.cpp inc/Component.h src/NbtData.cpp inc/NbtData.h inc/CraftingCalculator.h src/IIngredient.cpp inc/IIngredient.h src/Ingredient.cpp inc/Ingredient.h src/OreDictIngredient.cpp inc/OreDictIngredient.h src/OreDictEntry.cpp inc/OreDictEntry.h src/IngredientList.cpp inc/IngredientList.h inc/Recipe.cpp inc/Recipe.h)
target_include_directories(craftingCalculator PRIVATE inc)

