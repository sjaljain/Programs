#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cassert>
#include <climits>
#include <functional>
#include <bitset>
#define MOD 1000000007
#define dim 4
#define FOR(k,a,b) for(typeof(a) k=(a); k < (b); ++k)
typedef long long  LL;
using namespace std;

struct matrix {
    int a[dim][dim];
};

matrix P[61],t;

matrix mul(matrix x, matrix y)
{
    matrix res;

    FOR(a,0,dim) FOR(b,0,dim) res.a[a][b] = 0;

    FOR(a,0,dim) FOR(b,0,dim) FOR(c,0,dim) {
	res.a[a][c] += ((x.a[a][b]) * LL(y.a[b][c])+MOD) % MOD;
	res.a[a][c] %= MOD;
    }


    return res;
}

int power(LL pow)
{
    matrix num;

    num.a[0][0]=1;
   	num.a[0][1]=0;
   	num.a[0][2]=0;
   	num.a[0][3]=0;

   	num.a[1][0]=0;
   	num.a[1][1]=1;
   	num.a[1][2]=0;
   	num.a[1][3]=0;

   	num.a[2][0]=0;
   	num.a[2][1]=0;
   	num.a[2][2]=1;
   	num.a[2][3]=0;

   	num.a[3][0]=0;
   	num.a[3][1]=0;
   	num.a[3][2]=0;
   	num.a[3][3]=1;


    int i;
    matrix res;
    while(pow!=0)
    {
    	i=(int)log2(pow&~(pow-1));
   		res=mul(num,P[i]);

   		 for(int i=0;i<dim;i++)
    		for(int j=0;j<dim;j++)
        		num.a[i][j]=res.a[i][j]%MOD;

   		pow=pow&(pow-1);
    }
     return ((LL(num.a[0][0])*12)+(LL(num.a[0][1])*5) +(LL(num.a[0][2])*2) +(LL(num.a[0][3])*1))%MOD;
}



void precompute()
{
	matrix res;
	P[0]=P[1]=res=t;
    for(int i=1;i<=60;i++)
    {
        P[i]=res;
    	res=mul(P[i],P[i-1]);
    	P[i]=res;
    	cout<<res.a[0][0]<<" ";
    }
}


int main()
{
    int T;
   	scanf("%d",&T);
   	t.a[0][0]=1;
   	t.a[0][1]=2;
   	t.a[0][2]=3;
   	t.a[0][3]=1;

    t.a[1][0]=1;
   	t.a[1][1]=0;
   	t.a[1][2]=0;
   	t.a[1][3]=0;

   	t.a[2][0]=0;
   	t.a[2][1]=1;
   	t.a[2][2]=0;
   	t.a[2][3]=0;

   	t.a[3][0]=0;
   	t.a[3][1]=0;
   	t.a[3][2]=1;
   	t.a[3][3]=0;

    precompute();

	while(T--)
    {
        LL N;
        scanf("%llu",&N);

        if(N==1){printf("1\n");continue;}
        if(N==2){printf("2\n");continue;}
        if(N==3){printf("5\n");continue;}
        if(N==4){printf("12\n");continue;}

        else printf("%d\n",power(N-4));

    }
}



