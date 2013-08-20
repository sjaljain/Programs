/* Sajal Jain , 09EC1017
 * Codechef
 * Oct Long Challenge
 * DIAMOND - Dynamic Programming - Medium
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

#define BUF 4096 // block size on my disk is 4KBs
char ibuf[BUF];
int ipt = BUF;
int read_uint() {
while (ipt < BUF && ibuf[ipt] < '0') ipt++;
if (ipt == BUF) {
    fread(ibuf, 1, BUF, stdin);
    ipt = 0;
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
}
int n = 0;
while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
if (ipt == BUF) {
    fread(ibuf, 1, BUF, stdin);
    ipt = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
}
return n;
}

int main()
{
     vector< vector<double> > A(dim, vector<double>(dim,0));
     A[1][1]=1;
     A[2][1]=A[2][2]=0.5;
     for(int i=3;i<dim;i++)
     {
         A[i][1]+=0.5;
         A[i][i]+=0.5;
         for(int j=1;j<=i-2;j++)
               A[i][j]+=0.25*A[i-2][j];
         for(int j=2;j<=i-1;j++)
               A[i][j]+=0.5*A[i-2][j-1];
         for(int j=3;j<=i;j++)
               A[i][j]+=0.25*A[i-2][j-2];
     }

     //displaying the array
     /*
     for(int i=1;i<10;i++)
     {
         for(int j=1;j<=i;j++)
            printf("%lf ",A[i][j]);

        printf("\n");
     }
     */
     int T;
     scanf("%d",&T);
     while(T--)
     {
         int N;scanf("%d",&N);
         double val=0;
         vector<int> v(N+1);

         for(int i=1;i<=N;i++)
            scanf("%d",&v[i]);
            //v[i]=read_uint();

        for(int i=1;i<=N;i++)
            val+=v[i]*A[N][i];

        printf("%lf\n",val);

     }
     return 0;
}
