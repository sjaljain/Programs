/* Sajal Jain , 09EC1017
 * Interview Street
 * Binomial coefficient
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
#define MOD 142857
#define dim 2001

string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);

  ret += "#$";
  return ret;
}

void longestPalindromeIndexing(string s,vector<int> &X) {
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  //cout<<n<<endl;
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)

    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;

    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;

    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }

  // Find the maximum element in P.
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }

  for(int i=2;i<n-1;i+=2)
        X[(i/2)-1]=max(max(P[i],P[i-1]),P[i+1]);


    return ;
  //return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}

int longestPalindrome(string s1,string s2,vector<int> P1,vector<int> P2)
{
    //cout<<s1<<" "<<s2<<endl;
    int *match;
    int n=s1.length();
    match=new int[n];
    for(int i=0;i<n;i++)match[i]=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s1[i]!=s2[i])break;
        cnt++;
        match[i]=cnt;
    }
    //for(int i=0;i<n;i++)cout<<match[i]<<" ";
    //cout<<endl;
    /*
    int *P1,*P2;
    P1=new int[n];
    P2=new int[n];

    longestPalindromeIndexing(s1,P1);
    longestPalindromeIndexing(s2,P2);
    */
    //for(int i=0;i<n;i++)
    //{
    //    cout<<P1[i]<<" "<<P2[i]<<"---";
    //}
    //cout<<endl;
    int max_val=0;
    for(int i=0;i<n;i++)
    {
        int x1=0,x2=0,x3=0,val=0;
        x1=2*match[i];
        val=P1[i];
        if(i-(val/2)-1>=0)x2=val+2*match[i-(val/2)-1];
        x3=max(x1,x2);
        max_val=max(max_val,x3);
        //if(i>1 && match[i]==0)break;

    }
    for(int i=0;i<n;i++)
    {
        int x1=0,x2=0,x3=0,val=0;
        x1=2*match[i];
        val=P2[i];
        if(i-(val/2)-1>=0)x2=val+2*match[i-(val/2)-1];
        x3=max(x1,x2);
        max_val=max(max_val,x3);
        //if(i>1 && match[i]==0)break;

    }
    //cout<<max_val<<endl;
    return max_val;

}

int main()
{
    int n,m;scanf("%d%d",&n,&m);
    char c=getchar();
    vector<string> v;
    int max=0;
    char s[100001];
    for(int i=0;i<n;i++)
    {
        gets(s);
        v.push_back(s);
    }
    vector<vector<int> > P(n,vector<int> (m,0));
    for(int i=0;i<n;i++)
    {
        longestPalindromeIndexing(v[i],P[i]);
    }
    for(int i=0;i<n;i++)
    {
        /*
        vector<string> rev;
        for(int k=0;k<n;k++)
        {
            if(k==i)continue;
            rev.push_back(string(v[k].rbegin(), v[k].rend()));
        }
        sort(rev.begin(),rev.end());
        */
        for(int j=0;j<n;j++)
        {
            vector<int> X(m,0);
            for(int p=0;p<m;p++)
            {
                X[p]=P[j][m-p-1];
            }
            int val=longestPalindrome(v[i],string(v[j].rbegin(), v[j].rend()),P[i],X);
            if(i==j)continue;
            if(max<val)
                max=val;
            //if(max>11*m/12){printf("%d",max);return 0;}
        }
    }
    printf("%d",max);
    return 0;
}
