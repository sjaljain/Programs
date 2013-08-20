/* Sajal Jain , 09EC1017
 * Codeforces- Round 146 Div 2 Problem 1
 * 1 line description
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
#include <fstream>
using namespace std;

#define pp pair <int,int>
#define inf 999999999
#define MOD 1000000007
#define dim 2001

int main()
{
     string s;
     cin>>s;
     set<char> S;
     for(int i=0;i<s.length();i++)S.insert(s[i]);
     //printf("%d",S.size());
     if(S.size()%2==1)printf("IGNORE HIM!");
     else printf("CHAT WITH HER!");
     return 0;
}
