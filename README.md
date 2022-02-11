# Crafting Calculator vAlpha

## Supports:

- Recursive crafting
- Multiple recipes (must manually select a recipe to use though, give me a break I'm not going to read your mind)
- Chance outputs

## Features I want:

- Ability to rip recipes, item names, and icons from game
- GUI to do crafting calculations
- Minecraft version independence
- Portability

## Example:

Given a recipe tree, rough approximation of NH's star recipe, simplified for demonstrative purposes:

```c++
    Recipe netherStarRecipe{
      {"netherStar:2"},
      {"tinyNetherStarDust", "magmaCream"}
    };
    Recipe tinyNetherStarDustRecipe{
      {"tinyNetherStarDust:9"},       
      {"netherStarDust"}
    };
    Recipe netherStarDustRecipe{
      {"netherStarDust"},
      {"netherStar"}
    };
```
Should we query the program with the following:
```c++
    auto           target = Ingredient{"netherStar:64"};
    auto           result = netherStarRecipe.get_cost(target, {"tinyNetherStarDust:1"});
    IngredientList cost   = result.first,
    excess = result.second;
    std::cout << "Inputs: " << std::endl;
    for (auto &[name, ingredient]: cost)
    {
      std::cout << ingredient.get_str() << std::endl;
    }
      std::cout << "Excess Outputs: " << std::endl;
    for (auto &[name, ingredient]: excess)
    {
      std::cout << ingredient.get_str() << std::endl;
    }
    //
    Component::memory_cleanup();
```