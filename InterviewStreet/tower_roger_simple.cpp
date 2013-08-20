#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cassert>
#include<vector>

using namespace std;

int N;
vector<int> G[10000];

int dfs(int org,int s,vector<int> &covered)
{
    covered[s]=1;
    for(int i=0;i<G[s].size();i++)
    {
        //printf("%d - ",G[s][i]);
        if(G[s][i]==org){return 1;}
        if(covered[G[s][i]])continue;
        else return dfs(org,G[s][i],covered);
    }
    return 0;
}

int main()
{

    int T;
    scanf("%d",&T);
    while(T--)
    {
        int M;
        scanf("%d %d",&N,&M);
        for(int i=0;i<N+1;i++)G[i].clear();
        int done=0;
        for(int i=1;i<=M;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            G[u].push_back(v);
            vector<int> covered(N+1,0);
            if(dfs(u,u,covered)==1){printf("No: %d\n",i);done=1;break;}
        }
        if(done)continue;
        printf("Yes\n");

    }
    return 0;


}
