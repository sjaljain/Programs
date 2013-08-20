/* Sajal Jain , 09EC1017
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
#include <cstring>
#include <fstream>
using namespace std;

#define pp pair <int,int>
#define inf 999999999
#define MOD 1000000007
#define maxn 1007
typedef long long LL;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int X,Y,q,V,U,R;
        scanf("%d %d %d %d %d %d",&X,&Y,&q,&V,&U,&R);
        vector<int> D(R);
        for(int i=0;i<R;i++)
            scanf("%d",&D[i]);

        int max_d=0;
        for(int i=0;i<R;i++)if(D[i]>max_d)max_d=D[i];

        vector<int> v(2*max_d);
        v[0]=U;v[1]=V;
        for(int i=2;i<2*max_d;i++)
        {
            v[i]=(X*v[i-1]+Y*v[i-2])%q;
        }
        for(int i=0;i<R;i++)
        {
            int j;
            for(j=D[i];j<2*max_d;j++)
            if(v[j]==V){printf("%d\n",j-D[i]);break;}

            if(j==2*max_d)printf("-1\n");
        }
    }
    return 0;
}
