#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#define MAX 2001
#define edge pair<int,int>
using namespace std;
vector< pair<int, edge > > Graph,MST;

//vector<int> visited(n,0);

int n,e,parent[MAX];
void initialize(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i] = i;
    }
    MST.clear();
    Graph.clear();
}
int findSet(int x, int *parent)
{
    if(x!=parent[x])
    {
        parent[x] = findSet(parent[x],parent);
    }
    return parent[x];
}
void kruskal(int x)
{
    sort(Graph.begin(),Graph.end());
    long long int total = 0;
    vector<int> edgewt;
    for(int i=0; i<e; i++)
    {
        int pu = findSet(Graph[i].second.first,parent);
        int pv = findSet(Graph[i].second.second,parent);
        if(pu!=pv)
        {
            total+=Graph[i].first;
            edgewt.push_back(Graph[i].first);
            MST.push_back(Graph[i]);
            parent[pu] = parent[pv];
        }
    }
    sort(edgewt.begin(),edgewt.end());
    for(int i=0;i<x && i<edgewt.size();i++)
    {
        total-=edgewt[edgewt.size()-i-1];
    }
    printf("%lld\n",total);
}

void dfs(int v, vector<int> &visited,vector<int> G[2001])
{
    for(int j=0;j<G[v].size();j++)
    {
        if(visited[G[v][j]])continue;
        visited[G[v][j]]=1;
        dfs(G[v][j],visited,G);
    }
    return ;
}
int numcomponents(vector<int> G[2001])
{
    int num=0;
    vector<int> visited(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(visited[i])continue;
        num++;
        visited[i]=1;
        dfs(i,visited,G);
    }
    return num;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int k;
        scanf("%d%d%d",&n,&e,&k);
        initialize(n);
        int u,v,w;
        vector<int> G[2001];
        for(int i=0;i<e;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            G[u].push_back(v);
            G[v].push_back(u);
            Graph.push_back(pair<int, edge>(w,edge(u,v)));
        }
        //cout<<numcomponents()<<endl;
        int comp=numcomponents(G);
        if(comp>k){printf("Impossible!\n");continue;}
        kruskal(k-comp);


    }

    return 0;
}
