/* Sajal Jain , 09EC1017
 * Interview Street Codesprint Bowling
 * Hard DP
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
#define inf 9999999
#define MOD 1000000007
#define dim 2001

int main()
{
     vector<vector<int> >score(102,vector<int> (300,0));

     //computing scores and updating
     for(int n=1;n<=12;n++)
     {
         for(int n1=0;n1<=10;n1++)
         {
             for(int n2=0;n2+n1<=10;n2++)
             {
                 for(int s=0;s<=200;s++)
                 {
                     if(n==1)if(s==n1+n2){score[n][s]++;continue;}
                     if(s-n1-n2>=0){score[n][s]=((score[n][s]+score[n-1][s-n1-n2]))%MOD;}
                     //if(n>=2)
                 }

             }
         }
     }


     for(int i=0;i<=10;i++)
     {
         printf("%d ",score[3][i]);
     }
     printf("\n");

     int T;scanf("%d",&T);
     while(T--)
     {
         int N,M;
         scanf("%d%d",&N,&M);
         printf("%d\n",score[N][M]);
     }


    return 0;
}
