/* Sajal Jain , 09EC1017
 * SPOJ
 * MINUS
 * KnapSack Dynamic Programming - Tough
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
#define mid 10000

int main()
{
     int T;
     scanf("%d",&T);
     while(T--)
     {
        int N,M;
        scanf("%d%d",&N,&M);
        vector<int> v(2*mid+1,0); //range is from [-10000,+10000]
        vector<int> vcpy(2*mid+1,0);
        vector<int> num(N);
        for(int i=0;i<N;i++)scanf("%d",&num[i]);
        v[mid+num[0]]=1;
        for(int n=1;n<N;n++)
        {
            vector<int> vcpy(v);
            for(int m=0;m<=2*mid;m++)
            {
                //adding the number
                if(m-num[n]>=0 && vcpy[m-num[n]]==1 && n!=N-1)v[m]=1;
                //subtracting the number
                if(m+num[n]<=2*mid  && vcpy[m+num[n]]==1)v[m]=1;
            }

        }


        //achievable numbers
        for(int i=0;i<=2*mid;i++)if(v[i]==1)printf("%d ",i-mid);

     }
     return 0;
}
