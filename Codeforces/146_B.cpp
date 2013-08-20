/* Sajal Jain , 09EC1017
 * Codeforces- Round 146 Div 2 Problem 2
 * 1 line description
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
#define inf 999999999
#define MOD 1073741824
#define dim 2001

void precompute(int N,vector<int> &factor)
{
    for(int i=2;i<=N;i++)
    {
        for(int j=i;j<=N;j+=i)
        factor[j]++;
    }
}

int main()
{
     int a,b,c;
     scanf("%d%d%d",&a,&b,&c);
     int N;
     N=a*b*c;
     vector<int> factor(a*b*c+1,1);
     precompute(N,factor);
     //cout<<factor[9409];
     long long int sum=0;
     for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
            for(int k=1;k<=c;k++)
            {
                sum+=factor[i*j*k];
                sum=sum%MOD;
            }

    cout<<sum;
     return 0;
}
