/* Sajal Jain , 09EC1017
 * CodeChef - October 2012 Cookoff- ACM ICPC
 * Problem 1
 * 1 line description
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
#define dim 2001

int main()
{
     int T;
     scanf("%d",&T);
     while(T--)
     {
        int N,X;
        scanf("%d%d",&N,&X);
        vector<int> v(N);
        for(int i=0;i<N;i++)scanf("%d",&v[i]);
        int min=inf,sum=0;
        for(int i=0;i<N;i++){sum+=v[i];if(v[i]<min)min=v[i];}
        int ans=sum/X;
        if((sum-min)/X==ans)ans=-1;
        printf("%d\n",ans);


     }
     return 0;
}
