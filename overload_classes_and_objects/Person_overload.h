#include <string>
#ifndef _Person_Overload_H
#define _Person_Overload_H

class Person
{
 private:
  std::string firstname;
  std::string lastname;
  int arbitrarynumber;

 public:
  Person(std::string first,
	 std::string last,
	 int arbitrary);
  ~Person();
  std::string GetName();
  int GetNumber(){return arbitrarynumber;}
  void SetNumber(int number) {arbitrarynumber = number;}
  bool operator <(Person& p);
  bool operator <(int i);
};

bool operator<(int i, Person& p);

#endif
