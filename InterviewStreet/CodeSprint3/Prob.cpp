/* Sajal Jain , 09EC1017
 * SPOJ
 * HERDING
 * BFS/DFS/Trivial
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

int main()
{
     int T;
     scanf("%d",&T);
     while(T--)
     {
        int A,B,C;
        scanf("%d%d%d",&A,&B,&C);
        if(A>B)swap(A,B);
        int num,den;
        if(C<=0)
        {
            num=0;den=0;
            cout<<num<<"/"<<den<<endl;
            continue;
        }
        else if(C<=A)
        {
            num=C*C;
            den=2*A*B;
        }
        else if(C<=B)
        {
            num=2*C-A;
            den=2*B;
        }
        else if(C<=A+B)
        {
            num=(-1*C*C)+(2*C)*(A+B)-(A*A+B*B);
            den=2*A*B;
        }
        else
        {
            num=1;
            den=1;
        }
        int g=gcd(max(num,den),min(num,den));
        num/=g;
        den/=g;
        cout<<num<<"/"<<den<<endl;

     }
     return 0;
}
