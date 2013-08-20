#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
int T;
scanf("%d",&T);
while(T--)
{
int X,Y;
scanf("%d%d",&X,&Y);
if(X==0 || Y==0)continue;
printf("%d\n",(X/2)+(Y/2)+1);
}
return 0;
}
