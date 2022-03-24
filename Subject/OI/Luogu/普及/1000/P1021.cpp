#include <iostream>
#include <cstring>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::min;
#define INF 2147483647

int n, k, dp[5000], ans;
short fv[50], a[50];

inline int solve(int x)
{
  memset(dp, 0, sizeof(dp));
  int i = 0;
  while (dp[i] <= n)
  {
    i++;
    dp[i] = INF;
    for (int j = 1; j <= x && i - fv[j] >= 0; j++)
      dp[i] = min(dp[i], dp[i - fv[j]] + 1);
  }
  return i - 1;
}

void dfs(int index)
{
  if (index == k + 1)
  {
    auto t = solve(k);
    if (t > ans)
    {
      memcpy(a + 1, fv + 1, k * sizeof(short));
      ans = t;
    }
    return;
  }
  int end = solve(index - 1);
  for (int i = fv[index - 1] + 1; i <= end + 1; ++i)
  {
    fv[index] = i;
    dfs(index + 1);
  }
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  fv[1] = 1;

  dfs(2);

  for (int i = 1; i <= k; ++i)
    cout << a[i] << " ";
  cout << endl;
  cout << "MAX=" << ans << endl;

  return 0;
}
