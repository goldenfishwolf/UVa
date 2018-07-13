#include<stdio.h>
#include<math.h>

int main()
{
  int i, j, N, n ,m, ans, tem, temp;
  scanf("%d",&N);
  for(i = 0; i < N; i++)
  {
    ans = 0;
    scanf("%d",&n);
    scanf("%d",&m);
    for(j = 0; j < n; j++)
    {
      tem = m%(int)pow(2,j+2);
      if(tem < (int)(pow(2,j+2)-pow(2,j)) && tem >= (int)pow(2,j))
      {
        ans += (int)pow(2,j);
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}
