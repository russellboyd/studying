#include <iostream>
#include <memory>
#include <string>
#include <map>

struct HotDrink
{
  virtual void prepare(int volume) = 0;
  
};

struct Tea : HotDrink
{
  void prepare(int volume) override
  {
    std::cout << "Take tea bag, boil water, pour " << volume << "ml" << std::endl;
  }
};

struct Coffee : HotDrink
{
  void prepare(int volume) override
  {
    std::cout << "Grind some beans, boil water, pour " << volume << "ml" << std::endl;
  }
};


