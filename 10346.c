#include<stdio.h>
#include<math.h>

int main()
{
  int i,n,k,sum,tem;
  for(;scanf("%d",&n) != EOF;)
  {
    sum = n;
    scanf("%d",&k);
    for(;;)
    {
      sum += n/k;
      if(n/k == 0)
      {
        break;
      }
      n = (n - (n/k)*(k-1) );

    }
    printf("%d\n",sum);
  }
  return 0;
}
