#include<iostream>
using namespace std;
#include<vector>

#define MOD 142857
#define MAX 10000
int C[MAX+1][MAX/2+1];

void precompute()
{
	for (int i=0; i<=MAX; i++)
	{
		for (int k=0; k<=MAX/2 && k<=i; k++)
			if (k==0 || k==i)
				C[i][k] = 1;
			else
				C[i][k] = (C[i-1][k-1] + C[i-1][k])%MOD;
	}

}
int main()
{
    int t;scanf("%d",&t);
    precompute();
    while(t--)
    {
        int N,K;
        scanf("%d%d",&N,&K);
        if(K>N/2)K=N-K;
        printf("%d\n",C[N][K]);
    }
	return 0;
}
