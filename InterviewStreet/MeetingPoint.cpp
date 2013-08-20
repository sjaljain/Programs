
/* Sajal Jain , 09EC1017
 * Interview Street
 * Meeting Point
 * O(n) Chebyshev distance conversion from Manhattan distance
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


int main()
{
    long long int N;
    cin>>N;
    long long int min=inf;
    vector< pp > cheby;
    vector<int> manhattenx,manhatteny,manhattenx2,manhatteny2;
    long long int dist=0;
    int x,y;
    if(N<1000)
    {
        vector< pp > v;
        for(int i=0;i<N;i++)
        {
            int a,b;
            cin>>a>>b;
            v.push_back(pp(a,b));
        }
        for(int i=0;i<N;i++)
        {
            long long int sum=0;
            for(int j=0;j<N;j++)
            {
                sum+=max(abs(v[i].first-v[j].first),abs(v[i].second-v[j].second));
            }
            if(sum<min)min=sum;
        }
        cout<<min;
        return 0;
    }
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        cheby.push_back(pp(a,b));
        manhattenx.push_back(b-a);
        manhatteny.push_back(b+a);
        manhattenx2.push_back(b-a);
        manhatteny2.push_back(b+a);

    }
    int med_x,med_y;
    nth_element(manhattenx2.begin(),manhattenx2.begin()+(N/2),manhattenx2.end());
    med_x=manhattenx2[N/2];
    nth_element(manhatteny2.begin(),manhatteny2.begin()+(N/2),manhatteny2.end());
    med_y=manhatteny2[N/2];
    //cout<<med_x<<med_y<<endl;
    for(int i=0;i<N;i++)
    {
        dist=abs(manhattenx[i]-med_x)+abs(manhatteny[i]-med_y);
        if(dist<min){min=dist;x=manhattenx[i];y=manhatteny[i];}
    }

    //for(int i=0;i<N;i++){cout<<manhattenx[i]<<" "<<manhatteny[i]<<endl;}

    min=inf;
    nth_element(manhattenx2.begin(),manhattenx2.begin()+(N-1/2),manhattenx2.end());
    med_x=manhattenx2[(N-1)/2];
    nth_element(manhatteny2.begin(),manhatteny2.begin()+(N-1/2),manhatteny2.end());
    med_y=manhatteny2[(N-1)/2];
    //cout<<med_x<<med_y<<endl;

    min=dist;
    for(int i=0;i<N;i++)
    {
        dist=abs(manhattenx[i]-med_x)+abs(manhatteny[i]-med_y);
        if(dist<min){min=dist;x=manhattenx[i];y=manhatteny[i];}
    }
    //for(int i=0;i<N;i++){cout<<manhattenx[i]<<" "<<manhatteny[i]<<endl;}

    dist=0;
    //cout<<x<<y<<endl;
    int point_x,point_y;
    point_x=(y-x)/2;
    point_y=(x+y)/2;
    //cout<<point_x<<point_y<<endl;

    for(int i=0;i<N;i++)
    {
        dist+=max(abs(cheby[i].first-point_x),abs(cheby[i].second-point_y));
    }
    cout<<dist;
    return 0;
}
