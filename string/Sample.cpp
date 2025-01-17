#include <string>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

auto trim(string const & s) -> string
{
  auto front = find_if_not (begin(s), end(s), isspace);
  auto back = find_if_not (rbegin(s), rend(s), isspace);

  return string{front, back.base()};
}

int main()
{
  auto s = string {};
  //or
  s = basic_string<char> {};

  auto ws = wstring{};
  ws = basic_string<wchar_t> {};

  static_assert(sizeof(string:value_type) == 1, "1 byte");
  static_assert(sizeof(wstring::value_type) == 2, "2 bytes");

  s = string {"cluck!"};

  assert(!s.empty());

  assert(s.size() == 6);

  cout << s.c_str() << endl;

  s = string {'C', 'l', 'u', 'c', 'k'};

  cout << s.c_str() << endl;

  s.clear();

  assert(s.empty());
  assert(s.size() == 0);
  assert(0 == strcmp(s.c_str(), ""));

  s = string {"That hen clucked!"};

  s = string(s, 4, 3);

  assert(s == "hen");

  for(auto c : s)
    {
      cout << c << endl;
    }

  auto hen = string{"Matilda"};
  auto pasture = string{"Tomatoes"};
  auto id = hen + "@" + pasture;

  cout << id.c_str() << endl;

  auto pos = id.find('@');

  auto domain = id.substr(pos);

  assert(domain == "@Tomatoes");

  auto trimmed = trim("\t Matilda the hen \r\n.");

  assert(trimmed == "Matilda the hen");
}
