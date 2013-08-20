#include<iostream>
#include<vector>

using namespace std;

int main()
{
  int T;cin>>T;while(T--){
    int n;cin>>n;
    int p=5;
    int count=0;
    while(p<=n){
      count+=n/p;
      p*=5;
    }
    cout<<count<<endl;
  }
  return  0;
}
