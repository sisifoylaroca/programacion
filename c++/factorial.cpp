#include <iostream>

using namespace std;

long factorial(long);

int main()
{
  long  number = 33;

  cout << number << " factorial is: " << factorial(number) << endl;
  return 0;
}

long factorial(long number)
{
  long temp;

  if(number <= 1)
    return 1;

  temp = number * factorial(number - 1);
  
  return temp;
}