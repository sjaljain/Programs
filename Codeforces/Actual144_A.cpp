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


using namespace std;

int main()
{
      int N;
      scanf("%d",&N);
      if(N%2==1){printf("-1");return 0;}
      for(int i=1;i<=N;i++)
      {
          if(i%2==1)printf("%d ",i+1);
          else printf("%d ",i-1);
      }
      return 0;
}
