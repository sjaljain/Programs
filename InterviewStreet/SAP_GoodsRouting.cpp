/* Sajal Jain , 09EC1017
 * Interview Street
 * Flow Algorithm approximation (Greedy)
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
#define INF 999999999
#define MOD 1000000007

int N,M;
void floydWarshall (vector<vector<double> > &graph, vector<vector<int> > &parent)
{
    vector<vector<double> > dist;
    vector<double> v(N,inf);
    vector<int> v1(N,inf);
    for(int i=0;i<N;i++)
    {
        dist.push_back(v);
        parent.push_back(v1);
    }
    int i, j, k;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            dist[i][j] = graph[i][j];
            if(graph[i][j]!=inf)parent[i][j]=i;
        }


    for (k = 0; k < N; k++)
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    parent[i][j]=k;
                }

            }
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        graph[i][j]=dist[i][j];
    }
}

struct boys
{
    double cost,time;
    int pos;
    vector<pp> path;
    boys(double _cost,double _time,int _pos){cost=_cost;time=_time;pos=_pos;}
};

void find_path(boys &b,int start,int end,vector<vector<int> > parent)
{
    while(parent[start][end]!=start)
    {
        b.path.push_back(make_pair(start,parent[start][end]));
        start=parent[start][end];
    }
    b.path.push_back(make_pair(start,end));
}


int main()
{

    scanf("%d%d",&N,&M);
    vector<int> dest(M);for(int i=0;i<M;i++)scanf("%d",&dest[i]);
    vector<vector<double> > dist,time,cost;
    vector<vector<int > > costparent,timeparent;

    vector<double> v(N,inf);
    vector<int> v1(N,inf);
    for(int i=0;i<N;i++)
    {
        dist.push_back(v);
        time.push_back(v);
        cost.push_back(v);
        costparent.push_back(v1);
        timeparent.push_back(v1);
    }

    for(int i=0;i<N-1;i++)
    {
        int x,y;
        double distance;
        double p;
        scanf("%d %d %lf %lf",&x,&y,&distance,&p);
        dist[x][y]=distance;
        time[x][y]=distance/p;
        dist[y][x]=distance;
        time[y][x]=distance/p;
    }

    int costboy,speed,costpetrol,T;
    scanf("%d%d%d%d",&costboy,&speed,&costpetrol,&T);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cost[i][j]=dist[i][j]*costpetrol;
            time[i][j]=time[i][j]*60/speed;
        }
    }
    floydWarshall(cost,costparent);
    floydWarshall(time,timeparent);

    vector<boys> B;
    int boy_num=0;
    B.push_back(boys(costboy,0,0));

    vector<int> covered(N,1);
    for(int i=0;i<M;i++)covered[dest[i]]=0;

/*
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        printf("%.1lf ",cost[i][j]);

        printf("\n");
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        printf("%.1lf ",time[i][j]);

        printf("\n");
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        printf("%d ",costparent[i][j]);

        printf("\n");
    }
*/

    //Take 2 parameters - cost and time and compare with a new Delievery boy
    while(M)
    {
        double min_costval=inf;
        int min_costind=0;
        double min_timeval=inf;
        int min_timeind=0;

        //printf("pos = %d \n",B[boy_num].pos);
        for(int i=0;i<N;i++)
        {
            if(covered[i]==1)continue;
            for(int j=0;j<B.size();j++)
            {
                if(cost[B[j].pos][i]<min_costval && (time[B[j].pos][i]+B[j].time)<T)
                {
                    boy_num=j;
                    min_costval=cost[B[boy_num].pos][i];
                    min_costind=i;
                    min_timeval=time[B[boy_num].pos][i];
                    min_timeind=i;
                }
            }
                /*
                if(time[B[boy_num].pos][i]<min_timeval)
                {
                    min_timeval=cost[B[i].pos][i];
                    min_timeind=i;
                }
                */
        }
        //printf("%lf %d\n",min_costval,min_costind);
        if(B[boy_num].time+min_timeval>T)
        {
            //printf("time exceedded\n");
            B.push_back(boys(costboy,0,0));
            boy_num=B.size()-1;
            //printf("new boy created\n");
            continue;
        }
        //if(costboy+cost[0][min_costind]>min_costval && time[0][min_timeind]>min_timeval){B.push_back(boys(costboy,0,0));boy_num++;continue;}
        if(costboy+cost[0][min_costind]<min_costval)
        {
            //printf("new boy is better\n");
            B.push_back(boys(costboy,0,0));
            boy_num=B.size()-1;
            B[boy_num].cost+=cost[0][min_costind];
            find_path(B[boy_num],0,min_costind,costparent);
            B[boy_num].pos=min_costind;
            B[boy_num].time+=time[B[boy_num].pos][min_costind];
            covered[min_costind]=1;
            M--;
        }
        else
        {
            B[boy_num].cost+=cost[B[boy_num].pos][min_costind];
            find_path(B[boy_num],B[boy_num].pos,min_costind,costparent);
            B[boy_num].pos=min_costind;
            B[boy_num].time+=time[B[boy_num].pos][min_costind];
            covered[min_costind]=1;
            //printf("sol1 covered\n");
            M--;
        }
    }
    double amount=0;
    for(int i=0;i<B.size();i++)
    {
        printf("%d\n",B[i].path.size());
        for(int j=0;j<B[i].path.size();j++)
            printf("%d %d\n",B[i].path[j].first,B[i].path[j].second);

        amount+=B[i].cost;
    }
    //printf("%lf\n",amount);

   return 0;
}

