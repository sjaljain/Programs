#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>

using namespace std;

int main()
{
	int T;cin>>T;while(T--)
	{
		  int N,M;scanf("%d%d",&N,&M);
		  vector<int> v[N];
		  for(int i=1;i<=M;i++)
		  {
				int a,b;scanf("%d%d",&a,&b);
				v[a].push_back(b);
				v[b].push_back(a);
		  }	
		  int Q;scanf("%d",&Q);
		  for(int i=1;i<=Q;i++)
		  {
			  int a,b;scanf("%d%d",&a,&b);
			  vector<int> visited(N,0);
			  queue<int> q;
			  q.push(a);
			  visited[a]=1;
			  int done=0;
			  while(!q.empty() && !done)
			  {
					int p=q.front();
					q.pop();
					for(int j=0;j<v[p].size();j++)
					{
						if(v[p][j]==b){done=1;break;}
						if(!visited[v[p][j]]){q.push(v[p][j]);visited[v[p][j]]=1;}
					}
			  }	
			  if(done)printf("YO\n"); else printf("NO\n");	  
		  }
	}
	return 0;
}
