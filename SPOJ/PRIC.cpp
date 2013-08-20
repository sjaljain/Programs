/* Sajal Jain , 09EC1017
 * SPOJ
 * PRIC
 * Miller Rabin Primality Testing
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

/* This function calculates (a^b)%c */
int modulo(int a,int b,int c){
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; // squaring the base
        b /= 2;
    }
    return x%c;
}

bool Fermat(long long p,int iterations){
    if(p == 1){ // 1 isn't prime
        return false;
    }
    for(int i=0;i<iterations;i++){
        // choose a random integer between 1 and p-1 ( inclusive )
        long long a = rand()%(p-1)+1;
        // modulo is the function we developed above for modular exponentiation.
        if(modulo(a,p-1,p) != 1){
            return false; /* p is definitely composite */
        }
    }
    return true; /* p is probably prime */
}

int main()
{
        long long int P;
        P =(int)(pow((double)2,(double)31));
        P=P+1;
        //printf("%lld\n",P);
        long long x=1;
        int t=333333;
        //int t=50;
        while(t--){

                if(Fermat(x,10)){
                        printf("1");
                }else{
                        printf("0");
                }
                x=(x+1234567890+P)%P;
                //printf("%lld\n",x);
        }

        return 0;
}

