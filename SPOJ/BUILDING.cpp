//SPOJ - BUILDING - AdHoc (Line Sweep)

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
#define MOD 1000000007



int main()
{
    int n;
    scanf("%d",&n);
    vector<int> H(n+1,0),ans(n,0);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&H[i]);
    }
    int maxh=0;
    for(int i=0;i<n;i++)
    {
        if(H[i]>maxh)maxh=H[i];
    }
    for(int h=1;h<=maxh;h++)
    {
        int i=0;
        while(i<n)
        {
            int start=i;
            while(H[i]>=h)
                i++;
            int end=i;
            if(end==start){i++;continue;}
            int L=end-start;
            for(int j=start,x=0;j<end;j++,x++)
            {
                ans[j]+=(L-x)*(x+1);
            }
        }


    }
    for(int i=0;i<n;i++)
        {
            printf("%d ",ans[i]);
        }
    return 0;
}
