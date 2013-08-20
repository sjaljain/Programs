/*
The program has N vertices and M edges.
The vertices are numbered 1..N and root is any one of them
Take the inputs to the M edges. Then we print the bfs value from the root which is taken from the user
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
int N,M,root;
cin>>N>>M;
int a,b;
vector<int > v[N+1];
for(int i=1;i<=M;i++)
	{
	cin>>a>>b;
	v[a].push_back(b);
	v[b].push_back(a);

	}

    vector<int> dist(N+1,-1);
    queue<int> Q;
    int s=1;dist[s]=0;
    Q.push(s);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int j=0;j<v[u].size();j++)
        {
            if(dist[v[u][j]]!=-1)continue;
            dist[v[u][j]]=dist[u]+1;
            Q.push(v[u][j]);
        }
    }
    cout<<endl;
    for(int i=1;i<=N;i++)cout<<dist[i]<<" ";




return 0;
}
