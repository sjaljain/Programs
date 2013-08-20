#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int dp[2][205] , n;
struct mm
{
int num, sign;
}a[205];
int main()
{
int n;
while(scanf("%d",&n) == 1)
{
   int i , j,k ;
   for(i = 0 ;i < n ;i ++)
   {
    scanf("%d%d",&a[i].num,&a[i].sign);
   }
   memset(dp[0],0,sizeof(dp));
   dp[0][0] = 1;
   int now = 0 ;
   for(i = 0 ;i < n ; i ++)
    for(j = 1; j <= a[i].num; j ++)
    {
     for(k = 0 ; k <= 200 ;k ++)
     {
      if(dp[now][k])
      {
       if(k + a[i].sign <= 200)
       {
        dp[now^1][k + a[i].sign] = 1;
       }
       if(k - a[i].sign >= 0)
        dp[now^1][k - a[i].sign] = 1;
       else
        dp[now^1][a[i].sign - k] = 1;
      }
     }
     for(int p=0;p<=1;p++)
       {
	 for(int q=0;q<205;q++)
	   {
	     cout<<dp[p][q]<<" ";
	   }
	 cout<<endl;
	 }
     for(k = 0 ;k <= 200 ;k ++)
      dp[now][k] = 0 ;
     now = now^1;

     
    }



   for(k = 0 ;k <= 200 ;k ++)
   {
    if(dp[now][k])
    {
     printf("%d\n",k);
     break;
    }
   }
}
return 0 ;
}
