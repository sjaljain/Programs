#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int count=0;
    for(int i=0;i<=sqrt(n);i++)
    {
            for(int j=0;j<=sqrt(m);j++)
            {
                    if(((i*i+j)==n) &&((i+j*j)==m))
                    count++;
                    }
            }
            cout<<count;
    return 0;
}
