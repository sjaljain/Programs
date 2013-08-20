#include<stdio.h>

int main()
{
 int N;
 scanf("%d",&N);
 int sum=0;
 int x;
 for(int i=0;i<N;i++)   {scanf("%d",&x);sum+=x;}
 printf("%d",sum);
 
 return 0;
}
