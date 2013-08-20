/* Sajal Jain , 09EC1017
 * Codechef
 * CARVANS
 * Simple - AdHoc
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
        int N;scanf("%d",&N);
        vector<int> v(N);
        for(int i=0;i<N;i++)
            scanf("%d",&v[i]);

        int ans=1,max=v[0];
        for(int i=1;i<N;i++)
        {
            if(v[i]<=max){ans++;max=v[i];}
        }
        printf("%d\n",ans);
    }
    return 0;
}
