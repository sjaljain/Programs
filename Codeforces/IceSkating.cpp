//============================================================================
// Name : StringSimilarties.cpp
// Author : Sajal Jain
// Version :
// Copyright : Ice Skating
// Description : Ansi-style
//============================================================================
#include <iostream>
#include <stdio.h>
#include<vector>
#include <string>
#include <queue>

#define pp pair<int ,int> 

using namespace std;

int main() {
     int N;
     cin>>N;
     vector<int> v[N];
     int val[N][2];
     for(int i=0;i<N;i++)
     {
             cin>>val[i][0]>>val[i][1];
             for(int j=0;j<i;j++)
             {
                     if((val[i][0]==val[j][0])||(val[i][1]==val[j][1]))
                     {
                                                 v[i].push_back(j);
                                                 v[j].push_back(i);
                     }
                     
              }
             
     }
     
     //for(int i=0;i<N;i++){cout<<i<<" ";for(int j=0;j<v[i].size();j++)cout<<v[i][j]<<" ";cout<<endl;    }
     int count=-1;
     int visited[1001]={0};
     queue<int> Q;
     for(int i=0;i<N;i++)     
     {
             if(visited[i]!=0)continue;
             count++;
             visited[i]=1;
             Q.push(i);
             while(!Q.empty())
             {
                              for(int j=0;j<v[Q.front()].size();j++)
                              {
                                      if(visited[v[Q.front()][j]]==0)
                                      {
                                                             visited[v[Q.front()][j]]=1;
                                                             Q.push(v[Q.front()][j]);
                                                             }
                                      }
                              Q.pop();        
                              }             
             }        
      cout<<count;            
     //getchar();getchar();
     return 0;
}
