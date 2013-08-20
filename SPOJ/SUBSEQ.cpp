/* Sajal Jain , 09EC1017
 * SPOJ
 * SUBSEQ - Prefiz Sum Array + Map
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
      int T;scanf("%d",&T);
      while(T--)
      {
          int N;scanf("%d",&N);
          map<long long int,int> M;
          vector<int> v(N),sum(N);
          for(int i=0;i<N;i++)scanf("%d",&v[i]);
          sum[0]=v[0];
          for(int i=1;i<N;i++){sum[i]=sum[i-1]+v[i];}

          M.insert(pair<long long int,int>(0,1));
          //M[0]=1;

          int count=0;
          for(int i=0;i<N;i++)
          {
              if(M.find(sum[i]-47)!=M.end())
                count+=M.find(sum[i]-47)->second;
              if(M.find(sum[i])==M.end())
                    M.insert(pair<long long int,int>(sum[i],1));
                    //M[sum[i]]=1;
              else
                    M.find(sum[i])->second++;
          }
          /*
        cout << "mymap contains:\n";
        map<long long int,int>::iterator it;
        for ( it=M.begin() ; it != M.end(); it++ )
            cout << (*it).first << " => " << (*it).second << endl;
        */

          printf("%d\n",count);
      }


    return 0;
}
