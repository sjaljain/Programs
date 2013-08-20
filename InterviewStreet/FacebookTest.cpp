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

int convert_state(vector<int> v);
int next_state(int);
int goal_state(int);
int main()
{
    int N,K;
    cin>>N>>K;
    vector<int> v(N,0),g(N,0);
    for(int i=0;i<N;i++)
            cin>>v[i];
    for(int i=0;i<N;i++)
        cin>>g[i];

    int a=convert_state(v);
    int b=convert_state(g);

    queue<int> Q;
    Q.push(a);
    while(!Q.empty())
    {
        vector<int> x;
        next_state(Q.top(),x,K);
        for(int j=0;j<x.size();j++)
            {
             if(x[j]==b){done=1;break;}
             Q.push(x[j]);
            }
        cout<<Q.top()<<endl;
        Q.pop();

    }
    return 0;
}

int convert_state(vector<int> v)
{
    int x=1,ans;
    for(int i=v.size()-1;i>=0;i--)
    {
        ans+=v[i]*x;
        x*=10;
    }
    return ans;
}

int next_state(int y,vector<int> x,int K)
{
    vector<int> v;
    while(y!=0)
    {
        v.push_back(y%10);
        y/=10;
    }
    vector<int> s;
    for(int j=v.size()-1;j>=0;j++)
        s.push_back(v[j]);

    set<int> z;
    z.insert(v[0]);
    for(int i=0;i<s.size();i++)
    {
        for(int j=1;j<=K,j++)
        {
            if(z.find(j)==z.end())

        }
    }

}
