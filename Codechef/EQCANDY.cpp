/* Sajal Jain , 09EC1017
 * Codechef
 * Next Magic Number
 * Brute Force Strings
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

#define pp pair <int,int>
#define inf 999999999
#define MOD 1000000007

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


using namespace std;


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        N=read_uint();
        vector<int> v(N,0);
        for(int i=0;i<N;i++)v[i]=read_uint();

        long long int sum=0;
        int max=v[0],dum_max;
        for(int i=0;i<N;i++)
        {
            sum+=v[i];
            dum_max=sum/(i+1);
            if(dum_max<=max)max=dum_max;
        }
        printf("%d\n",max);
    }
    return 0;
}
