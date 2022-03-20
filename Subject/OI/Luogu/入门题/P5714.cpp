#include<iostream>
using std::cin, std::cout, std::endl;

int main()
{
  double m, x;
  cin >> m >> x;
  x *= x;
  m /= x;

  if(m < 18.5)
    cout << "Underweight";
  else if(m < 24)
    cout << "Normal";
  else
    cout << m << endl << "Overweight";
  return 0;
}