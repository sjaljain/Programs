/* Sajal Jain , 09EC1017
 * Codechef
 * CHEFTOWN
 * O(n) Sliding Interval (Finding max, min in a sliding interval using deque
 * Tutorial at http://www.leetcode.com/2011/01/sliding-window-maximum.html
 *
 * For example, if the current queue has the elements: [10 5 3], and a new element in the window
 * has the element 11. Now, we could have emptied the queue without considering elements 10, 5, and 3,
 * and insert only element 11 into the queue.
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

void maxSlidingWindow(vector<int> &A, int n, int w, vector<int> &B) {
  deque<int> Q;
  for (int i = 0; i < w; i++) {
    while (!Q.empty() && A[i] >= A[Q.back()])
      Q.pop_back();
    Q.push_back(i);
  }
  for (int i = w; i < n; i++) {
    B[i-w] = A[Q.front()];
    while (!Q.empty() && A[i] >= A[Q.back()])
      Q.pop_back();
    while (!Q.empty() && Q.front() <= i-w)
      Q.pop_front();
    Q.push_back(i);
  }
  B[n-w] = A[Q.front()];

}

void minSlidingWindow(vector<int> &A, int n, int w, vector<int> &B) {
  deque<int> Q;
  for (int i = 0; i < w; i++) {
    while (!Q.empty() && A[i] <= A[Q.back()])
      Q.pop_back();
    Q.push_back(i);
  }
  for (int i = w; i < n; i++) {
    B[i-w] = A[Q.front()];
    while (!Q.empty() && A[i] <= A[Q.back()])
      Q.pop_back();
    while (!Q.empty() && Q.front() <= i-w)
      Q.pop_front();
    Q.push_back(i);
  }
  B[n-w] = A[Q.front()];
}

int main()
{
    int N,W;
    scanf("%d%d",&N,&W);
    vector<int> A(N),B(N),C(N);
    for(int i=0;i<N;i++)
          scanf("%d",&A[i]);
    maxSlidingWindow(A,N,W,B);
    minSlidingWindow(A,N,W,C);

    int ans=0;
    for(int i=0;i<N-W+1;i++)
    {
        if(B[i]-C[i]==W-1)ans++;
    }

    cout<<ans;
    return 0;
}
