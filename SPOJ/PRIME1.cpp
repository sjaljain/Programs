/* Sajal Jain , 09EC1017
 * SPOJ
 * PRIME1
 * Sieve of Eratosthenes
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
#define MOD 1000000007
#define MAXN 1000000000

int main()
{
    int sqrtMAXN=(int)sqrt(MAXN);
    vector<int> Prime(sqrtMAXN+1,1);
    for(int n=2;n<=sqrt(sqrtMAXN);n++)
    {
        if(Prime[n]==0)continue;
        for(int j=n*n;j<=sqrtMAXN;j+=n)
        Prime[j]=0;
    }
     int T;
     scanf("%d",&T);
     //for(int i=0;i<=100;i++)if(Prime[i]==1)printf("%d ",i);
     while(T--)
     {
        int M,N;
        scanf("%d%d",&M,&N);
        vector<int> v(N-M+1,1);
        for(int n=2;n<=sqrtMAXN;n++)
        {
            if(Prime[n]==0)continue;
            for(int j=max(2*n,(((M-1)/n)*n)+n);j<=N;j+=n)
            {
                //if(j==n)continue;
                //printf("%d ",j);
                v[j-M]=0;
            }
        }
        for(int i=0;i<=N-M;i++)
        if(v[i]==1 && (i+M)!=1 && (i+M)!=0)printf("%d\n",i+M);

        printf("\n");
        }

     return 0;
}
