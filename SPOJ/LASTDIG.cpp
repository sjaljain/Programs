#include<iostream>
#include<math.h>
using namespace std;

int find(int ,int);

int main()
{
  int T;cin>>T;while(T--){
    int a,b;
    cin>>a>>b;
    int x=find(a,b);
    cout<<x<<endl;
  }
  return 0;
}

int find(int a,int b)
{
if(b==0)return 1;
 
    //find last digit of a
    int da = a % 10;
 
    if(da==0)return 0;
    if(da==5)return 5;
    switch(b%4){
    case 0:
      return da%2!=0?1:6;
    case 1:
      return da;
    case 2:
      return da*da%10;
    default:
      return da*da*da%10;

    }
}
