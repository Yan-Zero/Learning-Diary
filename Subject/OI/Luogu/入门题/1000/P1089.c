#include "stdio.h"
int n, t, d;
int main()
{
  for(register int i = 0; i < 12; i++)
  {
    scanf("%d", &n);
    if(d + 300 < n)
    {
      printf("-%d", i+1);
      return 0;
    }
    d = d + 300 - n;
    t += d / 100;
    d = d % 100;
  }
  t *= 120;
  printf("%d", t + d);

  return 0;
}
