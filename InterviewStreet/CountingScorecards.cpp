/* Sajal Jain , 09EC1017
 * Interview Street
 * Counting Scorecards
 * Dynamic Programming - counting number of integral solutions of equation
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
using namespace std;

#define pp pair <int,int>
#define inf 999999999
#define MOD 10000007


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,S;
        scanf("%d",&N);
        S=N*(N-1)/2;
        int p,n=0;
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&p);
            if(p==-1){n++;}
            else S-=p;
        }
        if(S==0){printf("1\n");continue;}
        else if(S<0){printf("0\n");continue;}
        //Find number of integral solutions of n variables that sum up to S

        vector< vector< int> > DP;
        vector<int> v(S+1,0);
        for(int i=0;i<=n;i++)DP.push_back(v);
        DP[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=(N-n+i)*(N-n+i-1)/2;j<=(S-((n-i)*(n-i-1)/2));j++)
            {
                for(int x=0;x<=N-1 && (j-x)>=0;x++)
                {
                    DP[i][j]=(DP[i][j]+DP[i-1][j-x])%MOD;
                }
            }
        }
        printf("%d\n",DP[n][S]);

    }
    return 0;
}
