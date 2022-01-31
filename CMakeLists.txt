cmake_minimum_required(VERSION 3.20)
project(craftingCalculatorC__)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS_DEBUG "-O0")

add_executable(craftingCalculatorC__
        src/main.cpp
        inc/CraftingCalculator.h
        src/RecipeBook.cpp
        inc/RecipeBook.h
        src/Recipe.cpp
        inc/Recipe.h
        src/Ingredient.cpp
        inc/Ingredient.h
        src/Component.cpp
        inc/Component.h src/IngredientList.cpp inc/IngredientList.h)
target_include_directories(craftingCalculatorC__ PRIVATE inc)

