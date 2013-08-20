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
#define dim 2
#define FOR(k,a,b) for(typeof(a) k=(a); k < (b); ++k)
typedef long long LL;
using namespace std;

struct matrix {
    int a[dim][dim];
};

matrix P[65],t;

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

   	num.a[1][0]=0;
   	num.a[1][1]=1;

    int i;
    matrix res;
    while(pow!=0)
    {
    	i=(int)log2(pow&~(pow-1));
   		res=mul(num,P[i]);

   		 for(int i=0;i<dim;i++)
    		for(int j=0;j<dim;j++)
        		num.a[i][j]=res.a[i][j];

   		pow=pow&(pow-1);
    }
    return ((LL(num.a[0][0])*24)+(LL(num.a[0][1])*12))%MOD;
}



void precompute()
{
	int d,u;
 	matrix res;
	for(int i=0;i<dim;i++)
    	for(int j=0;j<dim;j++)
    	{
        	P[0].a[i][j]=t.a[i][j];
        	P[1].a[i][j]=t.a[i][j];
        	res.a[i][j]=t.a[i][j];
        }


    for(int i=1;i<=64;i++)
    {

    	for(d=0;d<dim;d++)
    		for(u=0;u<dim;u++)
    			P[i].a[d][u]=res.a[d][u];

    	res=mul(P[i],P[i-1]);

    	for(d=0;d<dim;d++)
    		for(u=0;u<dim;u++)
    			P[i].a[d][u]=res.a[d][u];
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

    t.a[0][0]=1;
   	t.a[0][1]=2;
   	t.a[0][2]=3;
   	t.a[0][3]=1;

   	t.a[0][0]=1;
   	t.a[0][1]=2;
   	t.a[0][2]=3;
   	t.a[0][3]=1;

   	t.a[0][0]=1;
   	t.a[0][1]=2;
   	t.a[0][2]=3;
   	t.a[0][3]=1;


    precompute();

	while(T--)
    {
        LL N;
        scanf("%llu",&N);

        if(N==0 || N==1){printf("0\n");continue;}
        if(N==2){printf("12\n");continue;}
        if(N==3){printf("24\n");continue;}
        else printf("%d\n",power(N-3));
    }
}


