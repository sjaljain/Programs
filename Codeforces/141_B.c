#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    vector<long long int> v(N);
    for(int i=0;i<N;i++)
    {
        cin>>v[i];
    }
    vector<int> Prime(5000001,1);
    for(int n=2;n<=sqrt(5000001);n++)
    {
        if(Prime[n]==0)continue;
        for(int j=n*n;j<=5000000;j+=n)
        Prime[j]=0;
    }

    for(int i=0;i<N;i++)
    {
         double x=sqrt(v[i]);
         if(x!=(int)x){printf("NO\n");}
         else if(Prime[(int)x]==1)printf("YES\n");
    }


return 0;
}
