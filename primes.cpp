#include <iostream>
using namespace std;

int main()
{
  int x;
  cout << "Enter a number" << endl;
  cin >> x;
  bool prime = true;
  int i = 2;

  while(i <= x/i)
    {
      int factor = x/i;
      if(factor*i == x)
	{
	  cout << "Factor found : " << factor << endl;
	  prime = false;
	  break;
	}
      i = i + 1;
    }

  cout << x << " is ";
  if(prime)
    {
      cout << "prime" << endl;
    }
  else
    {
      cout << "not prime" << endl;
    }

  return 0;
}
