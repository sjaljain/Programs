#include<iostream>
#include<stdio.h>

int main()
{
  int T;scanf("%d",&T);while(T--){
    long long int a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    long long int ans=a;
    ans*=a;
    ans-=2*b;
    printf("%lld\n",ans);
  }
  return 0;
}
