/*
The teacher has sent an e-mail to her students with the following task: “Write a program that will determine and output the value of X if given the statement:

X=numberpow11+numberpow22+…+numberpowNN and it holds that number1, number2 to numberN are integers, and pow1, pow2 to powN are one-digit integers.” Unfortunately, when the teacher downloaded the task to her computer, the text formatting was lost so the task transformed into a sum of N integers:
X=P1+P2+…+PN

For example, without text formatting, the original task in the form of X=212+1253
became a task in the form of X=212+1253. Help the teacher by writing a program that will, for given N integers from P1 to PN determine and output the value of X from the original task.

Input
The first line of input contains the integer N
(1≤N≤10), the number of the addends from the task. Each of the following N lines contains the integer Pi (10≤Pi≤9999, i=1,…,N) from the task.

Output
The first and only line of output must contain the value of X
(X≤1000000000) from the original task.

Sample Input 1
2
212
1253

Sample Output 1
1953566
*/
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  string strval;
  string strbase;
  string strexp;
  string strvalcopy;
  int number_of_values;
  int counter = 0;
  int result;
  int intbase;
  int intexp;
  
  cin >> number_of_values;

  while(counter < number_of_values)
    {
      cin >> strval;
      strvalcopy = strval;
      strexp = strval.back();
      strvalcopy.erase(strvalcopy.find(strvalcopy.back()),1);
      strbase = strvalcopy;
      intbase = stoi(strbase, nullptr, 0);
      intexp = stoi(strexp, nullptr, 0);
      cout << intbase << endl;
      cout << intexp << endl;
      result += pow(intbase, intexp);
      counter++;
    }
  cout << result << endl;
}
