/* Sajal Jain , 09EC1017
 * Interview Street
 * Binomial coefficient
 *
 */

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <fstream>
using namespace std;

#define pp pair <int,int>
#define inf 999999999
#define MOD 142857
#define dim 2001

long long  mult(long long a,long long b)
{
	long long result=1;
	while(b>0){
		if(b&1==1)
			result=result*a%MOD;
		b>>=1;
		a=a*a%MOD;
	}
	return result;
}

long long multinv(long long a)
{
	return mult(a,MOD);
}

int main()
{
	long long  fact[MOD+1];
	fact[0]=1;
	long long int i,den=1,num=1;
	long long int factinv[MOD+1];
	fact[0]=factinv[0]=1;
	for( i=1;i<MOD+1;i++){
		num*=i;
		num%=MOD;
		fact[i]=num;
		den*=multinv(i);
		den%=MOD;
		factinv[i]=den;
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k,result=1;;
		scanf("%d%d",&n,&k);
	while(n){	int N=n%MOD;
		int K=k%MOD;
		if(N<K){result=0;break;}
		 result*=fact[N];
		result=result*factinv[K];
		result=result*factinv[N-K];
		result%=MOD;
		n/=MOD;
		k/=MOD;}
		printf("%d\n",result);
}
	return 0;
}

