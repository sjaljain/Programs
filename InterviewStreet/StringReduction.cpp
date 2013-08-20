#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
 int T;cin>>T;
 while(T--)
 {
           string s;
           cin>>s;
           int N=s.length();
           int count[3]={0};
           for(int i=0;i<N;i++)
                   count[s[i]-97]++;
           sort(count,count+3);
           //cout<<count[0]<<" "<<count[1]<<" "<<count[2];
           if(count[0]==0 && count[1]==0)
                       cout<<count[2]<<endl;
           else if((count[0]%2==0 && count[1]%2==0 && count[2]%2==0) ||(count[0]%2==1 && count[1]%2==1 && count[2]%2==1))
                        cout<<2<<endl;
           else cout<<1<<endl;
           
                   
           
           }
           return 0;   
    
}
