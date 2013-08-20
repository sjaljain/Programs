/* Sajal Jain , 09EC1017
 * CodeChef - October 2012 Cookoff- ACM ICPC
 * Problem 2
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
#define MOD 1000000007
#define dim 2001

struct point
{
    double val;
    int index;
    point(double _val,int _index){val=_val;index=_index;}
};

bool same(vector<point> &v,int N)
{
    double value=v[0].val;
    for(int i=1;i<N;i++)if(v[i].val!=value )return false;
    return true;
}

bool cmp(const point &p1,const point &p2)
{
    return p1.val<p2.val;
}
int prime[]={0,1,2,3,2,5,3,7,2,3,5,11,3,13,7,5,2,17,3,19,5,7,11,23,3,5,13,3,7,29,5};

int main()
{
     int T;
     scanf("%d",&T);
     while(T--)
     {
        int N;
        scanf("%d",&N);
        int p=prime[N];
        //cout<<p<<endl;
        vector<point> v;
        double a;
        for(int i=0;i<N;i++){scanf("%lf",&a);v.push_back(point(a,i+1));}



        //for(int m=0;m<N;m++)printf("%lf ",v[m].val);
        //    cout<<endl;
        int K=0;
        vector<int> Moves[1000];
        if(same(v,N)){printf("0\n");continue;}
        while(!same(v,N))
        {
            K++;
            sort(v.begin(),v.end(),cmp);
            double sum=0,avg=0;
            for(int i=0;i<p/2;i++)
            {
                sum+=v[i].val;
                sum+=v[N-i-1].val;
                Moves[K-1].push_back(v[i].index);
                Moves[K-1].push_back(v[N-i-1].index);
            }
            if(p%2==1)
            {
                sum+=v[(p+1)/2-1].val;
                Moves[K-1].push_back(v[(p+1)/2-1].index);


            }
            avg=sum/(double)p;
            if(p%2==1)v[(p+1)/2-1].val=avg;
            for(int i=0;i<p/2;i++)
            {
                v[i].val=avg;
                v[N-i-1].val=avg;
            }




        }

        printf("%d\n",K);
        for(int i=0;i<K;i++)
        {
            printf("%d ",p);
            sort(Moves[i].begin(),Moves[i].end());
            for(int j=0;j<p;j++)printf("%d ",Moves[i][j]);
            printf("\n");
        }






     }
     return 0;
}
