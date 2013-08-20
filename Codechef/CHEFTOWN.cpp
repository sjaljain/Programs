/* Sajal Jain , 09EC1017
 * Codechef
 * CHEFTOWN
 * O(n) Sliding Interval
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

int main()
{
    int N,W;
    scanf("%d%d",&N,&W);
    vector<int> H(N);
    for(int i=0;i<N;i++)
          scanf("%d",&H[i]);

    set<int> s;
    int sum=0;
    int ans=0;

    for(int i=0;i<W;i++)
    {
        sum+=H[i];
        s.insert(H[i]);
    }
    set<int>::iterator pos;
    pos=s.end();pos--;
    int min=*(s.begin());
    int max=*pos;


    if(sum==((W*(min+max))/2))
        ans++;

    for(int j=W;j<N;j++)
    {
        s.erase(H[j-W]);
        s.insert(H[j]);
        min=*(s.begin());
        pos=s.end();pos--;
        max=*pos;

        sum+=H[j];sum-=H[j-W];
        if(sum==((W*(min+max))/2))
            ans++;
    }

    printf("%d",ans);

    return 0;
}
