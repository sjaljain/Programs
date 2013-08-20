#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cassert>
#include <climits>
#include <functional>
#include <bitset>

#define dim 2
#define FOR(k,a,b) for(typeof(a) k=(a); k < (b); ++k)
typedef long long LL;
using namespace std;

double Phi = 1.618033988749;

int main()
{
    vector<double> D(1000001);
    vector<int> Sum(1000001,0);
    for(int n=1;n<1000;n++)
    {
        /*
        D[n]=pow(Phi,2-Phi);
        D[n]*=pow(n,3*(Phi-1));
        */
        D[n]=floor((pow(2*n,1.5)+1)/2);
        printf("%d %.1llf - ",n,D[n]);
    }

    for(int n=1;n<1000001;n++)
    Sum[n]=Sum[n-1]+(int)D[n];

    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        printf("%d\n",(int)Sum[N]);
    }

    return 0;
}


