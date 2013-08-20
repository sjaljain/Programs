#include<iostream>
#include<vector>
#include<cstdio>
#include<iomanip>

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

    long long int esum=0;
    int totcount=0;
    int cnt,s;
    int end=0;

    for(int start=0;start<N;start++)
    {
        if(end<start)end=start;
        s=sum[end]-sum[start]+v[start]; //including starting amount
        while(s<=T)
        {
            esum+=s;
            end++;
            if(end==N)break;
            s=sum[end]-sum[start]+v[start]; //including starting amount

        }
        cnt=end-start;
        totcount+=cnt;
        end--;

    }
    //cout<<totcount;

    long double prob=0.0;
    if(totcount==0){prob=0.0;cout<<prob;}
    else
    {
        prob=(long double)esum/(long double)totcount;
        cout.precision(12);
        cout.setf(ios::fixed,ios::floatfield);
        cout<<prob;
    }




    return 0;
}

