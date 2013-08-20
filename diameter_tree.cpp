#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N;
  cin>>N;
  int a,b;
  vector< int > v[N+1];
  for(int i=1;i<=N-1;i++)
	{
	cin>>a>>b;
	v[a].push_back(b);
	v[b].push_back(a);
	}
  int depth[10001]={0};
  int done[100001]={0},done1[10001]={0};
  vector <int> q,q1;
  q.push_back(1);done[1]=1;

  int count=0;
  while(count<N-1)
    {
      for(int j=0;j<v[q[count]].size();j++)
	{
	if(!done[v[q[count]][j]])
	{	
		q.push_back(v[q[count]][j]);
		done[v[q[count]][j]]=1;
	}
	//cout<<v[q[count]][j]<<" ";
	//depth[v[q[count]][j]]=depth[q[count]]+1;
	}
      count++;
    }

  //for(int i=0;i<q.size();i++) cout<<q[i]<<" ";

  q1.push_back(q[N-1]);
	//cout<<q1[0];
	done1[q1[0]]=1;
  count=0;
  while(count<N-1)
    {
      for(int j=0;j<v[q1[count]].size();j++)
	{
	if(!done1[v[q1[count]][j]])
		{
		q1.push_back(v[q1[count]][j]);
		//cout<<v[q1[count]][j]<<" ";
		depth[v[q1[count]][j]]=depth[q1[count]]+1;
		done1[v[q1[count]][j]]=1;
		}
	}
      count++;
    }
	
//for(int i=0;i<q1.size();i++) cout<<q1[i]<<" ";

  cout<<depth[q1[N-1]]<<endl;



return 0;
}

