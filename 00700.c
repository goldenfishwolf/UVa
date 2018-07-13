#include<stdio.h>
#include<stdlib.h>
int main()
{
  int n,i,j,x,ans,tem, N, flag;
  int com[21][3];
  int temp[21];

  for(N = 1;; N++)
  {
    scanf("%d",&n);
    if(n == 0)
    {
      break;
    }
    ans = 0;
    for(i = 0; i < n; i++)
    {
      scanf("%d",&com[i][0]);
      scanf("%d",&com[i][1]);
      scanf("%d",&com[i][2]);
    }
    for(i = 0; ans < 10000; i++)
    {
      ans = com[0][0] + (com[0][2] - com[0][1])* i;
      flag = 0;
      for(j = 1; j < n ; j++)
      {
        if(ans-com[j][0] < 0)
        {
          flag = 1;
          break;
        }
        if((ans-com[j][0]) % (com[j][2]-com[j][1]) != 0)
        {
          flag = 1;
          break;
        }
      }
      if(flag == 0)
      {
        break;
      }
    }
    printf("Case #%d:\n", N);
    if(ans >= 10000)
    {
      printf("Unknown bugs detected.\n");
    }
    else
    {
      printf("The actual year is %d.\n",ans);
    }
    printf("\n");
  }
  printf("\n");
  return 0;
}
