#include<stdio.h>

int main()
{
  int i = 0;
  char c;
  for(;scanf("%c",&c) != EOF;)
  {
    if(c == '\"')
    {
      if(i%2 == 0)
      {
        printf("``");
      }
      else
      {
        printf("''");
      }
      i++;
      
    }
    else
    {
    printf("%c",c);
    }
  }
  return 0;
}
