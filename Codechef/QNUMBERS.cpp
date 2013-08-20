/* Sajal Jain , 09EC1017
 * Codechef
 * QNUMBERS
 * O(QlogN) check for every query
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


void prime_compute(long long int n, vector<int> &p)
{
    vector<int> v((int)sqrt(n)+2,1);
    for(int i=2;i<=sqrt(n);i++)
    {
        int j=i*2;
        while(j<=sqrt(n)){v[j]=0;j+=i;}
    }
    for(int i=2;i<=sqrt(n)+1;i++)
    if(v[i]==1)p.push_back(i);

    return ;
}

int count_factors(long long int n, vector<int> &p)
{
long long int initial_n = n;
int num_factors = 1;
for (long long int i = 0; p[i] * p[i] <= initial_n; ++i) // for each number i up until the square root of the given number
{
    int power = 0; // suppose the power i appears at is 0
    while (n % p[i] == 0) // while we can divide n by i
    {
        n = n / p[i]; // divide it, thus ensuring we'll only check prime factors
        ++power; // increase the power i appears at
    }

    num_factors = num_factors * (power + 1); // apply the formula
    if(i+1>p.size() || n==1)break;

}

if (n > 1) // will happen for example for 14 = 2 * 7
{
    num_factors = num_factors * 2; // n is prime, and its power can only be 1, so multiply the number of factors by 2
}

return num_factors;
}

void GetFactors(unsigned long long int x, set<unsigned long long int>& factors)
{
  /* Cache the square root of the specified integer for efficiency. */
  unsigned long long int sqrtX = (unsigned long long int)sqrt(x);

  /* We can find all factors of x by iterating from 1 to the square root of x,
   * inclusive.
   */
  for (unsigned long long int i = 1; i <= sqrtX; ++i)
  {
    if (x % i == 0)
    {
      factors.insert(i);
      factors.insert(x/i);
    }
  }
  return ;
}



unsigned long long int gcd(unsigned long long int u, unsigned long long int v)
{
    if(v==0)return u;
    else return gcd(v,u%v);
}

int trav_distance(unsigned long long int x, set<unsigned long long int> factors)
{
    set<unsigned long long int>::iterator pos;
    //cout<<"x= "<<x<<" ";
    int trav=0;
    for(pos=factors.begin();pos!=factors.end();pos++)
    {
        if(x%(*pos)==0)trav++;
        if(*pos==x){return trav;}

    }

}

int main()
{

  unsigned long long int N;
  int Q;

  scanf("%llu%d",&N,&Q);

  vector<int> p;
  prime_compute(N,p);
  set<unsigned long long int> factors;

  GetFactors(N,factors);
  int F=factors.size();

  for(int i=1;i<=Q;i++)
  {
      int type;
      unsigned long long int K;
      scanf("%d%llu",&type,&K);
      //cout<<gcd(N,K);

      if(type==1)
             //printf("%d\n",count_factors(gcd(N,K),p));
             printf("%d\n",trav_distance(gcd(N,K),factors));
      else
      {
            int type2;
            if(N%K!=0)type2=0;
            else {type2=count_factors(N/K,p);}

            if(type==2)printf("%d\n",type2);
            else printf("%d\n",F-type2);
      }

  }
  return 0;
}
