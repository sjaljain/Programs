#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define MOD 1000000007
#define dim 4
#define FOR(k,a,b) for(typeof(a) k=(a); k < (b); ++k)
typedef long long LL;
using namespace std;

int s,e;

struct matrix {
    int a[dim][dim];
};

matrix P[50],t,num,z;

matrix mul(matrix x, matrix y)
{
    matrix res;
	res=z;

    FOR(a,0,2) FOR(b,0,dim) FOR(c,0,dim) {
	res.a[a][c] += ((x.a[a][b]) * LL(y.a[b][c])) % MOD;
	res.a[a][c] %= MOD;
    }

     FOR(a,2,4) FOR(b,0,dim) FOR(c,2,4) {
	res.a[a][c] += ((x.a[a][b]) * LL(y.a[b][c])) % MOD;
	res.a[a][c] %= MOD;
    }


	return res;
}


void precompute(int s,int e)
{
 	matrix res;
 	for(int i=s;i<=e;++i)
    {
    	res=mul(P[i],P[i-1]);
		P[i+1]=res;
    	P[i]=res;
    }
    s=e;

}

int power(LL pow)
{
    matrix num1;
    num1=num;

   	int i;
    matrix res;
    while(pow!=0)
    {
    	i=log2(pow&~(pow-1));
    	if(i>s)
    	{
    		precompute(s+1,i);
    		s=i;
    	}
   		res=mul(num1,P[i]);
		num1=res;


		pow=(pow&(pow-1));
    }

 		LL s=((LL)num1.a[0][0]*44)%MOD;
 		LL s1=((LL)num1.a[0][1]*18)%MOD;
 		LL s2=((LL)num1.a[0][2]*21)%MOD;
 		LL s3=((LL)num1.a[0][3]*13)%MOD;
    return (s+s1+s2+s3)%MOD;
}







int main()
{

    int T;
    s=0;
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

   	z.a[0][0]=0;
   	z.a[0][1]=0;
   	z.a[0][2]=0;
   	z.a[0][3]=0;

   	z.a[1][0]=0;
   	z.a[1][1]=0;
   	z.a[1][2]=0;
   	z.a[1][3]=0;

   	z.a[2][0]=0;
   	z.a[2][1]=0;
   	z.a[2][2]=0;
   	z.a[2][3]=0;

   	z.a[3][0]=0;
   	z.a[3][1]=0;
   	z.a[3][2]=0;
   	z.a[3][3]=0;


  	scanf("%d",&T);
   	t.a[0][0]=1;
   	t.a[0][1]=1;
   	t.a[0][2]=1;
   	t.a[0][3]=1;

   	t.a[1][0]=1;
   	t.a[1][1]=0;
   	t.a[1][2]=0;
   	t.a[1][3]=0;

   	t.a[2][0]=0;
   	t.a[2][1]=0;
   	t.a[2][2]=1;
   	t.a[2][3]=1;

   	t.a[3][0]=0;
   	t.a[3][1]=0;
   	t.a[3][2]=1;
   	t.a[3][3]=0;

	P[0]=t;
 	P[1]=t;
	while(T--)
    {
        LL N;
        scanf("%llu",&N);

        if(N==0 || N==1){printf("0\n");continue;}
        if(N==2){printf("5\n");continue;}
        if(N==3){printf("18\n");continue;}
        else printf("%d\n",power(N-4));
        int i,j;


    }
}
