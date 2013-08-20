#include<iostream>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>


using namespace std;

#define MAX 5001
int DP[ MAX ][ 2 ];
 

int main()
{
 int T;
 cin>>T;
 while(T--)
 {
           string s;
           cin>>s;
           for(int i=0;i<MAX;i++){DP[i][0]=0;DP[i][1]=0;}
           int L=s.size()-1;
           for(int j=0;j<=L;j++)
	       	{
		    	for(int i=j;i>=0;i--)
			    {
				if(s[i] == s[j])
					DP[i][1] = DP[i+1][0];
				else
					DP[i][1] = min(DP[i+1][1],DP[i][0])+1;
                 }
                 for(int i=0;i<=L;i++)
                 DP[i][0]=DP[i][1];
                 
		     }
           cout<<DP[0][1]<<endl;
}
 return 0;
}
