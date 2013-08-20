/*
 Codechef- HORSES
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        vector<int> v(N);
        int min=999999999;
        for(int i=0;i<N;i++)
            scanf("%d",&v[i]);
        sort(v.begin(),v.end());
        for(int i=1;i<N;i++)
        {
            if(v[i]-v[i-1]<min)
            min=v[i]-v[i-1];
        }
        printf("%d\n",min);

    }
    return 0;
}
