/* Sajal Jain , 09EC1017
 * Codechef
 * CARVANS
 * Simple - AdHoc
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
using namespace std;

#define pp pair <int,int>
#define inf 999999999
#define MOD 10000009

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        string s;
        cin>>s;
        int ans=1;
        for(int i=0,j=s.length()-1;i<=j;i++,j--)
        {
            if(s[i]==s[j] && s[i]=='?')
                ans=(ans*26)%MOD;
            else if(s[i]!='?' && s[j]!='?' && s[i]!=s[j])
                {ans=0;break;}

        }
        printf("%d\n",ans);
    }
    return 0;
}
