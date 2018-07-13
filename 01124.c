#include<stdio.h>

int main()
{
  int i = 0;
  char c;
  for(;scanf("%c",&c) != EOF;)
  {
    printf("%c",c);
  }
  return 0;
}
