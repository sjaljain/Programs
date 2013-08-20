#include<iostream>
#include<vector>
using namespace std;
vector<int> connected;
void connectedComponent1(vector<vector<int> > v,vector<bool> &visited,int condition,int j1)
{
visited[j1]=1;
for(int j=0;j<v[0].size();j++)
if(v[j1][j]==1&&visited[j]==0)
connectedComponent1(v,visited,1,j);
}
void connectedComponent(vector<vector<int> > v,vector<bool> &visited,int condition,int j1)
{
for(int i=0;i<v[0].size();i++)
{
if(visited[i]==0)
{

vector<bool> visited2=visited;
visited[i]=1;
for(int j=0;j<v[0].size();j++)
if(v[i][j]==1&&visited[j]==0)
connectedComponent1(v,visited,1,j);

for(int i1=0;i1<v[0].size();i1++)
{
if(visited2[i1]==0&&visited[i1]==1)
connected.insert(connected.end(),i1);
}
connected.insert(connected.end(),-1);

visited2.clear();

}

}
}
int main()
{
int n,condition=0;
cin>>n;
int array[n];
for(int i=0;i<n;i++)
cin>>array[i];


vector<vector<char> > v1(n,n);
vector<vector<int> > v(n,n);
vector<bool> visited(n);


for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
cin>>v1[i][j];
visited[i]=0;
}

for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if(v1[i][j]=='Y'||v1[j][i]=='Y')
v[i][j]=1;
else
v[i][j]=0;
}
}

connectedComponent(v,visited,0,0);
vector<int> v2;
for(int i=0;i<connected.size();i++)
{
if(connected[i]==-1)
{
sort(v2.begin(),v2.end());
v2.clear();
}
v2.insert(v2.end(),array[connected[i]]);

}
for(int i=0;i<n;i++)
cout<<v2[i]<<" ";
//system("pause");
return 0;
}
