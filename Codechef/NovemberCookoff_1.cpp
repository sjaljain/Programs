/* Sajal Jain , 09EC1017
 * Codechef NOV Cookoff
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

int hcf(int a,int b)
{
    if(a%b==0)return b;
    else return hcf(b,a%b);
}

int main()
{
     int T;
     scanf("%d",&T);
     //cout<<hcf(18,12);
     while(T--)
     {
        int N;
        scanf("%d",&N);
        vector<int> A(N);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&A[i]);
        }
        int gcd=A[0];
        for(int i=0;i<N;i++)
        {
            gcd=hcf(max(A[i],gcd),min(A[i],gcd));
        }
        int ans=gcd;
        for(int i=2;i<=sqrt(gcd);i++)
        {
            if(gcd%i==0)
            {
                ans=i;
                break;
            }
        }
        if(ans==1)printf("-1\n");
        else printf("%d\n",ans);


     }
     return 0;
}
