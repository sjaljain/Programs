/* Sajal Jain , 09EC1017
 * Codechef
 * Oct Long Challenge
 * MAXCOMP- DP Easy
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

struct event
{
    int start,end,cost;
    event(int _start,int _end,int _cost){start=_start;end=_end;cost=_cost;}
};

bool cmp(const event &a,const event &b)
{
    return a.end<b.end;
}

int main()
{

     int T;
     scanf("%d",&T);
     while(T--)
     {
        int N;
        scanf("%d",&N);
        vector<event> v;
        for(int i=0;i<N;i++)
        {
            int s,e,c;
            scanf("%d%d%d",&s,&e,&c);
            v.push_back(event(s,e,c));
        }
        sort(v.begin(),v.end(),cmp);
        int max[49]={0},j=0;
        for(int i=1;i<=48;i++)
        {
            max[i]=max[i-1];
            while(j<N)
            {
                if(v[j].end>i)break;
                if(max[i]<max[v[j].start]+v[j].cost)
                        max[i]=max[v[j].start]+v[j].cost;
                j++;
            }
            //printf("%d ",max[i]);
        }
        printf("%d\n",max[48]);

     }
     return 0;
}
