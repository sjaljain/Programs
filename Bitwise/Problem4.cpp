#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define mod 1000000007
#define MAXN 1000010

typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long int LL;

//copy both the functions
//dimension of matrix: 3
// matrix_mul(a,b,c): multiplies matrix a with b and puts the result in c
// matrix_expo(a,4,c): calculates a^4 and puts in c

LL mypow(LL a, LL n)
{
	LL r = 1;
	for(;n;n>>=1)
	{
		if(n&1) r = (r*a)%mod;
		a = (a*a)%mod;
	}
	return r;
}

void matrix_mul(LL a[4][4],LL b[4][4],LL c[4][4])
{
	REP(i,4)
		REP(j,4)
		{
			c[i][j]=0;
			REP(k,4)
			{
				LL temp=a[i][k]*b[k][j];
				if(temp>=mod)
					temp%=mod;
				c[i][j]+=temp;
				if(c[i][j]>=mod)
					c[i][j]%=mod;
			}
		}
}

LL id[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};

void matrix_expo(LL a[4][4], LL n,LL h[4][4])
{
	if(n==1)
	{
		REP(i,4)
			REP(j,4)
				h[i][j]=a[i][j];
		return;
	}
	else if(n==0)
	{
		REP(i,4)
			REP(j,4)
				h[i][j]=id[i][j];
		return;
	}

	LL c[4][4];
	LL x[4][4];

	matrix_expo(a,n/2,x);
	matrix_mul(x,x,c);

	if(n%2==1)
	{
		matrix_mul(a, c, h);
		return;
	}
	else
	{
		REP(i,4)
			REP(j,4)
				h[i][j]=c[i][j];
		return;
	}
}


int main(){

	int t;
	scanf("%d",&t);
	while(t--)
	{
		LL a[4][4]={{1,2,3,1},{1,0,0,0},{0,1,0,0},{0,0,1,0}};
		LL b[4][4];

		LL n;
		scanf("%lld",&n);
		if(n<=4)
		{
			if(n==1)
				printf("1\n");
			else if(n==2)
				printf("2\n");
            else if(n==3)
                printf("5\n");
			else
				printf("12\n");

		}
		else
		{
			matrix_expo(a,n-4,b);
			//cout<<b[0][0]<<" "<<b[0][1]<<" "<<b[0][2]<<" "<<b[0][3]<<endl;
			LL ans = 12*b[0][0] + 5*b[0][1] + 2*b[0][2]+1*b[0][3];
            cout<<ans%mod<<endl;

//			if(ans>=mod)
//				ans%=mod;
//			LL final=mypow(2LL,n);
//			final=final-ans;
//			while(final<0)
//				final+=mod;
			//printf("%lld\n",ans);
		}


	}
	return 0;
}
