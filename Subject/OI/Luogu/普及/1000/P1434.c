#include "stdio.h"
#define max(a, b) ((a)>(b)?(a):(b))

int r, c, a[102][102], ans;
short dp[102][102];
 
int memo(int x, int y)
{
  if(dp[x][y]) return dp[x][y];
  int up    = y > 1 ? a[x][y-1] : -1;
  int down  = y < r ? a[x][y+1] : -1;
  int left  = x > 1 ? a[x-1][y] : -1;
  int right = x < c ? a[x+1][y] : -1;
  dp[x][y]  = 1;
  if(a[x][y] > up && a[x][y] > down && a[x][y] > left && a[x][y] > right)
    return dp[x][y];
  if(a[x][y] < up   ) dp[x][y] = max(dp[x][y], memo(x, y-1));
  if(a[x][y] < down ) dp[x][y] = max(dp[x][y], memo(x, y+1));
  if(a[x][y] < left ) dp[x][y] = max(dp[x][y], memo(x-1, y));
  if(a[x][y] < right) dp[x][y] = max(dp[x][y], memo(x+1, y));
  return ++dp[x][y];
}

int main()
{
  scanf("%d%d", &r, &c);
  for(int i = 1; i <= r; i++)
    for(int j = 1; j <= c; j++)
      scanf("%d", &a[j][i]);

  for(int i = 1; i <= r; i++)
    for(int j = 1; j <= c; j++)
      ans = max(ans, memo(j, i));

  printf("%d", ans);
  return 0;
}