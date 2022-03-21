#include <iostream>
#include <algorithm>
using std::cin, std::cout, std::endl;

int a[3];
char A, B, C;

int main()
{
  cin >> a[0] >> a[1] >> a[2];
  cin >> A >> B >> C;
  std::sort(a, a + 3);
  cout << a[A - 'A'] << " " << a[B - 'A'] << " " << a[C - 'A'];
  return 0;
}