#include<stdio.h>

int main()
{
 int N;
 scanf("%d",&N);
 int sum=0;
 int x,i;
 for(i=0;i<N;i++)   {scanf("%d",&x);sum+=x;}
 printf("%d\n",sum);
 
 return 0;
}
