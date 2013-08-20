/* Sajal Jain , 09EC1017
 * Codeforces
 * Round 144 - Problem A
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


using namespace std;

int main()
{
      int K;scanf("%d",&K);
      int P[101]={0},C[101]={0};
      for(int i=3;i<=100;i++)
      P[i]=i*(i-1)*(i-2)/6;

      for(int i=2;i<=100;i++)
      C[i]=i*(i-1)/2;

      int A[101][101];
      for(int i=1;i<=100;i++)for(int j=1;j<=100;j++)A[i][j]=0;


      int k=0;
      for(k=3;P[k]<=K;k++);k--;
      K-=P[k];
      int init_k=k;
      for(int i=1;i<=k;i++)for(int j=1;j<=k;j++)if(i!=j)A[i][j]=1;
      int chance=0;
      while(K!=0)
      {
          chance++;
          for(k=2;C[k]<=K;k++);k--;
          K-=C[k];
          //printf("%d %d\n",K,k);
          for(int j=1;j<=k;j++)A[init_k+chance][j]=1;
          for(int i=1;i<=k;i++)A[i][init_k+chance]=1;

      }
      printf("100\n");
      for(int i=1;i<=100;i++)
      {
          for(int j=1;j<=100;j++)
            printf("%d",A[i][j]);
        printf("\n");
      }
      return 0;
}
