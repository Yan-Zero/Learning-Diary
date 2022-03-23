#include "stdio.h"
#include "string.h"

int n, c[22], dp[22], ans = 1;
char link[212], list[22][23];

int memo(int d)
{
  if(dp[d]) return dp[d];
  int from = 0;
  for(int i = 1, y = 0; i < d; ++i)
  {
    y += n - i;
    if(link[y+d-n] && memo(i) > dp[d])
    { from = i; dp[d] = memo(i); }
  }
  dp[d] += c[d];
  memcpy(list[d], list[from], sizeof(int) * 23);
  list[d][++list[d][0]] = d;
  return dp[d];
}

int main()
{
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%d", &c[i]);
  for(int i = 1; i <= n * (n - 1) / 2; ++i)
    scanf("%d", &link[i]);

  dp[1] = c[1]; list[1][0] = list[1][1] = 1;
  for(int i = 1; i <= n; ++i)
    if(memo(i) > memo(ans))
      ans = i;
  printf("%d", list[ans][1]);
  for(int i = 2; i <= list[ans][0]; ++i)
    printf(" %d", list[ans][i]);

  printf("\n%d", dp[ans]);

  return 0;
}
