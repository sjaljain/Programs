/* Sajal Jain , 09EC1017
 * Codechef
 * COALSCAM
 * Spanning Tree
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
using namespace std;

#define pp pair <int,int>
#define inf 999999999
#define MOD 1000000007

struct edge
{
    int start;
    int end;
    int cost;
    edge(int _start,int _end,int _cost){start=_start;end=_end;cost=_cost;}
};

bool Cmp(const edge &e1,const edge &e2){return e1.cost<e2.cost;}
bool CmpDesc(const edge &e1,const edge &e2){return e1.cost>e2.cost;}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,M1,M2;scanf("%d%d%d",&N,&M1,&M2);
        set<int> s;
        vector<edge> m1,m2;
        for(int i=0;i<M1;i++)
        {
            int s,e,c;scanf("%d%d%d",&s,&e,&c);
            m1.push_back(edge(s,e,c));
        }
        for(int i=0;i<M2;i++)
        {
            int s,e,c;scanf("%d%d%d",&s,&e,&c);
            m2.push_back(edge(s,e,c));
        }
        unsigned long long int profit=0,exp=0;
        sort(m2.begin(),m2.end(),CmpDesc);
        for(int i=0;i<M2;i++)
        {
            cout<<m2[i].start<<" "<<m2[i].end<<" "<<m2[i].cost<<endl;
            if(s.find(m2[i].start)==s.end() || s.find(m2[i].end)==s.end())
            {
                profit+=m2[i].cost;
                s.insert(m2[i].start);s.insert(m2[i].end);
            }
        }
        exp=profit;
        sort(m1.begin(),m1.end(),Cmp);

        for(int i=0;i<M1;i++)
        {
            cout<<m1[i].start<<" "<<m1[i].end<<" "<<m1[i].cost<<endl;
            if(s.find(m1[i].start)==s.end() || s.find(m1[i].end)==s.end())
            {
                exp+=m1[i].cost;
                s.insert(m1[i].start);s.insert(m1[i].end);
            }
        }
        if(s.size()!=N){printf("Impossible\n");}
        else printf("%lld %lld\n",profit,exp);

    }
    return 0;
}
