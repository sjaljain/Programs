/* Sajal Jain , 09EC1017
 * Algorithm Laboratory Autumn 2012
 * Greedy Graph (NP complete)
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
#include <stdlib.h>
#include <time.h>

#define inf 1000000000
int search_num=10;

struct point
{
    double x,y;
    point(double _x,double _y){x=_x;y=_y;}
};

double dist(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

bool valid(int x,int y,int m)
{
    if(x<0 || y<0 || x>=m || y>=m) return false;
    else return true;
}

using namespace std;

int main()
{
    int n;
    printf("n = ");scanf("%d",&n);
    int m=(int)floor(sqrt(n));

    //Generate n random points
    srand ( time(NULL) );
    vector<point> P;
    for(int i=0;i<n;i++)
    {
         double a=(double)rand() / (double)RAND_MAX;
         double b=(double)rand() / (double)RAND_MAX;
         P.push_back(point(a,b));
    }

    vector<point> Hash[m][m];

    for(int i=0;i<n;i++)
    {
        int s=(int)((P[i].x)/(1.0/m));
        int t=(int)((P[i].y)/(1.0/m));
        Hash[s][t].push_back(P[i]);
    }

    //Computing hashtable statistics
    int max_size=0,min_size=inf;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
        {
            if(Hash[i][j].size()>max_size)max_size=Hash[i][j].size();
            if(Hash[i][j].size()<min_size)min_size=Hash[i][j].size();
        }


    vector<int> Cellsize(max_size+1,0);
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            Cellsize[Hash[i][j].size()]++;

    printf("Minimum number of points in a cell = %d\n",min_size);
    printf("Maximum number of points in a cell = %d\n",max_size);

    for(int i=min_size;i<=max_size;i++)
    {
        printf("\t%d cells with %d points\n",Cellsize[i],i);
    }

    //Searching for the nearest point to a query

    while(search_num--)
    {
        point Q(0,0);
        Q.x=(double)rand() / (double)RAND_MAX;
        Q.y=(double)rand() / (double)RAND_MAX;
        printf("+++ Search for point closest to (%lf,%lf)\n",Q.x,Q.y);
        int s=(int)((Q.x)/(1.0/m));
        int t=(int)((Q.y)/(1.0/m));

        int r=0;
        double min_dist=inf;
        point init_point(0,0),final_point(0,0);

        while(min_dist==inf)
        {
            for(int i=-r;i<=r;i++)
            {
                for(int j=-r;j<=r;j++)
                {
                    if(max(abs(i),abs(j))<r)continue;//already covered squares
                    if(!valid(s+i,t+j,m))continue;//the index is not vald
                    for(int k=0;k<Hash[s+i][t+j].size();k++)
                    {
                        if(min_dist>dist(Q,Hash[s+i][t+j][k]))
                        {
                            min_dist=dist(Q,Hash[s+i][t+j][k]);
                            init_point=Hash[s+i][t+j][k];
                        }

                    }
                }
            }
            r++;
        }
        final_point=init_point;
        printf("\tInitial search gives    (%lf,%lf)\n",init_point.x,init_point.y);

        int final_r=2*r;
        while(r!=final_r)
        {
            for(int i=-r;i<=r;i++)
            {
                for(int j=-r;j<=r;j++)
                {
                    if(max(abs(i),abs(j))<r)continue;//already covered squares
                    if(!valid(s+i,t+j,m))continue;//the index is not valid
                    for(int k=0;k<Hash[s+i][t+j].size();k++)
                    {
                        if(min_dist>dist(Q,Hash[s+i][t+j][k]))
                        {
                            min_dist=dist(Q,Hash[s+i][t+j][k]);
                            final_point=Hash[s+i][t+j][k];
                        }

                    }
                }
            }
            r++;
        }
        printf("\tThe correct result is   (%lf,%lf)\n\n",final_point.x,final_point.y);

    }






    return 0;
}

