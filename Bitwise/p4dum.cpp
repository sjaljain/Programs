#include<iostream>

using namespace std;

typedef long long int LL;

int main()
{
    long long int MOD=1000000007;
    int T;
    cin>>T;
    while(T--)
    {

    long long int a,b,c,d;
    a=1;b=2;c=5;d=12;
    long long int e;
    int N;
    cin>>N;
    N=N-4;
    while(N--)
    {
        e=1*d+ 2*c + 3*b + a;
        cout<<e<<" a ";
        a=b;
        b=c;
        c=d;
        d=e%MOD;
        cout<<d<<" ";
    }
    cout<<e<<endl;
    }

}
