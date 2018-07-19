#include<stdio.h>
#include<stdlib.h>
FILE *f;

void printdp(int dp[][81],int n,int m)
{int i,j;
 for(i = 0;i<n;i++)
{
 for(j=0;j<m;j++){printf("%d ",dp[i][j]);}
printf("\n");
}

}

int trans(char s[], char t[], int dp[][81], int n, int m)
{
  if(n == 0 || m == 0)
  {
    dp[n][m] = n+m;
    return n+m;
  }

  if(s[n-1] == t[m-1])
  {
    dp[n][m] = trans(s,t,dp,n-1,m-1);
  }
  else
  {
    int i,r,d;
    i = trans(s,t,dp,n,m-1);
    r = trans(s,t,dp,n-1,m-1);
    d = trans(s,t,dp,n-1,m);
    if(d <= r && d <= i)
    {
      dp[n][m] = d + 1;
    }
    else if(r <= i && r <= d)
    {
      dp[n][m] = r + 1;
    }
    else
    {
      dp[n][m] = i + 1;
    }
  }
  return dp[n][m];
}

void print_ans(char s[], char t[], int dp[][81], int n, int m, int& step,int &slen)
{
  int i;
  if(n == 0)
  {
    for(i = 0; i < m; i++)
    {
      printf("%d Insert %d,%c\n",step,i+1,t[i]);
      step++;
    }
    slen = m+1;
    return;
  }
  if(m == 0)
  {
    for(i = 0; i < n; i++)
    {
      printf("%d Delete 1\n",step);
      step++;
    }
    slen = 1;
    return;
  }
  if(s[n-1] == t[m-1])
  {
    print_ans(s,t,dp,n-1,m-1,step,slen);
    slen++;
  }
  else if(dp[n][m] == dp[n-1][m] + 1)
  {
    print_ans(s,t,dp,n-1,m,step,slen);
    printf("%d Delete %d\n",step,slen);
    slen--;
    step++;
  }
  else if(dp[n][m] == dp[n-1][m-1] + 1)
  {
    print_ans(s,t,dp,n-1,m-1,step,slen);
    printf("%d Replace %d,%c\n",step,slen,t[m-1]);
    slen++;
    step++;
  }
  else if(dp[n][m] == dp[n][m-1] + 1)
  {
    print_ans(s,t,dp,n,m-1,step,slen);
    printf("%d Insert %d,%c\n",step,slen,t[m-1]);
    slen++;
    step++;
  }
}

void Ans(char s[], char t[],int dp[][81], int n, int m)
{
  int step = 1, slen = 0;
  printf("%d\n",trans(s,t,dp,n,m));
  print_ans(s,t,dp,n,m,step,slen);
}


int main()
{
  int i,j,m,n;
  char s[81],t[81];
  int dp[81][81];
  char c;f = fopen("test","w");
  for(;;)
  {
    for(i = 0; i < 82; i++)
    {
      if(scanf("%c",&c) == EOF)
      {
        return 0;
      }
      if(c == '\n')
      {
        break;
      }
      s[i] = c;
    }
    s[i] = '\0';

    for(j = 0; j < 82; j++)
    {
      if(scanf("%c",&c) == EOF)
      {
        return 0;
      }
      if(c == '\n')
      {
        break;
      }
      t[j] = c;
    }
    t[j] = '\0';
    for(m = 0; m < i+1; m++)
    {
      for(n = 0; n < j+1; n++)
      {
        dp[m][n] = -1;
      }
    }
    //printf("%d\n%d\n",i,j);
    Ans(s,t,dp,i,j);
    printf("\n");
  }
  return 0;
}
