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
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    vector<long long int> sum(n,0);
    sum[0]=v[0];
    for(int i=1;i<n;i++){sum[i]=v[i]+sum[i-1];}

    for(int i=0;i<n;i++)printf("%d ",sum[i]);
    printf("\n");
    int count=1,val=v[0];

    for(int i=1;i<n;i++)
    {
        int cnt;
        for(cnt=i-1;cnt>=0;cnt--)
        {
            if(sum[i]-sum[cnt]+k<(i-cnt+1)*v[i])break;
        }
        if(cnt<0)cnt=0;
        if(i-cnt+1>count){count=i-cnt+1;val=v[i];}


    }
    printf("%d %d",count,val);

    return 0;
}


