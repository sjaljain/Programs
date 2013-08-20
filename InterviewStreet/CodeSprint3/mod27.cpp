/* Sajal Jain , 09EC1017
 * Interview Street Codesprint Bowling
 * Hard DP
 *
 */

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <fstream>
using namespace std;

#define pp pair <int,int>
#define inf 9999999
#define MOD 1000000007
#define dim 2001

long long modPow(long long a, long long x,long long m) {
    long long res = 1;
    while(x > 0) {
        if(x & 1)res = (res * a) % m;
        a = (a * a) % m;
        x >>= 1;
    }
    return res;
}
int modInverse(int a,int m) {
    int res=1;
    for(int i=1;i<=17;i++)
    {
        res=(res*a)%m;

    }
    return res;
}

int power(int a,int b)
{
    if(b==0) return 1;
    int c=a;
    for(int i=2;i<=b;i++)
        a*=c;

    return a;
}

int main()
{
     //finding nCm modulo 27
     int N,R,M;
     scanf("%d%d",&N,&M);
     R=N-M;
     int pow3=1;
     while(power(3,pow3)<=N)pow3++;
     //cout<<pow3;

     vector<int> Nv(pow3),Rv(pow3),Mv(pow3);
     for(int i=0;i<pow3;i++)
     {
         Nv[i]=(N/power(3,i))%27;
         Rv[i]=(R/power(3,i))%27;
         Mv[i]=(M/power(3,i))%27;
     }

     vector<int> nv(pow3+2),rv(pow3+2),mv(pow3+2);
     int Ncpy=N,Rcpy=R,Mcpy=M;

     //N=n0+n1*3+n2*9

     for(int i=0;i<pow3;i++)
     {
         nv[i]=Nv[i]%3;
         mv[i]=Mv[i]%3;
         rv[i]=Rv[i]%3;
     }
     nv[pow3]=(Nv[pow3-1]/3)%27;nv[pow3+1]=(Nv[pow3-1]/9)%27;
     rv[pow3]=(Rv[pow3-1]/3)%27;rv[pow3+1]=(Rv[pow3-1]/9)%27;
     mv[pow3]=(Mv[pow3-1]/3)%27;mv[pow3+1]=(Mv[pow3-1]/9)%27;

     int e2=0,e0=0;
     for(int i=0;i<pow3+2;i++)
     {
         if(nv[i]<mv[i])e0++;
         if(nv[i]<mv[i] && i>=2)e2++;
     }

     //cout<<e0<<" "<<e2<<endl;
     int ans=(int)power(3,e0);
     ans*=(int)power(-1,e2);
     //cout<<ans<<endl;
     ans=(ans+27)%27;
     //cout<<ans;

     //for(int i=0;i<pow3;i++)
     //cout<<Nv[i]<<" "<<Mv[i]<<" "<<Rv[i]<<endl;

     for(int i=0;i<pow3;i++)
     {
         for(int j=2;j<=Nv[i];j++){if(j%3==0)continue;ans=(ans*j)%27;}
     }

     for(int j=0;j<pow3;j++)
     {
         for(int i=2;i<=Mv[j];i++){if(i%3==0)continue;ans=(ans*modInverse(i,27))%27;}
     }
     for(int j=0;j<pow3;j++)
     {
         for(int i=2;i<=Rv[j];i++){if(i%3==0)continue;ans=(ans*modInverse(i,27))%27;}
     }

     cout<<(ans+27)%27;

    return 0;
}
