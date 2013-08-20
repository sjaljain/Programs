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

#define dim 2

#define FOR(k,a,b) for(int k=(a); k < (b); ++k)

typedef long long LL;
using namespace std;

int MOD;

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

int power(LL pow,int V,int U)
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
    return ((LL(num.a[0][0])*V)+(LL(num.a[0][1])*U))%MOD;
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

int findV(int org_V,int V,int U,int X,int Y)
{
    int n=0;
    int found=0;
    if(V==org_V)return n;
    //printf("%d %d\n",V,U);
    while(!found)
    {
            //printf("%d %d - ",V,U);
            n++;
            long long int a,b,c;
            a=LL(X)*LL(V);
            b=LL(Y)*LL(U);
            c=(a+b+MOD)%MOD;
            if((int)c==org_V)found=1;
            else
            {
                U=V;
                V=(int)c;

            }
    }
    return n;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int X,Y,q,V,U,R;
        scanf("%d %d %d %d %d %d",&X,&Y,&q,&V,&U,&R);
        t.a[0][0]=X;
        t.a[0][1]=Y;

        t.a[1][0]=1;
        t.a[1][1]=0;
        MOD=q;
        precompute();

        vector<long long int> D(R);
        for(int i=0;i<R;i++)
            scanf("%lld",&D[i]);

        for(int i=1;i<=1000;i++)printf("%d %d - ",i,power(i-1,V,U));

        for(int i=0;i<R;i++)
        {
            //printf("%lld %d\n",D[i],power(D[i]-1,V,U));
            if(D[i]>=2)
                printf("%d\n",findV(V,power(D[i]-1,V,U),power(D[i]-2,V,U),X,Y));
            else printf("0\n");
        }







    }
    return 0;
}


