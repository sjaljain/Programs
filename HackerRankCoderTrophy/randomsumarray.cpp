#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int main()
{
    long long int N,T;
    scanf("%lld%lld",&N,&T);
    vector<long long int> v(N);
    vector<long long int> sum(N);
    for(int i=0;i<N;i++)scanf("%lld",&v[i]);
    sum[0]=v[0];
    for(int i=0;i<N;i++)sum[i]=sum[i-1]+v[i];

    int totcount=0;
    int cnt,s;
    int end=0;

    for(int start=0;start<N;start++)
    {
        s=sum[end]-sum[start]+v[start]; //including starting amount
        while(s<=T)
        {
            end++;
            if(end==N)break;
            s=sum[end]-sum[start]+v[start]; //including starting amount
        }
        cnt=end-start;
        totcount+=cnt;
        //cout<<cnt<<" ";
        end--;

    }
    long long int totpos=N*(N+1)/2;
    double prob=(double)totcount/(double)totpos;
    cout<<prob;

    return 0;
}

