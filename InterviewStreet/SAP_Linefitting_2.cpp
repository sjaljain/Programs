/* Sajal Jain , 09EC1017
 * Interview Street
 * Line fitting - Approximation algorithm
 * Douglas-Peucker algorithm
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

int N,D,total;

struct point
{
    int x,y;
    point(int _x,int _y){x=_x;y=_y;}
};

double distance(point a,point p,point q)
{
    double line_y=p.y+((q.y-p.y)*(a.x-p.x))/(q.x-p.x);
    return abs(a.y-line_y);
}


bool cmp(const point &a,const point &b)
{
    return a.x<b.x;
}

void simplify(vector<point> &v,vector<int> &mark, int start,int end);

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
    vector<int> mark(N,0);
    mark[0]=1;mark[N-1]=1;
    total=2;
    simplify(v,mark,0,N-1);
    printf("%d\n",total);
    for(int i=0;i<N;i++)
    {
        if(mark[i]){printf("%d %d\n",v[i].x,v[i].y);}
    }

   return 0;
}

void simplify(vector<point> &v,vector<int> &mark, int start,int end)
{
    if(start>=end)return;
    int max_ind=-1;
    double max_val=0;
    for(int i=start+1;i<end;i++)
    {
        double dist=distance(v[i],v[start],v[end]);
        if(dist>D)
        {
            if(dist>max_val)
            {
                max_val=dist;
                max_ind=i;
            }
        }
    }
    if(max_val==0)return;
    mark[max_ind]=1;total++;
    simplify(v,mark,start,max_ind);
    simplify(v,mark,max_ind,end);
}
