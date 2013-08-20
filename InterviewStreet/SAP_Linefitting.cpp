/* Sajal Jain , 09EC1017
 * Interview Street
 * Line fitting - Approximation algorithm
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
#include <cstring>
#include <fstream>
using namespace std;

#define pp pair <int,int>
#define inf 999999999
#define MOD 1000000007
#define maxn 1007

int N,D;

struct point
{
    int x,y;
    point(int _x,int _y){x=_x;y=_y;}
};

double slope(point a,point b)
{
    return (b.y-a.y)/(b.x-a.x);
}

point upper(point a)
{
    point u(0,0);
    u.x=a.x;
    u.y=a.y+D;
    return u;
}

point lower(point a)
{
    point u(0,0);
    u.x=a.x;
    u.y=a.y-D;
    return u;
}

bool cmp(const point &a,const point &b)
{
    return a.x<b.x;
}

int main()
{

    scanf("%d%d",&N,&D);
    vector<point> v;
    for(int j=0;j<N;j++)
    {
        int i,p;
        scanf("%d%d",&i,&p);
        v.push_back(point(i,p));
    }
    sort(v.begin(),v.end(),cmp);

    vector<point> ans;
    ans.push_back(v[0]);

    point p=v[0];
    double maxSlope=inf;
    double minSlope=-inf;

    int i=1;
    while(i<N)
    {


        if(!(slope(p,v[i])<maxSlope && slope(p,v[i])>minSlope))
            {
                ans.push_back(v[i-1]);
                p=v[i-1];
                maxSlope=inf;
                minSlope=-inf;
            }

        if(slope(p,upper(v[i]))<maxSlope)maxSlope=slope(p,upper(v[i]));
        if(slope(p,lower(v[i]))>minSlope)minSlope=slope(p,lower(v[i]));
        i++;
    }
    ans.push_back(v[N-1]);
    printf("%d\n",ans.size()-1);
    for(int i=0;i<ans.size();i++)
    {
        printf("%d %d\n",ans[i].x,ans[i].y);
    }
   return 0;
}
