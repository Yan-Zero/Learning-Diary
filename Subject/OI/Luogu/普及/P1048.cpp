#include <iostream>
using std::cin, std::cout, std::endl;

int t, m, v[102], p[102], dp[102][1002];

inline int max(int a, int b) { return a > b ? a : b; }

int main()
{
  cin >> t >> m;
  for (int i = 1; i <= t; ++i)
    cin >> v[i] >> p[i];
  // dp[i][j] = max (dp[i-1][j-v[i]] + p[i]) (dp[i-1][j]) if j >= v[i]
  for(int i = 1; i <= m; ++i)
    for(int j = 1; j <= t; ++j)
      if(j >= v[i])
        dp[i][j] = max(dp[i-1][j-v[i]] + p[i], dp[i-1][j]);
      else
        dp[i][j] = dp[i-1][j];
  
  cout << dp[m][t] << endl;

  return 0;
}
