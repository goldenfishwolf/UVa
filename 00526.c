#include<stdio.h>
#include<stdlib.h>


int dp[81][81];
int redp[81][81];
char s[81];
char t[81];
int n,m,step;


void print(int d[][81],int n,int m)
{
int i,j;
for(i = 0 ; i <= n; i++)
{
for(j = 0; j <= m; j++)
{
printf("%d ",d[i][j]);
}
printf("\n");
}

}


int min(int a,int b)
{
  return a<b?a:b;
}

int trans(int x,int y)
{


  if(x == n)
  {
    return m-y;
  }
  if(y == m)
  {
    return n-x;
  }
  if(s[x] == t[y])
  {
    dp[x][y] = trans(x+1,y+1);
    redp[x][y] = 0;
  }
  else
  {
    int i,d,r;
    r = trans(x+1,y+1);
    d = trans(x+1,y);
    i = trans(x,y+1);


    dp[x][y] = min(min(i,d),r) + 1;
    if(dp[x][y] == r + 1)
    {
      redp[x][y] = 3;
    }
    else if(dp[x][y] == d + 1)
    {
      redp[x][y] = 2;
    }
    else
    {
      redp[x][y] = 1;
    }
    
  }
  return dp[x][y];


/*
for(;;)
{
  if(s[x] == t[y])
  {
    dp[x][y] = trans(s,t,dp,redp,x+1,y+1,n,m);
    redp[x][y] = 0;
  }

}*/
/*

  int x,y,tem;
  for(x = 0; x <= n; x++)
  {
    for(y = 0; y <= m; y++)
    {

      if(x == 0 || y == 0)
      {
        dp[x][y] = x+y;
        if(x == 0)
        {
          redp[x][y] = 1;//insert
        }
        else
        {
          redp[x][y] = 2;//delete
        }
        continue;
      }
      if(s[x-1] == t[y-1])
      {
        dp[x][y] = dp[x-1][y-1];
        redp[x][y] = 0;
        continue;
      }
      
      
      dp[x][y] = 1 + min(min(dp[x-1][y],dp[x][y-1]),dp[x-1][y-1]);
      if(dp[x][y] == dp[x][y-1] + 1)
      {
        redp[x][y] = 1;//insert
      }
      else if(dp[x][y] == dp[x-1][y] + 1)
      {
        redp[x][y] = 2;
      }
      else
      {
        redp[x][y] = 3;//replace
      }
      
    }
  }

  return dp[n][m];
*/
}

void print_ans(int x, int y,int slen)
{
  /*if(!x)
  {
    for(i = 0; i < y; i++)
    {
      printf("%d Insert %d,%c\n",step,i+1,t[i]);
      step++;
    }
  }
  if(!y)
  {
    for(i = 0; i < x; i++)
    {
      printf("%d Delete 1\n",step);
      step++;
    }
    return;
  }
  step++;
  switch(redp[x][y])
  {
    case 0:
      step--;
      print_ans(x-1,y-1,step,slen-1);
      break;
    case 1:
      print_ans(x,y-1,step,slen-1);
      printf("%d Insert %d,%c,%d,%d\n",step,slen,t[y-1],x,y);
      break;
    case 2:
      
      print_ans(x-1,y,step,slen-2);
      printf("%d Delete %d\n",step,slen-1);
      break;
    case 3:
      
      print_ans(x-1,y-1,step,slen-1);
      printf("%d Replace %d,%c\n",step,slen,t[y-1]);
      break;
  }*/



  //int i,j,k;
  /*for(i = 0; i < n; i++)
  {
    for(j = 0; j < m; j++)
    {
      if(dp[i][j] == dp[i+1][j+1])
      {
        slen++;
        i++;
      }
    }
  } */ 
  step++;
  if(x >= n)
  {
    for(; y < m; y++,step++)
    {
      printf("%d Insert %d,%c\n",step,y+1,t[y]);
    }
    
    return;
  }
  if(y >= m)
  {
    for(; x < n; x++,step++)
    {
      printf("%d Delete %d\n",step,x);
    }
    return;
  }
  /*if(x == 0)
  {
    for(; y < m; y++)
    {
      printf("%d Insert %d,%c\n",step,y+1,t[y]);
      step++;
    }
    
    return;
  }
  if(y == 0)
  {
    for(; x < n; x++)
    {
      printf("%d Delete %d\n",step,x);
      step++;
    }
    return;
  }  
  if(s[n-1] == t[m-1])
  {
    print_ans(n-1,m-1,step,slen);
    slen++;
  }
  else if(dp[n][m] == dp[n-1][m-1] + 1)
  {
    print_ans(n-1,m-1,step,slen);
    printf("%d Replace %d,%c\n",step,slen,t[m-1]);
    slen++;
    step++;
  }
  else if(dp[n][m] == dp[n][m-1] + 1)
  {
    print_ans(n,m-1,step,slen);
    printf("%d Insert %d,%c\n",step,slen,t[m-1]);
    slen++;
    step++;
  }
  else if(dp[n][m] == dp[n-1][m] + 1)
  {
    print_ans(n-1,m,step,slen);
    printf("%d Delete %d\n",step,slen);
    step++;
  }*/


  if(redp[x][y] == 0)
  {
      step--;
      print_ans(x+1,y+1,slen+1);
  }
  else if(redp[x][y] == 1)
  {
      printf("%d Insert %d,%c\n",step,slen,t[y]);
      print_ans(x,y+1,slen+1);
  }
  else if(redp[x][y] == 2)
  {
    printf("%d Delete %d\n",step,slen);
      print_ans(x+1,y,slen);

  }
  else if(redp[x][y] == 3)
  {
    printf("%d Replace %d,%c\n",step,slen,t[y]);
      print_ans(x+1,y+1,slen+1);
  
  }

}

void Ans()
{
  step = 0;
  printf("%d\n",trans(0,0));//print(dp,n,m);printf("\n\n");print(redp,n,m);
  print_ans(0,0,1);
}


int main()
{
  int i,j;
  char c;
  for(;;)
  {
    for(n = 0; n < 82; n++)
    {
      if(scanf("%c",&c) == EOF)
      {
        return 0;
      }
      if(c == '\n')
      {
        break;
      }
      s[n] = c;
    }
    s[n] = '\0';

    for(m = 0; m < 82; m++)
    {
      scanf("%c",&c);
      if(c == '\n')
      {
        break;
      }
      t[m] = c;
    }
    t[m] = '\0';
    for(i = 0; i < n+1; i++)
    {
      for(j = 0; j < m+1; j++)
      {
        dp[i][j] = -1;
        redp[i][j] = -1;
      }
    }
    //printf("%d\n%d\n",i,j);
      step = 0;
  printf("%d\n",trans(0,0));//print(dp,n,m);printf("\n\n");print(redp,n,m);
  print_ans(0,0,1);
    printf("\n");
  }
  return 0;
}
