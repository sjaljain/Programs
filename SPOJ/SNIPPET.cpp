#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#define MAX 10001
#define edge pair<int,int>
using namespace std;
vector< pair<int, edge > > Graph,MST;
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
void kruskal()
{
    sort(Graph.begin(),Graph.end());
    int total = 0;
    for(int i=0; i<e; i++)
    {
        int pu = findSet(Graph[i].second.first,parent);
        int pv = findSet(Graph[i].second.second,parent);
        if(pu!=pv)
        {
            total+=Graph[i].first;
            MST.push_back(Graph[i]);
            parent[pu] = parent[pv];
        }
    }
    cout<<total<<"\n";
}
int main()
{
	int s;
	cin>>s;
	while(s--)
	{
    cin>>n;
    initialize(n);
    e=0;
    int u,v,w;
    for(int i=1; i<=n; i++)
    {
		string name;int p;
		cin>>name;
		cin>>p;
		e+=p;
		for(int j=1;j<=p;j++)
		{
        cin>>v>>w;
        Graph.push_back(pair<int, edge>(w,edge(i,v)));
		}
    }
    kruskal();
	}
    return 0;
}

