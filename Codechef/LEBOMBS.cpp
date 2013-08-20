#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
              int N;cin>>N;
              string s;
              cin>>s;
              vector<int> v(N,1);
              for(int i=0;i<N;i++)
              {
                      if(s[i]=='1')
                      {
                                   if(i==0){v[0]=0;v[1%N]=0;}
                                   else if(i==N-1){v[(N-2)%N]=0;v[N-1]=0;}
                                   else {v[i-1]=0;v[i]=0;v[i+1]=0;}
                                   }
                      } 
              
              int count=0;        
              for(int i=0;i<N;i++)
              if(v[i]==1)count++;
              
              cout<<count<<endl;
     }
     //getchar();
     //getchar();
    return 0;
}

