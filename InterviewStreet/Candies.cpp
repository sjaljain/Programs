/* Sajal Jain , 09EC1017
 * Interview Street
 * Candies
 * O(n) Ad-Hoc, Identifying valleys
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

/* The maximum possible rating for any child in the class. */
const int kMaxRating = 100000;
/* A pseudo-infinite value that lies beyond the range of possible ratings. */
const int kInfinity  = kMaxRating + 1;
int GetRating(int i, const vector<int>& ratings)
{
  if (i < 0 || i > ratings.size() - 1)
    return kInfinity;
  return ratings[i];
}

int main()
{
  int numChildren;
  cin >> numChildren;
  vector<int> ratings(numChildren);
  for (int i = 0; i < numChildren; ++i)
  cin >> ratings[i];
  vector<int> valleys;
  for (int i = 0; i < numChildren; ++i)
  {
    int ri = GetRating(i, ratings);
    if (ri <= GetRating(i-1, ratings) && ri <= GetRating(i+1, ratings))
      valleys.push_back(i);
  }
  vector<int> candies(numChildren);
  for (vector<int>::iterator itr = valleys.begin(); itr != valleys.end(); ++itr)
  {
    int valley_i = *itr;
    candies[valley_i] = 1;

    int mountain_i = valley_i - 1;
    while (mountain_i >= 0 && ratings[mountain_i] > ratings[mountain_i+1])
    {
       candies[mountain_i] = max(candies[mountain_i], candies[mountain_i+1] + 1);
       --mountain_i;
    }
    mountain_i = valley_i + 1;
    while (mountain_i <= numChildren - 1 &&
           ratings[mountain_i] > ratings[mountain_i-1])
    {
        candies[mountain_i] = candies[mountain_i-1] + 1;
        ++mountain_i;
    }
  }

  cout << accumulate(candies.begin(), candies.end(), 0) << endl;

  return 0;
}
