/* Sajal Jain , 09EC1017
 * Codeforces
 * Round 144 - Problem A
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

int sumdigits(int n)
{
    int ans=0;
    while(n>0)
    {
        ans+=n%10;
        n/=10;
    }
    return ans;
}


int main()
{
      long long int N;
      cin>>N;
      int sN=(int)sqrt(N);

      for(int i=sN;i>=1;i--)
      {
          if(N%i!=0)continue;
          if(i+sumdigits(i)==N/i){printf("%d",i);return 0;}
      }
      printf("-1");
      return 0;
}
