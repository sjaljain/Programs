#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
#define getcx getchar_unlocked

#define MAX 5000000
#define LMT 2236
#define MOD 1000000007
unsigned base[MAX/64];
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))
int A[5000001];
void pre()
{
    unsigned i, j, k,ptn;
    for(i=3; i<LMT; i+=2)
        if(!chkC(base, i))
            for(j=i*i, k=i<<1; j<MAX; j+=k)
                setC(base, j);
	A[1]=1;
	A[2]=2;
	ptn=2;
    for(i=3; i<=MAX; i++)
	{
		if(i&1)
		{
			if(!chkC(base, i))
				ptn++;
		}
		A[i]=((long long)(A[i-1])*ptn)%MOD;
	}
}

int main()
{
	pre();
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		cin>>n;
		printf("%d\n",A[n]);
	}
	return 0;
}
