#include "stdio.h"

int n, m, dp[5002], ans;
char link[5002][5002], out[5002];

int memo(int d)
{
  if(dp[d])        return dp[d];
  if(!link[0][d])  dp[d] = 1;
  else for(int i = 1; i <= n; ++i)
  if(link[d][i]) { dp[d] += memo(i); dp[d] %= 80112002; }
  return dp[d];
}

int main()
{
  scanf("%d%d", &n, &m);
  int x, y;
  for(int i = 1; i <= m; ++i)
  {
    scanf("%d%d", &x, &y);
    link[y][x] = 1;
    link[0][y] = 1;
    out[x] = 1;
  }

  for(int i = 1; i <= n; ++i)
    if(!out[i])
      { ans += memo(i); ans %= 80112002; }

  printf("%d", ans);
  return 0;
}
