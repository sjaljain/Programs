/* Sajal Jain , 09EC1017
 * SPOJ
 * MSTRING - Dynamic Programming  - Hard
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
#include <cstring>
#include <fstream>
using namespace std;

#define pp pair <int,int>
#define inf 999999999
#define MOD 1000000007
#define maxn 1007


char a[maxn],b[maxn];
int next[maxn][26],f[maxn];
int main()
{
     scanf("%s%s",a+1,b+1);
     int len1=strlen(a+1);
     int len2=strlen(b+1);
     for(int i=len2-1;i>=0;i--)
     {
         memmove(next+i,next+i+1,sizeof(next[i]));
         next[i][b[i+1]-'a']=i+1;
     }
     memset(f,44,sizeof(f));
     f[0]=0;
     int ans=999999999;
     for(int i=1;i<=len1;i++)
        for(int j=len2;j>=0;j--)
             if(f[j]<len1)
                 if(!next[j][a[i]-'a'])
                    ans=min(ans,f[j]+1);
                 else
                    f[next[j][a[i]-'a']]=min(f[j]+1,f[next[j][a[i]-'a']]);
     printf("%d\n",ans);
     return 0;
 }
