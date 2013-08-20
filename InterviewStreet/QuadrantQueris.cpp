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



struct segment
{
    int start_index; //start_index of points
    int end_index;
    int X_query;
    int Y_query;
    int num[5];
    segment()
    {
        for(int i=0;i<5;i++)num[i]=0;
        }//Numbers in each quadrant
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

void insert(segment *S, int start, int end, int node,char c);
void query(segment *S, int start, int end, int node,int *count,int ,int);

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
    //Construct the segment tree
    int n=1;
    while(n<N)n*=2; //Storing multiple of 2 just greater than N
    n*=2;
    //cout<<n;
    segment S[n];
    //Initialization
    int j;
    for(j=0;j<N;j++)
    {
        S[n/2+j].start_index=j+1;
        S[n/2+j].end_index=j+1;
        S[n/2+j].num[v[j].quad]=1;
        S[n/2+j].X_query=0;
        S[n/2+j].Y_query=0;
    }
    for(;j<n/2;j++)
    {
        S[n/2+j].start_index=j+1;
        S[n/2+j].end_index=j+1;
        S[n/2+j].X_query=0;
        S[n/2+j].Y_query=0;
    }
    int k=n/2;
    while(k>1)
    {
        k/=2;
        for(int i=0;i<k;i++)
        {
            S[k+i].start_index=S[2*(k+i)].start_index;
            S[k+i].end_index=S[2*(k+i)+1].end_index;
            for(int m=1;m<=4;m++)
                   S[k+i].num[m]=S[2*(k+i)].num[m]+S[2*(k+i)+1].num[m];
            S[k+i].X_query=0;
            S[k+i].Y_query=0;
        }
    }
    //Initialization is complete
//    for(int i=1;i<n;i++)
//    {
//        cout<<S[i].start_index<<" "<<S[i].end_index<<" ";
//        for(int v=1;v<=4;v++)
//            cout<<S[i].num[v]<<" ";
//        cout<<endl;
//    }
    //Query & Lazy Propagation starts
    int Q;
    cin>>Q;
    while(Q--)
    {
        int count[5]={0};

        char c;
        int p,q;
        cin>>c>>p>>q;
        if(c=='X' || c=='Y')
             insert(S,p,q,1,c);
        else query(S,p,q,1,count,0,0);

        for(int i=1;i<=4;i++)
               cout<<count[i]<<" ";
        cout<<endl;
        for(int i=1;i<n;i++)
        {
            cout<<S[i].start_index<<" "<<S[i].end_index<<" ";
            for(int v=1;v<=4;v++)
                cout<<S[i].num[v]<<" ";
            cout<<S[i].X_query<<" "<<S[i].Y_query;
            cout<<endl;
        }

        cout<<endl;
    }

    return 0;
}

//Segment Tree Update procedure
void insert(segment *S, int start, int end, int node,char c)
{
     int mid=(S[node].start_index+S[node].end_index)/2;
     cout<<mid<<"a"<<" ";
     if(S[node].start_index>=start && S[node].end_index<=end)
     {
         if(c=='X'){S[node].X_query=(S[node].X_query+1)%2;}
         else S[node].Y_query=(S[node].Y_query+1)%2;
         return;
     }
     else if(mid>=end){insert(S,start,end,node*2,c);}
     else if(mid<start){insert(S,start,end,2*node+1,c);}
     else
     {
         insert(S,start,mid,node*2,c);
         insert(S,mid+1,end,2*node+1,c);
     }
     return ;
}

void query(segment *S, int start, int end, int node,int *count, int X,int Y)
{
    //Segment Tree Query using Lazy Propagation

    int mid=(S[node].start_index+S[node].end_index)/2;
    if(S[node].start_index>=start && S[node].end_index<=end)
     {
         X+=S[node].X_query;
         Y+=S[node].Y_query;

         cout<<node<<endl;
         if(X%2==1)
         {
             swap(S[node].num[1],S[node].num[4]);
             swap(S[node].num[2],S[node].num[3]);
             S[node].X_query++;
             }
        if(Y%2==1)
         {
             swap(S[node].num[1],S[node].num[2]);
             swap(S[node].num[4],S[node].num[3]);
             S[node].Y_query++;
             }
        for(int i=1;i<=4;i++){count[i]+=S[node].num[i];}
        return ;

    }
     else if(mid>=end){query(S,start,end,node*2,count,X+S[node].X_query,Y+S[node].Y_query);}
     else if(mid<start){query(S,start,end,2*node+1,count,X+S[node].X_query,Y+S[node].Y_query);}
     else
     {
         query(S,start,mid,node*2,count,X+S[node].X_query,Y+S[node].Y_query);
         query(S,mid+1,end,2*node+1,count,X+S[node].X_query,Y+S[node].Y_query);
     }
     //Question Specific

    return ;

}

