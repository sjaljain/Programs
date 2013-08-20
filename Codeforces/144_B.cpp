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
    int n,d,l;
    scanf("%d%d%d",&n,&d,&l);
    vector<int> ans(n,1);
    int corrected=0;
    int toachieve=d;
    if(n%2==1)toachieve--;

    int imp=1;

    while(toachieve!=0 && corrected<(n/2)*2)
    {
        //printf("%d - ",toachieve);
        if(toachieve<0 && toachieve<-(l-1)){ans[corrected+1]=l;toachieve+=l-1;corrected+=2;}
        else if(toachieve<0 && toachieve>=-(l-1)){ans[corrected+1]=1-toachieve;toachieve=0;corrected+=2;}
        else if(toachieve>0 && toachieve>(l-1)){ans[corrected]=l;toachieve-=l-1;corrected+=2;}
        else if(toachieve>0 && toachieve<=(l-1)){ans[corrected]=toachieve+1;toachieve=0;corrected+=2;}

    }
    if(toachieve==0)imp=0;
    if(toachieve>0 && toachieve<l && n%2==1){ans[n-1]=toachieve+1;imp=0;}

    if(imp==1){printf("-1");return 0;}
    for(int i=0;i<n;i++)printf("%d ",ans[i]);
    return 0;
}


