#include<stdio.h>

int main()
{
  int i,n,a,b,c, tem, avg;
  scanf("%d",&n);
  for(i = 0; i < n; i++)
  {
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    avg = (a+b)/3;
    tem = c * (2*a-b) /(a+b);
    printf("%d\n",tem); 
  }
  return 0;
}
