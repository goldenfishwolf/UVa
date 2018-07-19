#include<stdio.h>

void ans(int tree[], int start, int end)
{
  int root = tree[start];
  int i,left,right;

  if(start > end)
  {
    return;
  }
  if(start == end)
  {
    printf("%d\n",root);
    return;
  }

  for(i = start + 1; i <= end; i++)
  {
    if(tree[i] > root)// not left
    {
      break;
    }
  }
  ans(tree, start+1, i-1);
  ans(tree, i, end);

  printf("%d\n",root);
}

int main()
{
  int i, j, m, n, tem;
  int tree[10001];
  for(i = 0; i < 10001; i++)
  {
    tree[i] = -1;
  }
  for(i = 0; scanf("%d",&tem) != EOF;i++)
  {
    tree[i] = tem;
  }
  ans(tree,0,i-1);
  return 0;
}
