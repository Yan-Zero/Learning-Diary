#include <iostream>
using std::cin, std::cout, std::endl;

int t, m, p[10005], c[10005];
unsigned long long dp[10000005];

inline unsigned long long max(unsigned long long a, unsigned long long b) {
    return a > b ? a : b;
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> t >> m;
  for(int i = 0; i < m; ++i)
    cin >> c[i] >> p[i];
  
  for(int i = 0; i < m; ++i)
    for(int j = c[i]; j <= t; ++j)
      dp[j] = max(dp[j], dp[j - c[i]] + p[i]);

  cout << dp[t] << endl;

  return 0;
}
