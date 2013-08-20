#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

long long int count( long long int, long long int);

#define MOD 1000007 
            
int main()
{
    long long int N;
    cin>>N;
    vector<long long int> v(N+1,1);
    v[0]=0;v[1]=0;
    for(long long int i=2;i<=sqrt(N);i++)
           for( long long int j=2*i;j<N+1;j+=i)
                    v[j]=0;
    
    //for(int i=0;i<N+1;i++){if(v[i]==1)cout<<i<<" ";}
    long long int ans=1;
    for( long long int n=2;n<=N;n++)
    {
            if(v[n]==0)continue;
            //cout<<count(N,n)<<" ";
            ans=(ans*(2*count(N,n)+1))%MOD;
            }
    cout<<ans;
    //getchar();getchar();
    
    return 0;
}

long long int count( long long int N, long long int n)
{
  long long int x=n;
 long long int sum=0;
 while(x<=N)
 {
            sum+=N/x;
            x*=n;
            } 
  return sum;  
}
