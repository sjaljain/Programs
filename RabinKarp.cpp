/* Sajal Jain , 09EC1017
 * SPOJ
 * PLD - String Pallindromes of length K
 *
 */

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <set>
#include <stdlib.h>
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
#define SIZE 234567

vector< multiset<int> > array;
int N,K,th,total;
char str[40000];

void check(int hval,int place)
{
    int i;
    if(array[hval].find(place-(K%2?2:1))!=array[hval].end())
    {
        if(th<=30)
        {
            for(i=0;i<th;i++)
            {
                if(str[place+i]!=str[place-i-(K%2?2:1)]) return;
            }
        }
        total++;
    }
}

int main()
{
    int i,mod,hval;
    array.resize(SIZE);
    scanf("%d%s", &K, str);
    N=strlen(str);
    if(K>N) {printf("0\n"); return 0;}
    if(K==1) {printf("%d\n",N); return 0;}
    th=K/2;
    mod=1;
    hval=0;
    for(i=0;i<N;i++) str[i]-='a';

    //preparing hash values of length K/2 for all substrings
    for(i=th-1;i>=0;i--)
    {
        hval+=(str[i])*mod;
        if(i!=0)
        mod*=27;
        mod%=SIZE;
        hval%=SIZE;
    }
    array[hval].insert(th-1);
    for(i=th;i<N;i++)
    {
        hval-=mod*str[i-th];
        while(hval<0) hval+=SIZE;
        hval*=27;
        hval+=str[i];
        hval%=SIZE;
        array[hval].insert(i);
    }
    mod=1;
    hval=0;
    //finding hash values of substrings (of length K/2) in reverse order
    for(i=N-th;i<=N-1;i++)
    {
        hval+=(str[i])*mod;
        if(i!=N-1)
        mod*=27;
        mod%=SIZE;
        hval%=SIZE;
    }
    check(hval,N-th);
    for(i=N-th-1;i>=0;i--)
    {
        hval-=mod*str[i+th];
        while(hval<0) hval+=SIZE;
        hval*=27;
        hval+=str[i];
        hval%=SIZE;
        check(hval,i);//checking if the values match -> its a pallindrome
    }
    printf("%d\n",total);
    return 0;
}
