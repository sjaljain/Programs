#include<stdio.h>

int main()
{

long long x; int ans=(char*)(&x+1) - (char*)(&x);
printf("%d",ans);
}
