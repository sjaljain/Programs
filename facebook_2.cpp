#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
vector<int> G[100];
vector<int> ans,visited,Pa,mark;
int t,n,m,h,s,u,v,count;
int dfs(int pos,int P);
int main()
{
	int i;

	cin>>t;

	while(t--)
	{
		cin>>n>>m>>h>>s;

		for(i=0;i<100;++i)
			G[i].clear();

		for(i=0;i<m;++i)
		{
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		ans.assign(n+1,-1);
		visited.assign(n+1,0);
		mark.assign(n+1,-1);

		Pa.assign(n+1,-1);
		mark[s]=1;
		dfs(h,0);

		int count=0;

		for(i=0;i<n;++i)
			if(mark[i]==1)
				count++;

		cout<<endl;
		cout<<count<<endl;
	}

	return 0;
}

int dfs(int pos,int P)
{
	int i;
    if(mark[pos]==1)
        return 1;

	visited[pos]=1;
	int thru = -1;
	for(int i=0;i<G[pos].size();++i)
	{
	    int k;
		if(visited[G[pos][i]]==0 )
         {
             k = dfs(G[pos][i],P+1);
             if(k==1)
             {
                 thru = 1;
             }
         }
	}
	visited[pos]=0;
	if(thru == 1)
	{
	    mark[pos]=1;
	}
	return mark[pos];
}
