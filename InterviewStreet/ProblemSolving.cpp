#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
 int T;cin>>T;
 while(T--)
 {
           int N,K;
           cin>>N>>K;
           vector<int> v[N];
           vector<int> val(N);
           for(int i=0;i<N;i++)
           {
                   cin>>val[i];
                   for(int j=0;j<i;j++)
                   {
                           if(abs(val[i]-val[j])>=K)
                                   v[j].push_back(i);
                           }
                    }
                    
                    
           
           }
           return 0;   
}
