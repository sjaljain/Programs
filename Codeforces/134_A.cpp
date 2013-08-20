//============================================================================
// Name : StringSimilarties.cpp
// Author : Sajal Jain
// Version :
// Copyright : Codeforces Mountain Scenery
// Description : Ansi-style
//============================================================================
#include <iostream>
#include <stdio.h>
#include<vector>
#include <string>

using namespace std;

int main() {
     int N,K;
     cin>>N>>K;
     vector<int> v(2*N+1);
     for(int i=0;i<2*N+1;i++)cin>>v[i];
     for(int i=1,k=0;i<2*N+1 && k<K;i+=2)
     {
             if((v[i]-1>v[i+1])&&(v[i]-1>v[i-1]))
             {v[i]--;k++;}
             }  
     for(int i=0;i<2*N+1;i++)
     cout<<v[i]<<" ";
     
     //getchar();getchar();
     return 0;
}
