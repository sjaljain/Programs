#include <stdio.h>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <time.h>
#include <fstream>
#include <sstream>
using namespace std;

long long modPow(long long a, long long x,long long m) {
    long long res = 1;
    while(x > 0) {
        if(x & 1)res = (res * a) % m;
        a = (a * a) % m;
        x >>= 1;
    }
    return res;
}
long long modInverse(long long a,long long m) {
    return modPow(a, m-2,m);
}

typedef long long int64;

int MODE;

int gcd(int a,int b)
{
	return (b==0)?a:gcd(b,a%b);
}
int multiply(int a,int b)
{
	return (int)(((int64)a*(int64)b)%MODE);
}
int add(int a,int b)
{
	return (a+b)%MODE;
}
int mypower(int p,int64 e)
{
	if (e==0) return 1%MODE;
	if (e%2==0)
		return mypower(multiply(p,p),e/2);
	else
		return multiply(mypower(p,e-1),p);
}
int mypower2(int p,int64 e,int &o)
{
	if (e==0)
	{
		o=1;
		return 0;
	}
	if (e%2==0)
		return multiply(mypower2(multiply(p,p),e/2,o),p+1);
	else
	{
		int t=mypower2(p,e-1,o);
		t=add(t,o);
		o=multiply(o,p);
		return t;
	}
}

long long solve(long long N,long long K,long long m)
{

    long long ans, n, k , num=1, den=1;
    long long FacMod[1010];
    long long FacModInv[1010];
    FacMod[0]=FacModInv[0]=1;
    FacMod[m]=FacModInv[m]=1;
    for(int i=1;i<m;i++){
        num*=i; num%=m;
        FacMod[i]=num;
        den*=modInverse(i,m); den%=m;
        FacModInv[i]=den;
    }
    ans=1;
    while(N){
        n=N%m;  k=K%m;
        if(n<k){ ans=0; break; }
        ans*=FacMod[n];
        ans*=FacModInv[k];
        ans*=FacModInv[n-k];
        ans%=m;
        N/=m;   K/=m;
    }
    return ans;

}
int main(void){
    int i,j,T;
    long long N,K;

    cin>>T;
    while(T--){
        scanf("%lld %lld",&N,&K);
        long long ans[4];
        ans[0]=solve(N,K,3);
        ans[1]=solve(N,K,11);
        ans[2]=solve(N,K,13);
        ans[3]=solve(N,K,37);
        //cout<<ans[0]<<endl;
        /*
        for(int i=0;i<142857;i++)
        {
            if(i%)
        }
        */
        printf("%lld %lld %lld %lld\n",ans[0],ans[1],ans[2],ans[3]);
    }
    return 0;
}
