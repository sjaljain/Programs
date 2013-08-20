/* Sajal Jain , 09EC1017
 * Codechef NOV Cookoff
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

int main(int argv, char** args)
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,M;
        scanf("%d%d",&N,&M);
        vector<vector<int> > A(N,vector<int> (M));
        vector<vector<char> > B(N,vector<char> (M));
        char ch;
        scanf("%c",&ch);

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                scanf("%c",&B[i][j]);
                A[i][j]=B[i][j]-'0';
            }
            scanf("%c",&ch);

        }
      /*
        for(int i=0;i<N;i++)
        {

            for(int j=0;j<M;j++)
                cout<<A[i][j]<<" ";

        cout<<endl;
        }
        */

        int ans=0;
        for(int p=0;p<=9;p++)
        {
            int dp[100][100][10]={0};
            dp[0][0][A[[0][0]]=1;
            dp[0][0][(A[[0][0]+p)%10]=1;


            for(int i=0;i<N;i++)
            {
                for(int j=0;j<M;j++)
                {
                    dp[0][0][A[[i][j]]=1;
                    dp[0][0][(A[[i][j]+p)%10]=1;
                    if(i==0 && j==0)continue;
                    if(i==0)
                    {
                            /*
                            int m=max(A[i][j],(A[i][j]+p)%10);
                            for(int k2=m;k2>=0;k2--)
                                dp[i][j][k2]=dp[i][j][k2]+1;
                            for(int k2=m+1;k2<=9;k2++)
                                dp[i][j][k2]=dp[i][j-1][k2];
                            */
                            for(int k=0;k<=9;k++)
                            {
                                int m=min(k,(k+p)%10);
                                for(int k2=m;k2<=9;k2++)
                                {
                                    dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k2]+1)
                                }
                            }

                    }
                    else if(j==0)
                    {
                            int m=max(A[i][j],(A[i][j]+p)%10);
                            for(int k2=m;k2>=0;k2--)
                                dp[i][j][k2]=dp[i][j][k2]+1;
                            for(int k2=m+1;k2<=9;k2++)
                                dp[i][j][k2]=dp[i][j-1][k2];

                    }
                    else
                    {
                           int m=max(A[i][j],(A[i][j]+p)%10);
                            for(int k2=m;k2>=0;k2--)
                                dp[i][j][k2]=max(dp[i][j-1][k2]+1,dp[i-1][j][k2]+1);
                            for(int k2=m+1;k2<=9;k2++)
                                dp[i][j][k2]=max(dp[i][j-1][k2],dp[i-1][j][k2]);
                    }
                }
            }
            ans=max(ans,dp[N-1][M-1][0]);
            for(int i=0;i<N;i++)
            {

            for(int j=0;j<M;j++)
                cout<<dp[i][j][0]<<" ";

            cout<<endl;
            }

        }

    printf("%d\n",ans);
    }
    return 0;
}
