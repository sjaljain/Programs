#include<iostream>

using namespace std;

int main()
{
    int n,m,a;
    long long int count;
    cin>>n>>m>>a;
    count=(n+a-1)/a;
    count*=(m+a-1)/a;
    cout<<count;
    //getchar();
    return 0;
 }
