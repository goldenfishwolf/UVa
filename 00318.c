#include<stdio.h>

void domino(int map[][501], int n, int now, float time, int key1,int key2)
{
  int i;
  for(i = 0; i < n; i++)
  {
    if(map[now][i] != -1)
    {
      ;
    }
  }
}

int main()
{
  int n,m,i,j,x,y,tem;
  int map[501][501];
  int temp[501];
  float sec;
  for(;;)
  {
    scanf("%d%d",&n,&m);
    if(n == 0 && m == 0)
    {
      break;
    }
    for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
      {
        map[i][j] = -1;
      }
    }
    for(i = 0; i < m; i++)
    {
      scanf("%d%d%d",&x,&y,&tem);
      map[x][y] = tem;
      map[y][x] = tem;
    }
    for(;;)
    {
      ;
    }
  }
  return 0;
}
