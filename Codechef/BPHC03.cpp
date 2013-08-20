/* Sajal Jain , 09EC1017
 * SPOJ
 * HERDING
 * BFS/DFS/Trivial
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

int N;

int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};

int valid(int x,int y)
{
    if(x<0 || x>=N || y<0 || y>=N)return 0;
    else return 1;
}

void dfs(vector<int> G[],int v,vector<int> &used,int &count)
{
    if(v==N*N-1){count=count+1;return;}
    if(used[v]==1){used[v]=0;return;}
    used[v]=1;
    for(int j=0;j<G[v].size();j++)
    {
        if(used[G[v][j]]==1)continue;
        dfs(G,G[v][j],used,count);

    }
    if(used[v]==1){used[v]=0;}
    return ;
}

int main()
{

     scanf("%d",&N);
     vector< vector<int> > A(N,vector<int> (N));
     for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&A[i][j]);

     vector<int> G[N*N];
     vector<int> used(N*N,0);
     for(int i=0;i<N;i++)
     {
         for(int j=0;j<N;j++)
         {
             for(int k=0;k<4;k++)
             {
                 if(!(valid(i+dx[k],j+dy[k])))continue;
                 if(A[i+dx[k]][j+dy[k]]==0)
                 G[i*N+j].push_back((i+dx[k])*N+j+dy[k]);
             }
         }
     }
     /*
     for(int i=0;i<N*N;i++)
     {
         cout<<"Node "<<i<<" ";
         for(int j=0;j<G[i].size();j++)
         cout<<G[i][j]<<" ";

         cout<<endl;
     }*/
     int count=0;
     dfs(G,0,used,count);
     printf("%d",count);
     return 0;
}
