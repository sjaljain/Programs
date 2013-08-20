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

int dfs(vector<int> G[],int v,vector<int> &inpath,vector<int> &used)
{
    //cout<<v<<" ";
    used[v]=1;
    if(inpath[v]==1){used[v]=0;return 1;}
    else if(inpath[v]==-1){used[v]=0;return 0;}

    int x=0,y=0;
    for(int j=0;j<G[v].size();j++)
    {
        if(used[G[v][j]]){y=1;continue;} //y =1->back edge exists, path may exist
        x=max(x,dfs(G,G[v][j],inpath,used));
    }
    used[v]=0;
    if(x==0 && y==0) {inpath[v]=-1;return 0;}
    else if(x==1) {inpath[v]=1;return 1;}
    else return 0;

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
     //inpath values 0=maybe,1=in,-1=out
     vector<int> inpath (N,0);
     vector<int> used (N,0);
     inpath[S]=1;
     int x=dfs(G,H,inpath,used);
     int count=0;

     //cout<<"vertex visited == ";
     for(int i=0;i<N;i++)
        if(inpath[i]==1)
        {
            //cout<<i<<" ";
            count++;
        }
     //cout<<"\ncount == ";
     if(count==1 && H!=S)count=0;
     printf("%d\n",count);
     }
     return 0;
}
