#include "HotDrink.h"
#include "HotDrinkFactory.h"

struct HotDrink;

struct CoffeeFactory : HotDrinkFactory
{
  std::unique_ptr<HotDrink> make() override;
  return std::make_unique<Coffee>();
};
