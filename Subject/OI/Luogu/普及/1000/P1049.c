#include "stdio.h"
#include "string.h"
#define _max(a, b) ((a)>(b)?(a):(b))
int v, n, c[32], dp[20002];

int main()
{
  scanf("%d", &v);
  scanf("%d", &n);
  for(int i = 0; i < n; scanf("%d", &c[++i]));

  for(int i = 1; i <= n; ++i)
    for(int j = v; j >= c[i]; --j)
      dp[j] = _max(dp[j], dp[j - c[i]] + c[i]);

  printf("%d", v - dp[v]);

  return 0;
}
