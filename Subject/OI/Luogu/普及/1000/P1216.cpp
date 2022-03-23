#include <iostream>
using std::cin, std::cout, std::endl;
#define max(a, b) ((a)>(b)?(a):(b))

int dp[1005], r;
char c[500505];

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> r;
  for(int i = 1; i <= (r + 1) * r / 2; ++i)
    cin >> (short&)c[i];

  for(int i = 1; i <= r; ++i)
  {
    int b = (i - 1) * i / 2;
    for(int j = i; j > 0; --j)
      dp[j] = max(dp[j - 1], dp[j]) + c[b + j];
  }

  int _max_ = 0;
  for(int i = 1; i <= r; ++i)
    if(_max_ < dp[i])
      _max_ = dp[i];

  cout << _max_;

  return 0;
}
