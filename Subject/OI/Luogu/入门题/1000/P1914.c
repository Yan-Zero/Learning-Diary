#include "stdio.h"

int offest;
char ch[100];

int main()
{
  scanf("%d", &offest);
  scanf("%s", &ch);
  int i = 0;
  while(ch[i])
  {
    ch[i] -= 'a';
    ch[i] += offest;
    ch[i] %= 26;
    ch[i] += 'a';
    ++i;
  }
  printf("%s", ch);
  return 0;
}
