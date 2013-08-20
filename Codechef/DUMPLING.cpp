#include<iostream>

using namespace std;

unsigned long long int gcd(unsigned long long int a,unsigned long long int b)
{
  if(b==0 || a==0) return a;
  else return gcd(b,a%b);
}

unsigned long long  int lcm(unsigned long long int a,unsigned long long int b)
{
  return (a/gcd(a,b))*b;
}

 int main()
{
  int T;
  cin>>T;
  while(T--)
    {
      unsigned long long int A,B,C,D,K;
      cin>>A>>B>>C>>D>>K;
      // cout<<gcd(A,B)<<" "<<gcd(C,D)<<" "<<endl;
      //unsigned long long int ans=lcm(gcd(A,B),gcd(C,D));
      //cout<<ans;
      cout<<2*(K/(lcm(gcd(A,B),gcd(C,D))))+1<<endl;
    }
  return 0;
}
/*
1
2000000000000 3000000000000 5000000000000 10000000000000 13000000000000
*/
