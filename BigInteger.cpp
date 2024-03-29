#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long LL;

#define bit(n) (1<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
#define p_len 4
const int p=10000;
#define NN 28/p_len

struct num
{
	int len;
	int it[NN];
	num(LL n=0)
	{
		for(len=0;n>0;n/=p) it[len++]=n%p;
	}
};

void operator-=(num &a,num b)
{
	int i,div=0;
	for(i=0;i<a.len;i++)
	{
		div+=a.it[i]-(i<b.len?b.it[i]:0)+2*p;
		a.it[i]=div%p;
		div=div/p-2;
	}
	for(;i-->=0 && a.it[i]==0;);
	a.len=i+1;
}

num operator*(num a,num b)
{
	num prod(0);
	memset(prod.it,0,sizeof prod.it);
	if(b.len==0 || a.len==0) return prod;
	int i,j,div;
	for(i=0;i<a.len;i++)
	{
		if(a.it[i]>0)
		{
			div=0;
			for(j=0;j<b.len;j++)
			{
				div+=prod.it[i+j]+a.it[i]*b.it[j];
				prod.it[i+j]=div%p;
				div/=p;
			}
			if(div>0) prod.it[i+j]=div;
		}
	}
	prod.len=a.len+b.len;
	if(prod.it[prod.len-1]==0) prod.len--;
	return prod;
}

void print(num &a)
{
	if(a.len==0) printf("0"); else
	{
		long i=a.len-1;
		printf("%d",a.it[i]);
		char s[10];
		sprintf(s,"%%0%dd",p_len);
		for(i--;i>=0;i--) printf(s,a.it[i]);
	}
	printf("\n");
}

int main()
{

	int T;
	for(scanf("%d",&T);T--;)
	{
		LL n,m;
		scanf("%lld %lld",&n,&m);
		num ans=num(n)*num(m);
		ans-=num(n);
		/*
		num ans=num(m*n)*num(m*n-1);

		if(m>1 && n>2) ans-=num(4*(m-1)*(n-2));
		if(m>2 && n>1) ans-=num(4*(m-2)*(n-1));
		*/
		print(ans);
	}
	return 0;
}
