#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
 int N,M;
 cin>>N>>M;
 vector<int> v[N+1];
 int color[101]={0};
 for(int i=0;i<M;i++)
 {
         int a,b;
         cin>>a>>b;
         v[a].push_back(b);
         v[b].push_back(a);
         }   
 for(int i=1;i<=N;i++)
 {
         int c[4]={0};
         if(v[i].size()==0)continue;
         for(int j=0;j<v[i].size();j++)
                  c[color[v[i][j]]]=1;              
         
         if(c[1]==0)color[i]=1;
         else if(c[2]==0)color[i]=2;
         else if(c[3]==0)color[i]=3;
         }
 
 int count[4]={0};        
 for(int i=1;i<=N;i++)
 count[color[i]]++;
 
 for(int i=1;i<=N;i++)
 //cout<<color[i]<<" ";
 
 sort(count+1,count+4);
 if((count[0]+count[2]+count[3])%2==1)count[1]++;
 cout<<count[1];
 
 //getchar();
 //getchar();
         return 0;
    
}
