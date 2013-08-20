/* Sajal Jain , 09EC1017
 * Interview Street DP 20 points
 * Interval Selection - Sorting + DP
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
#define MOD 1000000007
#define pchar(c) putchar_unlocked(c)//op[opsz++] = c

struct interval
{
    int start;
    int end;
    interval(int _start,int _end){start=_start;end=_end;}
};

bool Cmp(const interval &a,const interval &b)
{
    if(a.end<b.end)return true;
    else if(b.end==a.end) return a.start<b.start;
    else return false;
}

int main()
{

    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        vector<interval> v;
        for(int i=0;i<N;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v.push_back(interval(a,b));
        }
        sort(v.begin(),v.end(),Cmp);

        vector<int> interval0(N,0);
        vector<int> interval1(N,0);
        interval0[0]=v[0].end-v[0].start;
        interval1[0]=interval0[0];

        for(int i=1;i<N;i++)
        {
            interval0[i]=v[i].end-v[i].start;
            if(v[i].start>v[i-1].end){interval1[i]=interval0[i];}
            else
            {
                int max=0,j=i-1;
                while(v[i].start<=v[j].end && j>=0)
                {
                    if(interval0[j]>max)max=interval0[j];
                    j--;
                }
                interval1[i]=interval0[i]+max;
            }

        }
        int max=0;
        for(int i=0;i<N;i++)
        {
            if(interval1[i]>max)max=interval1[i];
        }
        printf("%d\n",max);


    }
    return 0;
}

