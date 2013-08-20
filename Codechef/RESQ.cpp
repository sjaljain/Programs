#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{
		int T;int N,i;
		scanf("%d",&T);
		while(T--)
		{
			scanf("%d",&N);
			for(i=sqrt(N);i>=1;i--)
				if(N%i==0) break;
			printf("%d\n",(N/i)-i);
		}
		return 0;
}

