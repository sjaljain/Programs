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
    int x1,y1,z1;
    scanf("%d%d%d",&x1,&y1,&z1);
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    int a1,a2,a3,a4,a5,a6;
    scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6);
    int ans=0;

    if(y1<0)ans+=a1;
    else if(y1>y)ans+=a2;

    if(z1<0)ans+=a3;
    else if(z1>z)ans+=a4;

    if(x1<0)ans+=a5;
    else if(x1>x)ans+=a6;

    printf("%d",ans);


    return 0;
}


