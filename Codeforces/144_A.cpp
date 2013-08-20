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
    int N;
    scanf("%d",&N);
    int cnt=0;
    while(N--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a+b+c>=2)cnt++;
    }
    printf("%d",cnt);


    return 0;
}


