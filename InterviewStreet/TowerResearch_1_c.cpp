/* Sajal Jain , 09EC1017
 * SPOJ
 * PICAD - Dynamic Programming
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
typedef long long LL;


int main()
{
     int T;
     scanf("%d",&T);
     while(T--)
     {
         int p1,p2,alpha,beta,k;
         long long int n;
         scanf("%d %d %d %d %lld %d",&p1,&p2,&alpha,&beta,&n,&k);
         vector<int> seq(k);
         seq[0]=p1;seq[1]=p2;
        for(int i=2;i<k;i++)
        {
            long long int a,b;
            a=LL(alpha)*LL(seq[i-1]);
            //cout<<a<<" ";
            b=LL(beta)*LL(seq[i-2]);
            //cout<<b<<" ";
            //cout<<a<<" "<<b<<" "<<(a+b)<<" "<<(a+b)%n<<" "<<(a+b+n)%n<<endl;
            seq[i]=(int)((a+b+n)%n);

        }
/*
         for(int i=0;i<k;i++)printf("%d ",seq[i]);
         printf("\n");
*/
         int N=k;
         vector<int> incr(N,1),decr(N,1);
         for (int i = 1; i < N; ++i){
            for (int j = 0; j < i; ++j){
                 if (seq[j] < seq[i])
                 {
                     // handle "increasing" step - need to check previous "decreasing" value
                     if (decr[j]+1 > incr[i])  incr[i] = decr[j] + 1;
                 }
                 if (seq[j] > seq[i])
                 {
                     if (incr[j]+1 > decr[i])  decr[i] = incr[j] + 1;
                 }
            }
        }
        int max_val=0;
        for(int i=0;i<N;i++)if(max(incr[i],decr[i])>max_val)max_val=max(incr[i],decr[i]);
        printf("%d\n",max_val);
     }
     return 0;
}

