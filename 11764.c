#include <stdio.h>

int main()
{
  int i,n,j,m,w,tem,h,l;
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++)
  {
    scanf("%d",&m);
    h = 0;
    l = 0;
    if(m == 1)
    {
      scanf("%d",&tem);
    }
    else
    {
      scanf("%d",&tem);
      for(j = 1; j < m; j++)
      {
        scanf("%d",&w);
        if(w > tem)
        {
          h++;
        }
        else if(w < tem)
        {
          l++;
        }
        tem = w;
      }
    }
    printf("Case %d: %d %d\n",i+1,h,l);
  }
  return 0;
}
