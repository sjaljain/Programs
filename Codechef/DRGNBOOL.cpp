/* Sajal Jain , 09EC1017
 * Codechef
 * Oct Long Challenge
 * DRGNBOOL -Easy
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
#define dim 2001


int main()
{

     int T;
     scanf("%d",&T);
     while(T--)
     {
        int N,M;
        scanf("%d%d",&N,&M);
        vector< pp > I,F;
        for(int i=0;i<N;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            I.push_back(make_pair(a,b));
        }
        for(int i=0;i<M;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            F.push_back(make_pair(a,b));
        }
        int L_I[101]={0},L_F[101]={0};
        for(int i=0;i<N;i++)
               L_I[I[i].second]+=I[i].first;
        for(int i=0;i<M;i++)
               L_F[F[i].second]+=F[i].first;

        int ans=0;
        for(int i=1;i<=100;i++)
               if(L_F[i]>L_I[i])ans+=L_F[i]-L_I[i];

        printf("%d\n",ans);

     }
     return 0;
}
