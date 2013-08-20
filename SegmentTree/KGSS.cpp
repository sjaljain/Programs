//SPOJ - Maximum Sum KGSS

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
#define MAXN 4000000

struct elem
{
    int max,sum;
    elem(int _max,int _sum){max=_max;sum=_sum;}
};

vector<elem> v(MAXN,elem(0,0));
int a[1000000];
int maxn;
//a contains the original values to be fed in
//tl =0 , tr=n-1 initially, v holds the root of the (sub)tree(intially 1)

//this is the query part
pair<int,int> query (int k,int tl, int tr, int l, int r) {
    int tm = (l + r) / 2;
    //printf("%d %d %d %d %d\n",tm,l,r,tl,tr);
	if (l >= tl && r <= tr)
		return make_pair(v[k].sum,v[k].max);
    else if(tm>=tr)
              return  query(2*k,tl,tr,l,tm);
    else if(tm<tl)
            return query(2*k+1,tl,tr,tm+1,r);
    else
    {
        int x_max=query(2*k,tl,tm,l,tm).second;
        int x_sum=query(2*k,tl,tm,l,tm).first;
        int y_max=query(2*k+1,tm+1,tr,tm+1,r).second;
        int y_sum=query(2*k+1,tm+1,tr,tm+1,r).first;
        return make_pair(max(max(x_sum,y_sum),x_max+y_max),max(x_max,y_max));
    }
}

void update (int pos, int val) {
	int k=pos+maxn/2;
	v[k].max=val;
	v[k].sum=val;
    while(k>1)
    {
        v[k/2].max=max(v[(k/2)*2].max,v[(k/2)*2+1].max);
        v[k/2].sum=max(max(v[(k/2)*2].sum,v[(k/2)*2+1].sum),v[(k/2)*2].max+v[(k/2)*2+1].max);
        k/=2;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(maxn=1;maxn<n;maxn*=2);maxn*=2;

    for(int i=0;i<n;i++)
          scanf("%d",&a[i]);

    for(int i=0;i<n;i++)
    {v[i+maxn/2].max=v[i+maxn/2].sum=a[i];}


    //building the segment tree
    int k=maxn/4;
    while(k>=1)
    {
        for(int i=k;i<2*k;i++)
        {
            v[i].max=max(v[2*i].max,v[2*i+1].max);
            v[i].sum=max(max(v[i*2].sum,v[i*2+1].sum),v[i*2].max+v[i*2+1].max);
        }
        k/=2;
    }

    int q;
    scanf("%d",&q);
    while(q--)
    {
        char c1,c2;
        int x,y;
        scanf("%c%c%d%d",&c1,&c2,&x,&y);

        if(c2=='U')
        {
            int pos=x-1;
            int val=y;
            update(pos,val);
        }
        else printf("%d\n",query(1,x,y,1,maxn/2).first);
        /*for(int i=1;i<maxn;i++)
        {
            printf("%d %d - ",v[i].sum,v[i].max);
        }*/
    }

    return 0;
}
