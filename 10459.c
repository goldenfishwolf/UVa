#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b

int compare(const void *arg1, const void *arg2) {
  return  (*(int *)arg1 - *(int *)arg2);
}


int find_height(int** tree,int* up,int* down, int num, int root)
{
  int i, j, m, n = -1;
  for(i = 0; i < num; i++)
  {
    if(tree[root][i] != 0)
    {
      tree[i][root] = 0;
      up[i] = up[root] + 1;
      m = find_height(tree, up, down, num, i);
      tree[i][root] = 1;
      if(m > n) n = m;
    }
  }
  n++;
  down[root] = n;
  return n;
}

void Ans(int** tree, int num)
{
  int i, j, k, l, m ,n ,flag , tem = -1;
  int* rmax = (int*)malloc(sizeof(int)*num);
  int* rmin = (int*)malloc(sizeof(int)*num);
  int* up = (int*)malloc(sizeof(int)*num);
  int* down = (int*)malloc(sizeof(int)*num);
  for(i = 0; i < num; i++)
  {
    up[i] = 0;
    rmax[i] = -1;
    rmin[i] = -1;
  }
  up[0] = 0;
  find_height(tree,up,down,num,0);
  for(i = 0; i < num; i++)
  {
    tem = MAX(tem,up[i]);
  }
  for(i = 0, j = 0; i < num; i++)
  {
    if(up[i] == tem)
    {
      rmax[j] = i;
      j++;
      break;
    }
  }
    tem = -1;
    up[rmax[0]] = 0;
    find_height(tree,up,down,num,rmax[0]);
    for(i = 0; i < num; i++)
    {
      tem = MAX(tem,up[i]);
    }
    for(i = 0; i < num; i++)
    {
      if(up[i] == tem)
      {
        for(m = 0, flag = 0; m < j; m++)
        {
          if(rmax[m] == i)
          {
            flag = 1;
            break;
          }
        }
        if(!flag)
        {
          rmax[j] = i;  
          j++;
        }
      }
    }
    for(i = 0, n = 0; i < num; i++)
    {
      if(down[i] == (tem+1)/2 || down[i] == tem/2)
      {
        rmin[n] = i;
        n++;
      }
    }
  l=j;
  for(k = 1; k < l; k++)
  {
    tem = -1;
    up[rmax[k]] = 0;
    find_height(tree,up,down,num,rmax[k]);
    for(i = 0; i < num; i++)
    {
      tem = MAX(tem,up[i]);
    }
    for(i = 0; i < num; i++)
    {
      if(up[i] == tem)
      {
        for(m = 0, flag = 0; m < j; m++)
        {
          if(rmax[m] == i)
          {
            flag = 1;
            break;
          }
        }
        if(!flag)
        {
          rmax[j] = i;  
          j++;
        }
      }
    }

  }

  printf("Best Roots  :");

  qsort((void*)rmin,n,sizeof(int),compare);
  for(i = 0; i < n; i++)
  {
    printf(" %d",rmin[i]+1);
  }
  
  printf("\nWorst Roots :");
  qsort((void*)rmax,j,sizeof(int),compare);
  for(i = 0; i < j; i++)
  {
    printf(" %d",rmax[i]+1);
  }
  printf("\n");
  free(rmax);
  free(rmin);
  free(up);
  free(down);
}


int main()
{
  int i,j;
  int n,m,u,v;
  int** tree;
  for(;scanf("%d",&n) != EOF;)
  {
    tree = (int**)malloc(sizeof(int*)*n);
    for(i = 0; i < n; i++)
    {
      tree[i] = (int*)malloc(sizeof(int)*n);
    }
    for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
      {
        tree[i][j] = 0;
      }
    }
    for(i = 0; i < n; i++)
    {
      scanf("%d",&m);
      for(j = 0; j < m; j++)
      {
        scanf("%d",&u);
        tree[i][u-1] = 1;
      }
    }
    Ans(tree,n);
    for(i = 0; i < n; i++)
    {
      free(tree[i]);
    }
    free(tree);
  }
  return 0;
}

