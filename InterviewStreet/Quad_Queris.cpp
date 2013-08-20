/* Sajal Jain , 09EC1017
 * Interview Street
 * Quadrant Queries
 * Segment Tree Basic
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
using namespace std;

#define pp pair <int,int>
#define inf 999999999

int n=1;

struct segment
{
    int start_index; //start_index of points
    int end_index; //end_index of points
    int count; //count of number of points in each quadrant
};

struct point
{
    int x,y;
    int quad;
    point(int _x,int _y)
    {
        x=_x;y=_y;
        if(x>0 && y>0)quad=1;
        else if(x<0 && y>0)quad=2;
        else if(x<0 && y<0)quad=3;
        else quad=4;
    }
};

void X_insert(segment S[5][1000], int start, int end, int node);
void Y_insert(segment S[5][1000], int start, int end, int node);
int query(segment *S, int start, int end, int node);


int main()
{
    int N;cin>>N;
    vector<point> v;
    for(int i=0;i<N;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back(point(x,y));
    }

    //Storing multiple of 2 just greater than N

    while(n<N)n*=2;
    n*=2;
    //Initialization :S[1] will contains the full interval, S[2] S[3] half intervals and so on
    segment S[5][1000];

    int j;
    for(j=0;j<n/2;j++)
    {
        for(int k=1;k<=4;k++)
        {
            S[k][n/2+j].start_index=j+1;
            S[k][n/2+j].end_index=j+1;
            S[k][n/2+j].count=0;
        }
        if(j<N)
        S[v[j].quad][n/2+j].count=1;
    }
    int k=n/2;
    while(k>1)
    {
        k/=2;
        for(int i=0;i<k;i++)
        {
            for(int m=1;m<=4;m++)
            {
                S[m][k+i].start_index=S[m][2*(k+i)].start_index;
                S[m][k+i].end_index=S[m][2*(k+i)+1].end_index;
                S[m][k+i].count=S[m][2*(k+i)].count+S[m][2*(k+i)+1].count;
            }
        }
    }

    int Q;
    cin>>Q;
    while(Q--)
    {
        int count[5]={0};

        char c;
        int p,q;
        cin>>c>>p>>q;
        if(c=='X')
        {
            X_insert(S,p,q,0);
        }
        else if(c=='Y')
        {
            Y_insert(S,p,q,0);
        }
        else
        {
            for(int i=1;i<=4;i++)
            {
                 count[i]=query(S[i],p,q,0);
                 cout<<count[i]<<" ";
            }
            cout<<endl;
        }


    }

    return 0;
}

//Segment Tree Update procedure
void X_insert(segment S[5][1000], int start, int end, int node)
{
    int mid=(S[1][node].start_index+S[1][node].end_index)/2;
    if(S[1][node].start_index>=start && S[1][node].end_index<=end)//In the region
    {
        int quad1=S[1][node].count;
        int quad2=S[2][node].count;
        int quad3=S[3][node].count;
        int quad4=S[4][node].count;
        while(node!=0)
        {
            node/=2;
            S[1][node].count+=quad4-quad1;
            S[2][node].count+=quad3-quad2;
            S[3][node].count+=quad2-quad3;
            S[4][node].count+=quad1-quad4;

        }
        return ;
    }
    else if(mid>=end){X_insert(S,start,end,node*2);}
    else if(mid<start){X_insert(S,start,end,2*node+1);}
    else
    {
      X_insert(S,start,mid,node*2);
      X_insert(S,mid+1,end,2*node+1);
    }

}

void Y_insert(segment S[5][1000], int start, int end, int node)
{
    int mid=(S[1][node].start_index+S[1][node].end_index)/2;
    if(S[1][node].start_index>=start && S[1][node].end_index<=end)//In the region
    {
        int quad1=S[1][node].count;
        int quad2=S[2][node].count;
        int quad3=S[3][node].count;
        int quad4=S[4][node].count;
        while(node!=0)
        {
            node/=2;
            S[1][node].count+=quad2-quad1;
            S[2][node].count+=quad1-quad2;
            S[3][node].count+=quad4-quad3;
            S[4][node].count+=quad3-quad4;

        }
        return ;
    }
    else if(mid>=end){Y_insert(S,start,end,node*2);}
    else if(mid<start){Y_insert(S,start,end,2*node+1);}
    else
    {
      Y_insert(S,start,mid,node*2);
      Y_insert(S,mid+1,end,2*node+1);
    }

}

int query(segment *S, int start, int end, int node)
{
    //Segment Tree Query using Lazy Propagation
    int mid=(S[node].start_index+S[node].end_index)/2;
    if(S[node].start_index>=start && S[node].end_index<=end)
            return S[node].count;
    else if(mid>=end){return query(S,start,end,node*2);}
    else if(mid<start){return query(S,start,end,2*node+1);}
    else
            return query(S,start,mid,node*2)+ query(S,mid+1,end,2*node+1);


}

