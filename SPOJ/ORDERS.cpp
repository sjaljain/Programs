/* Sajal Jain , 09EC1017
 * SPOJ
 * ORDERS O(n)
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


int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        vector<int> v(N),ans(N),flag(N,0);
        for(int i=0;i<N;i++)scanf("%d",&v[i]);

        for(int i=0;i<N;i++)ans[i]=(i+1)-v[i];
        for(int i=0;i<N;i++){flag[i-v[i]]++;flag[i]--;}
        int val=0;
        for(int i=0;i<N;i++)
        {
            val+=flag[i];
            ans[i]+=val;
        }
        for(int i=0;i<N;i++)printf("%d ",ans[i]);
        printf("\n");
    }

    return 0;
}


