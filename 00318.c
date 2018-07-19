#include<stdio.h>

void domino(int map[][501], int n, int now, float time, int key1, int key2)
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

void ans(int map[][501], int n)
{
  int num = n;
  int d[501];
  int i,j,k;
  for(i = 0; i < 501; i++)
  {
    d[i] = -1;
  }
  d[0] = 0;
  for(; num > 0;)
  {
    for(i = 0; i < 501; i++)
    {
      if(d[i] != -1)
      {
        for(j = 0; j < n; j++)
        {
          if(map[d[i]][j] > 0)
          {
            map[d[i]][j] -= 5;
            map[j][d[i]] -= 5;
          }
        }
      }
    }
  }
}

int main()
{
  int n,m,i,j,k,l,x,y,tem;
  int map[501][501];
  int temp[2][501];
  int sec_flag;
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
    sec = 0.0;
    for(l = 0;;)
    {
      sec_flag = 0;
      for(i = 0, j = 0; temp[l][i] != -1; i++, j++)
      {
        if(map[temp[l][i]][j] >= 0.5)
        {
          map[temp[l][i]][j] -= 0.5;
          map[j][temp[l][i]] -= 0.5;
          sec_flag = 1;
          if(map[temp[l][i]][j] == 0)
          {
            temp[i] = -1;
          }
        }
      }
      if(sec_flag == 1)
      {
        sec += 0.5;
      }
      for(i = 0, j = 0; ; i++)
      {
        if(temp[l][i] != -1)
        {
          if(l == 1)
          {
            temp[0][j] = temp[l][i];
          }
          else
          {
            temp[1][j] = temp[l][i];
          }
        }
      }
      if(l == 0)
      {
        l = 1;
      }
      else
      {
        l = 0;
      }
    }
  }
  return 0;
}
