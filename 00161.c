#include<stdio.h>

int main()
{
  int i, j,k,l,ans,temp,flag;
  int bound = 5*60*60 + 1;
  int light[101] = {0};
  int tem[101] = {0};
  for(;;)
  {
    for(i = 0; i < 3 || light[i-1] != 0; i++)
    {
      scanf("%d",&light[i]);
    }
    if(light[0] == 0 && light[1] == 0 && light[2] == 0)
    {
      break;
    }
    for(j = 0;j < i-1; j++)
    {
      for(k = 1;; k++)
      {
        temp = light[j] * 2 * k;
        if(temp > bound)
        {
          tem[j] = -1;
          break;
        }
        flag = 0;
        for(l = 0; l < i-1; l++)
        {
          if(temp%(light[l]*2) >= light[l] - 5)
          {
            flag = 1;
          }
        }
        if(flag == 0)
        {
          tem[j] = temp;
          break;
        }
      }
    }
    ans = bound;
    for(l = 0; l < i-1; l++)
    {
      if(tem[l] < ans && tem[l] != -1)
      {
        ans = tem[l];
      }
    }
    if(ans == bound)
    {
      printf("Signals fail to synchronise in 5 hours\n");
    }
    else
    {
      printf("%.2d:%.2d:%.2d\n",ans/3600,(ans-(ans/3600)*3600)/60,ans%60);
    }
  }
  return 0;
}
