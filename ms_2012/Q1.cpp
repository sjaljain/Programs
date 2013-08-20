#include<stdio.h>
int foo(int i)
{


static int sum=0;
printf("%d - ",sum);
if(i==5)
{
return sum;
}
else
{
sum+=i;
i++;
return foo(i);
}}
main()
{
//int x=foo(3);
int x=0;
int y=foo(1);
printf("%d %d",y,x);
}
