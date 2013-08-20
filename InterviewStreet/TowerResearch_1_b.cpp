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


using namespace std;
int main()
{
     int T;
     scanf("%d",&T);
     while(T--)
     {
         int p1,p2,alpha,beta,n,k;
         scanf("%d %d %d %d %d %d",&p1,&p2,&alpha,&beta,&n,&k);
         vector<int> a(k);
         a[0]=p1;a[1]=p2;
         for(int i=2;i<k;i++)
         {


            long long int a1,b;
            a1=LL(alpha)*LL(a[i-1]);
            //cout<<a<<" ";
            b=LL(beta)*LL(a[i-2]);
            //cout<<b<<" ";
            //cout<<a<<" "<<b<<" "<<(a+b)<<" "<<(a+b)%n<<" "<<(a+b+n)%n<<endl;
            a[i]=(int)((a1+b+n)%n);



         }
         long long int i=1;
         long long int count1 =1;
         while(i<k)
            {

            if(a[i]>=a[i-1])
            {
                      while((a[i]>=a[i-1])&&i<k)
                      i++;
            count1++;
            }
             if(a[i]<a[i-1])
            {
                      while((a[i]<=a[i-1])&&i<k)
                      i++;
            count1++;
            }

           }



       printf("%d\n",count1);
     }

    return 0;
}
