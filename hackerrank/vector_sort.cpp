/*
  You are given integers.Sort the integers and print the sorted order.
Store the integers in a vector.Vectors are sequence containers representing arrays that can change in size.

    Declaration:

    vector<int>v; (creates an empty vector of integers)

    Size:

    int size=v.size();

    Pushing an integer into a vector:

    v.push_back(x);(where x is an integer.The size increases by 1 after this.)

    Popping the last element from the vector:

    v.pop_back(); (After this the size decreases by 1)

    Sorting a vector:

    sort(v.begin(),v.end()); (Will sort all the elements in the vector)

To know more about vectors, Click Here

Input Format

The first line of the input contains where is the number of integers. The next line contains integers.
Constraints

, where is the integer in the vector.

Output Format

Print the integers in the sorted order one by one in a single line followed by a space.

Sample Input

5
1 6 10 8 4

Sample Output

1 4 6 8 10

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> vec;
  int num_ints;
  int in;
  cin >> num_ints;
  for(int x = 0; x < num_ints; x++)
    {
      cin >> in;
      vec.push_back(in);
    }
  sort(vec.begin(), vec.end());

  for(int x = 0; x < vec.size(); x++)
    {
      cout << vec[x] <<  " ";
    }
}
