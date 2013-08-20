/* Sajal Jain , 09EC1017
 * Facebook Interview Test
 * DFS all nodes on simple paths
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

void dfs(vector<int> G[],int v,int d,vector<int> &inpath,vector<int> &path,vector<int> &used)
{
    used[v]=1;path.push_back(v);
    if(inpath[v]==1)
    {

        for(int i=0;i<path.size();i++)
            inpath[path[i]]=1;

        path.erase(path.begin() + path.size()-1);
        used[v]=0;
        return;
    }
    //if(used[v]==1){used[v]=0;return;}
    for(int j=0;j<G[v].size();j++)
    {
        if(used[G[v][j]]==1)continue;
        //path.push_back(G[v][j]);
        dfs(G,G[v][j],d,inpath,path,used);

    }
    if(used[v]==1){used[v]=0;path.erase(path.begin() + path.size()-1);}
    return ;
}

int main()
{
     int T;
     scanf("%d",&T);
     while(T--)
     {
     int N,M,H,S;
     scanf("%d %d %d %d",&N,&M,&H,&S);
     vector< int > G[N];
     for(int i=0;i<M;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
     vector<int> inpath (N,0);
     inpath[S]=1;

     vector<int> path;
     vector<int> used (N,0);

     dfs(G,H,S,inpath,path,used);

     cout<<"vertex visited == ";
     int count=0;
     for(int i=0;i<N;i++)
        if(inpath[i]==1){cout<<i<<" ";count++;}
     cout<<"\ncount == ";
     printf("%d\n",count);
     }
     return 0;
}
