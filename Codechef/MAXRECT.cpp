/* Sajal Jain , 09EC1017
 * Codechef
 * Oct Long Challenge
 * MAXRECT - NP Hard Problem
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


int main()
{
    int N,M;
    scanf("%d%d",&M,&N);
    vector< vector<int> > A(M, vector<int>(N));

    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
             scanf("%d",&A[i][j]);


    vector<int> Row(M,1);
    vector<int> Col(N,1);

    int count_c=N,count_r=M;

    while(1)
    {

        int min_c,min_r;
        vector<long long int> Sum_c(N,0);
        vector<long long int> Sum_r(M,0);
        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
            {
                Sum_c[j]+=A[i][j];
                Sum_r[i]+=A[i][j];
            }
    /*
     for(int i=0;i<M;i++)
        printf("%d ",Sum_r[i]);

    printf("\n");

    for(int i=0;i<N;i++)
        printf("%d ",Sum_c[i]);

    printf("\n");
    */

    //Find min row or column
    long long int sum_c=Sum_c[0];
    for(int i=0;i<N;i++)
        if(Sum_c[i]<=sum_c){sum_c=Sum_c[i];min_c=i;}

    long long int sum_r=Sum_r[0];
    for(int i=0;i<M;i++)
        if(Sum_r[i]<=sum_r){sum_r=Sum_r[i];min_r=i;}

    if((sum_c>=0 && sum_r>=0)|| (count_r==1 && count_c==1)) break;

    if(sum_c<=sum_r && count_c>1)
    {
        Col[min_c]=0;
        count_c--;
        for(int i=0;i<M;i++)
        {
            A[i][min_c]=0;
        }
    }
    else
    {
        Row[min_r]=0;
        count_r--;
        for(int i=0;i<N;i++)
        {
            A[min_r][i]=0;
        }
    }
    }
    //Second editions

    for(int i=0;i<M;i++)
    {
        if(Row[i]==1)continue;
        int ans=0;
        for(int j=0;j<N;j++)
        {
            if(Col[j]==0)continue;
            ans+=A[i][j];
        }
        if(ans>0){Row[i]=1;count_r++;}
    }
    for(int j=0;j<N;j++)
    {
        if(Col[j]==1)continue;
        int ans=0;
        for(int i=0;i<M;i++)
        {
            if(Row[i]==0)continue;
            ans+=A[i][j];
        }
        if(ans>0){Col[j]=1;count_c++;}
    }

    printf("%d %d\n",count_r,count_c);
    for(int i=0;i<M;i++)
        if(Row[i]!=0)printf("%d ",i);

    printf("\n");

    for(int i=0;i<N;i++)
        if(Col[i]!=0)printf("%d ",i);


    return 0;
}

