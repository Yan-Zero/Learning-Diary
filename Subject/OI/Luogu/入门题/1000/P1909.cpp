#include <iostream>
using std::cin, std::cout, std::endl;

int n, v[3], p[3], _min = 0x6FFFFFFF, dp[20];

inline int min(int a, int b) {
    return a < b ? a : b;
}
inline int div_(int a, int b) {
    return int(a / b) + (a % b == 0 ? 0 : 1);
}

int main()
{
  cin >> n;
  cin >> v[0] >> p[0];
  cin >> v[1] >> p[1];
  cin >> v[2] >> p[2];

  for(int i = 0; i < 3; ++i)
    _min = min(_min, div_(n, v[i]) * p[i]);

  cout << _min << endl;

  return 0;
}
