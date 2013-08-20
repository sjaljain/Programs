/* Sajal Jain , 09EC1017
 * Codechef
 * COALSCAM
 * Spanning Tree
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
#define pchar(c) putchar_unlocked(c)//op[opsz++] = c

int main()
{
    vector<int> Prime(5000001,1);
    for(int n=2;n<=sqrt(5000001);n++)
    {
        if(Prime[n]==0)continue;
        for(int j=n*n;j<=5000000;j+=n)
        Prime[j]=0;
    }
    //for(int i=112000;i<=500000;i++){if(Prime[i]!=0)cout<<i<<" ";}
    int N;
    vector<long long int> Answer(5000001,0);
    Answer[0]=1;
    int num_prime=0;
    for(int i=1;i<=5000000;i++)
    {
        if(Prime[i]==1)num_prime++;

        if(num_prime==0){cout<<num_prime;break;}
        Answer[i]=(Answer[i-1]*num_prime);
        Answer[i]=Answer[i]%MOD;
       //if(Answer[i]==0) {cout<<i<<" "<<Answer[i-1];cout<<" "<<num_prime;break;}

    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);

        printf("%lld\n",Answer[N]);


    }
    return 0;
}

