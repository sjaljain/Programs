/* Sajal Jain , 09EC1017
 * Algorithm Laboratory Autumn 2012
 * EMST algorithm - Rajasekran (Kruskal + Random Cartesian Graph)
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
#define MAX 1000000
#define edge pair<int,int>

using namespace std;

vector< pair<double, edge > > Graph,MST;
int n,m;


struct point
{
    double x,y;
    int index;
    point(double _x,double _y,int _index){x=_x;y=_y;index=_index;}
};

vector<point> Hash[1000][1000];

double dist(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

bool valid(int x,int y,int m)
{
    if(x<0 || y<0 || x>=m || y>=m) return false;
    else return true;
}

void initialize(int n, vector<int> &parent)
{
    for(int i=0; i<n; i++)
    {
        parent[i] = i;
    }
    MST.clear();
    Graph.clear();
}

//finding parent with path compression
int findSet(int x, vector<int> &parent)
{
    if(x!=parent[x])
    {
        parent[x] = findSet(parent[x],parent);
    }
    return parent[x];
}

void kruskal(vector<int> &parent,vector<int> &done,double r,int max_parent)
{
    static int phase=1;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<Hash[i][j].size();k++)
            {
                int ind_p=Hash[i][j][k].index;

                if(done[ind_p])continue;
                if(phase==3)cout<<ind_p<<" --  ";
                for(int x=(int)(-r/(1/sqrt(n)))-1;x<=(int)(r/(1/sqrt(n)))+1;x++)
                {
                    for(int y=(int)(-r/(1/sqrt(n)))-1;y<=(int)(r/(1/sqrt(n)))+1;y++)
                    {
                        if(!valid(i+x,j+y,m))continue;
                        for(int l=0;l<Hash[i+x][j+y].size();l++)
                        {
                            //if(phase!=1)cout<<Hash[i+x][j+y][l].index<<" ";
                            //if(parent[ind]==max_parent)continue;
                            double distance=dist(Hash[i][j][k],Hash[i+x][j+y][l]);
                            int ind1=Hash[i][j][k].index;
                            int ind2=Hash[i+x][j+y][l].index;
                            if(distance<=r && distance!=0)
                            {
                                Graph.push_back(pair<double, edge> (distance,edge(ind1,ind2)));
                                //Graph.push_back(pair<double, edge> (distance,edge(ind1,ind2)));
                                //if(max_parent!=-1)cout<<ind1<<" "<<ind2<<endl;
                            }


                        }
                    }
                }
            }
        }
    }
    sort(Graph.begin(),Graph.end());
    double total = 0.0;
    for(int i=0; i<Graph.size(); i++)
    {
        //if(i%2==1)continue;
        int pu = findSet(Graph[i].second.first,parent);
        int pv = findSet(Graph[i].second.second,parent);
        if(pu!=pv)
        {
            total+=Graph[i].first;
            MST.push_back(Graph[i]);
            parent[pu] = parent[pv];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(parent[i]==i)continue;
        else
        {
            int x=i;
            while(parent[x]!=x)
            {
                x=parent[x];
            }
            parent[i]=x;
        }
    }
    //for(int i=0;i<n;i++)cout<<i<<" "<<parent[i]<<"  ";
    //cout<<endl;1
    //Finding max frequency parent
    vector<int> freq(n,0);
    int num_trees=0;
    int max=0;
    for(int i=0;i<n;i++)
    {
        int y=parent[i];
        if(freq[y]==0)num_trees++;
        freq[y]++;
        if(freq[y]>max){max=freq[y];max_parent=y;}
    }
    //num_trees code
    cout<<"Phase "<<phase<<" of EMST..."<<endl;
    cout<<"+++ Largest tree is of size = "<<max<<endl;
    cout<<"    No of edges in G is "<<Graph.size()<<endl;
    cout<<"    No of edges in T is "<<MST.size()<<endl;
    cout<<"    Number of trees = "<<num_trees<<endl;
    phase++;

    if(num_trees==1)return ;
    for(int i=0;i<n;i++)done[i]=0;
    for(int i=0;i<n;i++)if(parent[i]==max_parent)done[i]=1;//parents are reset
    for(int i=0;i<n;i++)parent[i]=i;//parents are reset

    Graph.clear();
    Graph=MST;
    MST.clear();

    if(phase==1)r=1.1*log(n)/sqrt(n);else r=2*r;
    if(phase==10)return;
    //cout<<max_parent<<" "<<r<<endl;
    kruskal(parent,done,r,max_parent);
    return ;

}


int main()
{
    printf("n ( <500000 ) = ");scanf("%d",&n);
    vector<int> parent(n,0);
    vector<int> done(n,0);
    initialize(n,parent);
    m=(int)floor(sqrt(n));
    double rootn = sqrt(n);

    //Generate n random points
    srand ( time(NULL) );
    vector<point> P;
    for(int i=0;i<n;i++)
    {
         double a=(double)rand() / (double)RAND_MAX;
         double b=(double)rand() / (double)RAND_MAX;
         P.push_back(point(a,b,i));
    }

    for(int i=0;i<n;i++)
    {
        int s=(int)((P[i].x)/(1.0/m));
        int t=(int)((P[i].y)/(1.0/m));
        Hash[s][t].push_back(P[i]);
    }

    //Rajasekran algorithm C1=1.5,C2=1.1 r=ln()
    //Step 1: Construct graphs that are within 1/rootn distance of each other (neighbouring cell check)
    double C1=1.5;
    double r=C1/rootn;

    kruskal(parent,done,r,-1);
    return 0;
}

