#include "stdio.h"
int n, t = 1;

int main()
{
  scanf("%d", &n);
  for (register int i = 1; i <= n * n; i++)
  {
    if (i < 10)
      printf("0%d", i);
    else
      printf("%d", i);
    if (i % n == 0)
      printf("\n");
  }

  printf("\n");
  for (int i = 1; i <= n; i++)
  {
    for (register int j = 1; j <= n - i; j++)
      printf("  ");
    while (t <= i * (i + 1) / 2)
    {
      if (t < 10)
        printf("0%d", t);
      else
        printf("%d", t);
      t++;
    }
    printf("\n");
  }
}