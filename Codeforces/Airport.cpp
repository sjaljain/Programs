//============================================================================
// Name : Airport.cpp
// Author : Sajal Jain
// Version :
// Copyright : Airport
// Description : Ansi-style
//============================================================================
#include <iostream>
#include<vector>
#include <string>
#include<algorithm>


using namespace std;

int main() {
      
     int N,M;
     cin>>N>>M;
     vector<int> v(M);
     for(int i=0;i<M;i++)cin>>v[i];
     sort(v.begin(),v.end());
     //minimize answer
     int min=0,count=0,x;
     for(int i=0;i<M;i++)
     {
             x=v[i];
             min+=(x*(x+1))/2;
             if(count+x>N)
             {
                             x=count+x-N;
                             min-=(x*(x+1))/2;
                             break;
                             }
              count+=x;               
             
     }  
     
     
     //maximize answer
     int max=0;
     count=0;
     int A[1001]={0};
     int j=0;
     for(int i=1;i<1000;i++)
     {
             if(j>=M)break;
             A[i]=M-j;
             while(v[j]<=i)j++;
             }      
      for(int i=v[M-1];i>=0;i--)
      {
              x=A[i];
              max+=x*i;
              if(count+x>N)
              {
                           x=count+x-N;
                           max-=x*i;
                           break;
                           }
              count+=x;
              }  
              
     cout<<max<<" "<<min;       

     //getchar();getchar();
     return 0;
}
