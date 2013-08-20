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
using namespace std;

#define pp pair <int,int>
#define inf 999999999
#define MOD 1000000007


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        string s;
        cin>>s;
        int done=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='7')s[i]='4';
            else if(s[i]=='4')
            {
                s[i]='7';
                done=1;
                break;
            }
        }
    if(done)cout<<s<<endl;
    else cout<<"4"<<s<<endl;
    }
    return 0;
}
