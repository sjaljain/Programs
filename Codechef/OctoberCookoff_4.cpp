/* Sajal Jain , 09EC1017
 * CodeChef - October 2012 Cookoff- ACM ICPC
 * Problem 4
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

struct player
{
    int index;
    double player_prob;
    player(int _index,double _player_prob){index=_index;player_prob=_player_prob;}

};

bool cmp(const player &p1,const player &p2)
{
    return p1.index<p2.index;
}
int main()
{
     int T;
     scanf("%d",&T);
     while(T--)
     {
        int N,M,P;
        scanf("%d%d%d",&N,&M,&P);
        int K=(int)log2(N);
        //cout<<K<<endl;
        double prob=(double)P/100;
        vector<player> PL;
        int a;
        for(int i=0;i<M;i++){scanf("%d",&a);PL.push_back(player(a-1,1));}
        sort(PL.begin(),PL.end(),cmp);
        while(K--)
        {
            for(int i=0;i<PL.size();i++)
            {


              //both players exist
              //int done=0;
              if(i+1<PL.size() && PL[i+1].index/2==PL[i].index/2)
                  {
                      //cout<<PL[i].index<<" "<<PL[i].player_prob<<endl;
                      PL[i].index=PL[i].index/2;

                      double x,y,z;
                      x=PL[i].player_prob*PL[i+1].player_prob;
                      y=PL[i].player_prob*(1.0-PL[i+1].player_prob)*prob;
                      z=(1.0-PL[i].player_prob)*PL[i+1].player_prob*prob;
                      PL[i].player_prob=x+y+z;
                      //PL[i].player_prob/=10000;
                      PL.erase(PL.begin()+i+1);

                  }

              //else only 1 is player
              else
              {

                  //cout<<" i am i"<<endl;
                  //cout<<PL[i].index<<" "<<PL[i].player_prob<<endl;
                  PL[i].index=PL[i].index/2;
                  PL[i].player_prob*=prob;
              }
            }


        }
        printf("%.14lf\n",PL[0].player_prob*100);




     }
     return 0;
}
