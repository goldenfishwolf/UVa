#include<stdio.h>

void tree(int inorder[], int postorder[],int start, int end, int ans[], int& p)
{
  if(start > end)
  {
    ans[0] = -1;
    ans[1] = -1;
    return;
  }
  int i,j, value, leaf,root;
  root = postorder[p];
  p--;
  if(start == end)
  {
    ans[0] = inorder[end];
    ans[1] = inorder[end];
    return;
  }
  
  /*for(i = end-1; i >= 0 ; i--)
  {
    if(postorder[i] != -1)
    {
      root = postorder[i];
      postorder[i] = -1;
      break;
    }
  }*/
  
  for(i = start; i <= end; i++)
  {
    if(inorder[i] == root)
    {
      tree(inorder, postorder, i+1, end, ans,p);//right
      leaf = ans[0];
      value = ans[1];
      tree(inorder, postorder, start, i-1, ans,p);//left
      if(leaf == -1)
      {
        ;//only left
      }
      else if(ans[0] == -1)
      {
        ans[0] = leaf;//only right
        ans[1] = value;
      }
      else
      {
        //have left and right
        if(ans[1] < value)
        {
          ;
        }
        else if(ans[1] > value)
        {
          ans[1] = value;
          ans[0] = leaf;
        }
        else
        {
          if(leaf < ans[0])
          {
            ans[0] = leaf;
          }
        }
      }

      ans[1] += root;
      break;
    }
  }
}

int main()
{
  int i,j,n,m;
  int flag = 0, next_flag = 0;
  int tem;
  int inorder[10001];
  int postorder[10001];
  int ans[2];
  for(i = 0; i < 10001; i++)
  {
    inorder[i] = 0;
    postorder[i] = 0;
  }
  for(i = 0; i < 2; i++)
  {
    ans[i] = -1;
  }
  for(i = 0, n = -1; ; i++)
  {
    if(scanf("%d",&tem) != EOF)
    {
      for(j = 0; j < i; j++)
      {
        if(flag)
        {
          if(n == i)
          {
            flag = 0;
            next_flag = 1;
            break;
          }
        }
        else
        {
          if(tem == inorder[j])
          {
            //printf("%d%d\n",i,tem);
            n = i;
            i = 0;
            flag = 1;
            break;
          }
        }
      }
    }
    else
    {
      m = n-1;
      tree(inorder, postorder, 0, n-1, ans,m);
      printf("%d\n",ans[0]);
      for(j = 0; j < 2; j++)
      {
        ans[j] = -1;
      }
      break;
    }
    
    if(next_flag)
    {
      m = n-1;
      tree(inorder, postorder, 0, n-1, ans,m);
      next_flag = 0;
      printf("%d\n",ans[0]);
      i = 0;
      for(j = 0; j < n; j++)
      {
        inorder[j] = 0;
        postorder[j] = 0;
      }
      n = -1;
    }
    if(flag)
    {
       postorder[i] = tem;
    }
    else
    {
      inorder[i] = tem;
     }
  }
  return 0;
}
