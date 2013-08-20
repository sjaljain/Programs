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
#define inf 9999999
#define MOD 1000000007
#define dim 2001

int main()
{
     int N,M;
     scanf("%d%d",&N,&M);
     vector<vector<int> > G(N+1,vector<int> (N+1,inf));
     for(int i=0;i<M;i++)
     {
         int u,v,w;
         scanf("%d %d %d",&u,&v,&w);
         G[u][v]=w;G[v][u]=w;
     }
     for(int i=1;i<=N;i++)
     {
         int l;scanf("%d",&l);
         for(int j=1;j<=N;j++)
         {
             G[i][j]*=l;
             G[j][i]*=l;
         }
         G[i][i]=0;
     }
/*
     for(int i=1;i<=N;i++)
     {

         for(int j=1;j<=N;j++)
         {
             cout<<G[i][j]<<" ";

         }
         cout<<endl;
     }
  */
     vector<int> cost(N+1),used(N+1,0),assign(N+1,0);
     for(int i=1;i<=N;i++)scanf("%d",&cost[i]);

    for(int l=1;l<=N;l++)//looping on lamps
    {
        int min=inf,c;
        for(int j=1;j<=N;j++)
        {
            c=G[l][j];
            if(!used[j])c+=cost[j];
            if(c<min){min=c;assign[l]=j;}
        }
        used[assign[l]]=1;
    }
    int cnt=0;
    for(int i=1;i<=N;i++)if(used[i])cnt++;printf("%d\n",cnt);
    for(int i=1;i<=N;i++)if(used[i])printf("%d ",i);printf("\n");
    for(int i=1;i<=N;i++)printf("%d ",assign[i]);

    return 0;
}
