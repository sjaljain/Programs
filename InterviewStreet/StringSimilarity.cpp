//============================================================================
// Name : StringSimilarties.cpp
// Author : Sajal Jain
// Version :
// Copyright : Interview Street 25 points Problem
// Description : Ansi-style
//============================================================================
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

char input[100000];
int Z[100000];

int main() {
   int T;
   scanf("%d", &T);
   while(T--) {
      scanf("%s", &input);
      int N = strlen(input);
      Z[0] = N;
      int l = 0, r = 0;
      /** Operating Z-Function */
      for(int i = 1; i < N; ++i) {
          int k = i < r ? min(r - i, Z[i - l]) : 0;
          cout<<"k="<<k<<" ";
          while(i + k < N && input[i + k] == input[k])
             ++k;
          Z[i] = k;
          if(i + k > r) {
             l = i;
             r = i + k;
          }
          cout<<k<<" "<<l<<" "<<r<<endl;
       }
       int res = 0;
       for(int i = 0; i < N; i++)
          res += Z[i];
       printf("%d\n", res);
     }
     return 0;
}
