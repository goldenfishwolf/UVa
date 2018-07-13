#include<stdio.h>
#include<stdlib.h>

void walk(int map[][101],int x, int y, int R, int C, int M, int N, int& e, int& o)
{
  map[x][y] = 1;
  int sum = 0;
  if(x + M < R && y + N < C && map[x+M][y+N] != 2)
  {
    sum++;
    if(map[x+M][y+N] == 0)walk(map,x+M, y+N, R, C, M, N, e, o);
  }
  if(M != 0 && x - M >= 0 && y + N < C && map[x-M][y+N] != 2)
  {
    sum++;
    if(map[x-M][y+N] == 0)walk(map,x-M, y+N, R, C, M, N, e, o);
  }
  if(N != 0 && x + M < R && y - N >= 0 && map[x+M][y-N] != 2)
  {
    sum++;
    if(map[x+M][y-N] == 0)walk(map,x+M, y-N, R, C, M, N, e, o);
  }
  if(M != 0 && N != 0 && x - M >= 0 && y - N >= 0 && map[x-M][y-N] != 2)
  {
    sum++;
    if(map[x-M][y-N] == 0)walk(map,x-M, y-N, R, C, M, N, e, o);
  }
  if(N != M)
  {
    if(x + N < R && y + M < C && map[x+N][y+M] != 2)
    {
      sum++;
      if(map[x+N][y+M] == 0)walk(map,x+N, y+M, R, C, M, N, e, o);
    }
    if(N != 0 && x - N >= 0 && y + M < C && map[x-N][y+M] != 2)
    {
      sum++;
      if(map[x-N][y+M] == 0)walk(map,x-N, y+M, R, C, M, N, e, o);
    }
    if(M != 0 && x + N < R && y - M >= 0 && map[x+N][y-M] != 2)
    {
      sum++;
      if(map[x+N][y-M] == 0)walk(map,x+N, y-M, R, C, M, N, e, o);
    }
    if(M != 0 && N != 0 && x - N >= 0 && y - M >= 0 && map[x-N][y-M] != 2)
    {
      sum++;
      if(map[x-N][y-M] == 0)walk(map,x-N, y-M, R, C, M, N, e, o);
    }
  }
  if(sum % 2 == 0)
  {
    e++;
  }
  else
  {
    o++;
  }
}

int main()
{
  int i,j,k,n,e,o,R,C,M,N,W,x,y;
  int map[101][101];
  scanf("%d",&n);
  for(i = 0; i < n; i++)
  {
    e = 0;
    o = 0;
    for(j = 0; j < 101; j++)
    {
      for(k = 0; k < 101; k++)
      {
        map[j][k] = 0;
      }
    }
    scanf("%d",&R);
    scanf("%d",&C);
    scanf("%d",&M);
    scanf("%d",&N);
    scanf("%d",&W);
    for(j = 0; j < W; j++)
    {
      scanf("%d",&x);
      scanf("%d",&y);
      map[x][y] = 2;
    }
    walk(map,0,0,R,C,M,N,e,o);
    printf("Case %d: %d %d\n",i+1,e,o);
  }
  return 0;
}
