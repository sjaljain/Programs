
#include <stdio.h>
#include <math.h>
#include <map>
#include <utility>
#include <vector>
#include <iostream>
#define Prime 27
//#define P 142857
//#define P 1009
using namespace std;
int N,K;
int binomial[50][50];
int main()
{

	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d %d",&N,&K);
		int answer=1;
		long long Ncpy=N,Kcpy=K;
		int P[]={27,11,13,37};
		int ans[4];
		for(int m=0;m<4;m++)
		{
		    int choose[100][100];
            for (int i=0; i<1009; i++) {
            choose[i][0]=choose[i][i]=1;
            for (int j=1; j<i; j++) choose[i][j] = (choose[i-1][j]+choose[i-1][j-1])%P[m];
            }
                  int ret = 1;
                  while (N>0 || K>0) {
                  int a = N%P[m];
                  int b = K%P[m];
                  N/=P[m];
                  K/=P[m];
                  if (a<b) ret = 0;
                  else ret = (ret*choose[a][b])%P[m];
        }
        ans[m]=ret;
        N=Ncpy;K=Kcpy;
		}

		//printf("%d %d %d %d\n",ans[0],ans[1],ans[2],ans[3]);
		for(int i=0;i<142857;i++)
		{
		    if(i%27!=ans[0])continue;
		    if(i%11!=ans[1])continue;
		    if(i%13!=ans[2])continue;
		    if(i%37!=ans[3])continue;
		    printf("%d\n",i);break;
		}
	}

    return 0;
}
