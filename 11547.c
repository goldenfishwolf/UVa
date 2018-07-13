#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i,n,t;
  scanf("%d",&n);
  for(i = 0; i < n ;i++)
  {
    scanf("%d",&t);
    printf("%d\n",abs((((t*567/9 + 7492) * 235/47 - 498)%100) /10) );
  }
  return 0;
}
