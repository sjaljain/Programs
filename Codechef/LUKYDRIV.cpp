#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string.h>
#define MOD 1000000007

using namespace std;

long long A[5][10];
long long tA[5][10];
long long b[5];
char num[10010];

void solve() {

	scanf("%s",num);

	int l = strlen(num);
    


    for(int i=0; i<=4; i++)
        b[i] = 0;

    for(int i=0; i<=4; i++)
        for(int j=0; j<=8; j++)
            A[i][j] = 0;

    for(int i=3; i<=4; i++)
        for(int j=0; j<=8; j++)
            tA[i][j] = 0;

    for(int i=0; i<l; i++) {
		char nu = num[i];
        int v = nu - 48;

        if(v == 0) {
            b[4] += b[3];
            b[3] += b[2];
            b[2] += b[1];
            b[1] ++;
        }

        if(v == 9)
            v = 0;
        for(int j=0; j<=8; j++) {
            int a = v+j;
            if(a >= 9)
                a -= 9;
            tA[2][a] = A[1][j];
            tA[3][a] = A[2][j];
            A[4][a] += A[3][j];
        }
        A[1][v] ++;


        for(int j=0; j<=8; j++) {
            A[2][j] += tA[2][j];
            if(A[2][j] >= MOD)
                A[2][j] -= MOD;
            tA[2][j] = 0;
            A[3][j] += tA[3][j];
            if(A[3][j] >= MOD)
                A[3][j] -= MOD;
            tA[3][j] = 0;
        }

    }
    long long bak = b[1]+b[2]+b[3]+b[4];
    bak = bak%MOD;
    long long sol = 0;
    sol = (A[1][0] + A[2][0] + A[3][0] + A[4][0])%MOD;
    sol -= bak;
    if(sol < 0)
        sol += MOD;

	printf("%lld\n",sol);

}

int main() {     
	int testCount;
	scanf("%d",&testCount);
    for (int i = 1; i <= testCount; i++)
		solve();
}
