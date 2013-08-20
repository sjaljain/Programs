/* Sajal Jain , 09EC1017
 * Codeforces- Round 146 Div 2 Problem 3
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

int gcd(int a,int b)
{
    if(a%b==0)return b;
    else return gcd(b,a%b);
}

bool checkcoprime(int a,int b)
{
    if(gcd(a,b)==1)return true;
    else return false;
}

int main()
{
     int N;
     scanf("%d",&N);
     if(N==1){printf("1");return 0;}
     if(N==2){printf("2");return 0;}
     long long int main_prod=0,prod;
     for(int n=N;n>=3;n--)
     {
         int c;
         for(c=n-2;c>=1;c--)
         {
             if(checkcoprime(n,c)&&checkcoprime(n-1,c))
             break;
         }
         prod=n*(n-1)*c;
         if(prod<main_prod){break;}
         else main_prod=prod;
     }
     cout<<main_prod;
     return 0;
}
