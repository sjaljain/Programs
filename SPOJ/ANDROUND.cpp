/* Sajal Jain , 09EC1017
 * Codechef
 * Oct Long Challenge
 * MAXRECT - NP Hard Problem
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


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,K;
        scanf("%d%d",&N,&K);
        vector<int> v(N),ans(N);
        for(int i=0;i<N;i++){scanf("%d",&v[i]);}
        for(int i=0;i<N;i++)
        {
            ans[i]=v[i];
            for(int j=1;j<=min(N,K);j++)
            {
                ans[i]=ans[i]&v[(i+j)%N];
                ans[i]=ans[i]&v[(i-j+N)%N];
            }
        }
        for(int i=0;i<N;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
    }


    return 0;
}


