#include<stdio.h>

int main()
{
  int M,N,K,n,i,j,k,l,m,ans;
  int coin[101];
  int tem[101];
  for(i = 0; i < 101; i++)
  {
    coin[i] = 0;
    tem[i] = 0;
  }
  char c;

  scanf("%d",&M);
  for(i = 0; i < M; i++)
  {
    scanf("%d",&N);
    scanf("%d",&K);
    for(j = 0 ; j < K ;j++)
    {
      scanf("%d",&n);
      for(k = 0; k < 2*n; k++)
      {
        scanf("%d",&tem[k]);
      }
      scanf("%c",&c);
      scanf("%c",&c);
      switch(c)
      {
        case '<':
        case '>':
          for(k = 0; k < N; k++)
          {
            m = 0;
            for(l = 0; l < 2*n; l++)
            {
              if(k+1 == tem[l])
              {
                m = 1;
                break;
              }
            }
            if(m == 0)
            {
              coin[k] = 1;
            }
          }         
          break;
        case '=':
          for(l = 0; l < 2*n; l++)
          {
            coin[tem[l] - 1] = 1;
          }
          break;
      }
    }

    ans = 0;

    for(j = 0; j < N; j++)
    {
      if(coin[j] == 0)
      {
        if(ans != 0)
        {
          ans = 0;
          break;
        }
        ans = j+1;
      }
    }
    
    for(j = 0; j < 101; j++)
    {
      coin[j] = 0;
      tem[j] = 0;
    }
    printf("%d\n",ans);
    if(i != M-1)
    {
      printf("\n");
    }
  }
 
  return 0;
}
