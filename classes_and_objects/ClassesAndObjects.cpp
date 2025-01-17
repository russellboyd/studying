#include "Tweeter.h"
#include "status.h"
#include "Person.h"
#include <iostream>

using std::cout;
using std::endl;

using namespace std;

int main()
{
  Person p1("Kate", "Gregory", 123);
  {
    Tweeter t1("Someone", "Else", 456, "@whoever");
  }

  cout << "after innermost block" << endl;
  cout << "p1: " << p1.GetName() << " " << p1.GetNumber() << p1.SetNumber(124) << endl;
  cout << "p1: " << p1.GetName() << " " << p1.GetNumber() << endl;
  Status s = Pending;
  s = Approved;
  return 0;
}
