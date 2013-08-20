/* Sajal Jain , 09EC1017
 * Interview Street
 * Unlucky Numbers
 * O(n) Math, Factors of a number and gcd calculation
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
#define MOD 10000007

//Binary GCD algorithm
unsigned long long int gcd(unsigned long long int u, unsigned long long int v)
{
  int shift;
  if (u == 0) return v;
  if (v == 0) return u;
  for (shift = 0; ((u | v) & 1) == 0; ++shift) {
    u >>= 1;
    v >>= 1;
  }

  while ((u & 1) == 0)
    u >>= 1;

  do {

    while ((v & 1) == 0)  /* Loop X */
      v >>= 1;

    if (u > v) {
      unsigned long long int t = v; v = u; u = t;  // Swap u and v.
    }
    v = v - u;                       // Here v >= u.
  } while (v != 0);

  /* restore common factors of 2 */
  return u << shift;
}

/* Function: GetFactors(x)
 * Usage: set<int> factors;
 *        GetFactors(12, factors);
 * -----------------------------------------------------------------------------
 * Updates the provided set to include all factors of the specified number.
 */
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
}

/* Function: IntersectSets(const set<int>& set1, const set<int>& set2)
 * Usage: set<int> intersection = IntersectSets(set1, set2);
 * -----------------------------------------------------------------------------
 * A simple wrapper function that returns a new set containing only the elements
 * that exist in both set1 and set2.
 */
template <typename T>
set<T> SetDifference(const set<T>& set1, const set<T>& set2)
{
  set<T> difference;
  set_difference(set1.begin(), set1.end(),
                 set2.begin(), set2.end(),
                 insert_iterator<set<T> >(difference,
                                          difference.begin()));
  return difference;
}

int main()
{

  unsigned long long int numUnfriendlies, friendly;


  cin >> numUnfriendlies;
  cin >> friendly;

  /* Read in all of the unfriendly numbers into a vector. */
  vector<unsigned long long int> unfriendlies(numUnfriendlies);
  for (unsigned long long int i = 0; i < numUnfriendlies; ++i)
    cin >> unfriendlies[i];

  set<unsigned long long int> friendlyFactors;
  GetFactors(friendly, friendlyFactors);

  set<unsigned long long int> unfriendlyFactors;
  for (vector<unsigned long long int>::iterator itr = unfriendlies.begin();
       itr != unfriendlies.end(); ++itr)
  {
    unsigned long long int unfriendly = *itr;

    /* Find the GCD between the friendly number and this unfriendly number. */
    unsigned long long int g = gcd(friendly, unfriendly);


    unfriendlyFactors.insert(g);
    GetFactors(g, unfriendlyFactors);
  }

  set<unsigned long long int> difference = SetDifference(friendlyFactors, unfriendlyFactors);
  cout << difference.size() << endl;

  return 0;
}
