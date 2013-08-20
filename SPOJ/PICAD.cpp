/* Sajal Jain , 09EC1017
 * SPOJ
 * PICAD - Dynamic Programming
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

struct event
{
    int time,type;
    event(int _time,int _type){time=_time;type=_type;}
};

bool cmp(const event &a,const event &b)
{
    if(a.time==b.time)return a.type<b.type;
    else
    return a.time<b.time;
}

int main()
{
     int start,end;
     scanf("%d%d",&start,&end);
     int N;scanf("%d",&N);
     vector<event> v;
     for(int i=0;i<N;i++)
     {
         int s,e;
         scanf("%d%d",&s,&e);
         v.push_back(event(s,0));
         v.push_back(event(e,2));
     }

     v.push_back(event(start,1));//dummy events
     v.push_back(event(end,1));

     sort(v.begin(),v.end(),cmp);

     int max=0,min=inf,count=0;

     for(int i=0;i<2*N+2;i++)
     {
         if(v[i].type==0)//start of an event
         {
             if(v[i].time>end)//ignore the case
                continue;
             else if(v[i].time<start) count++;
             else
             {
                 count++;
                 if(count>max)max=count;
             }

         }
         else if(v[i].type==2)//ending of an event
         {
             if(v[i].time>=end)//ignore the case
                continue;
             else if(v[i].time<start)count--;
             else
             {
                 count--;
                 if(count<min)min=count;
             }
         }
         else
         {
             if(count>max)max=count;
             if(count<min)min=count;
         }

     }

     printf("%d %d\n",min,max);
     //scanf("%d",&min);
     return 0;
 }


