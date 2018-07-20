#include<stdio.h>
void print(int map[][4])
{
  int i, j, n, m;
printf("\n");
  for(i = 0; i < 4; i++)
  {
    for(j = 0; j < 4; j++)
    {
      printf("%d",map[i][j]);
    }
    printf("\n");
  }printf("\n");
}
int check(int map[][4])
{
  int i, j;
  for(i = 0; i < 4; i++)
  {
    if(map[0][i] == 2)
    {
      if((map[0][0]==2 && map[0][1]==2 && map[0][2]==2 && map[0][3]==2)||
        (map[0][i]==2 && map[1][i]==2 && map[2][i]==2 && map[3][i]==2)||
        (map[0][0]==2 && map[1][1]==2 && map[2][2]==2 && map[3][3]==2)||
        (map[0][3]==2 && map[1][2]==2 && map[2][1]==2 && map[3][0]==2))
        {
          return 1;
        }
    }
    if(map[i][0] == 2)
    {
      if((map[0][0]==2 && map[1][0]==2 && map[2][0]==2 && map[3][0]==2)||
        (map[i][0]==2 && map[i][1]==2 && map[i][2]==2 && map[i][3]==2)||
        (map[0][0]==2 && map[1][1]==2 && map[2][2]==2 && map[3][3]==2)||
        (map[0][3]==2 && map[1][2]==2 && map[2][1]==2 && map[3][0]==2))
        {
          return 1;
        }
    }
  }
  return 0;
}

int O(int map[][4],int xy[])
{
  int i, j, n, m;
  for(i = 0; i < 4; i++)
  {
    for(j = 0; j < 4; j++)
    {
      if(map[i][j] == 0)
      {
        map[i][j] = 2;
        n = check(map);
        if(n == -1)
        {
          ;
        }
        if(X(map,xy))
      }
    }
  }
  return check(map);
}

int X(int map[][4], int xy[])
{
  int i, j, n, m, flag = 0;
  for(i = 0; i < 4; i++)
  {
    for(j = 0; j < 4; j++)
    {
      if(map[i][j] == 0)
      {
        map[i][j] = 2;
        for(n = 0; n < 4; n++)
        {
          for(m = 0; m < 4; m++)
          {
            if(map[n][m] == 0)
            {
              map[n][m] = 1;
              if(all(map) == 0)
              { 
                print(map);
                flag = 1;
              }
              map[n][m] = 0;
              if(flag)break;
            }
          }
          if(flag)break;
        }
        if(flag == 0)
        {
          xy[0] = i;
          xy[1] = j;
          return 1;
        }
        map[i][j] = 0;
      }
    }
  }
  return 0;
}

int main()
{
  int i,j,m,n;
  int map[4][4];
  int xy[2];
  char c;

  for(;;)
  {
    scanf("%c",&c);
    if(c == '$')
    {
      break;
    }
    scanf("%c",&c);
    xy[0] = -1;
    for(i = 0; i < 4; i++)
    {
      for(j = 0; j < 4; j++)
      {
        scanf("%c",&c);
        switch(c)
        {
          case '.':
            map[i][j] = 0;
            break;
          case 'o':
            map[i][j] = 1;
            break;
          case 'x':
            map[i][j] = 2;
            break; 
        }
      }
      scanf("%c",&c);
    }

    if(ans(map,xy) == 1)
    {
      printf("(%d,%d)\n",xy[0],xy[1]);
    }
    else
    {
      printf("#####\n");
    }
  }
  return 0;
}
