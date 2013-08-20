#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;
    int M=N*(K-1)/K;
    int done=0;
    while(!done)
    {
        int sum=0;
        int k=K;
        int m=M;
        while(m!=0)
        {
            sum+=m;
            m/=K;
        }
        if(sum>=N)
        {
            done=1;
            cout<<M;
        }
        M++;
    }
    return 0;
}
