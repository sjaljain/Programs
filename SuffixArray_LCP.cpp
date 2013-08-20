/*
Tested at:
http://www.spoj.pl/problems/DISUBSTR/
http://www.spoj.pl/problems/SUBST1/

*/

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#define MAX 500001
using namespace std;

char str[MAX]; //input
int Rank[MAX], suffixArray[MAX]; //output
int cnt[MAX], Next[MAX]; //internal
bool bh[MAX], b2h[MAX];
int Height[MAX];
char msg[250001];

// Compares two suffixes according to their first characters
bool smaller_first_char(int a, int b)
{
        return str[a] < str[b];
}

void print(int index)
{
        for(int i=index;i<strlen(str);++i)
        {
                cout<<str[i];
        }
        cout<<endl;
}

//function that contains the index of the starting position of the suffix according to the rank
//for ABABA suffixArray holds 4 2 0 3 1

void suffixSort(int n){
        //sort suffixes according to their first characters
        for (int i=0; i<n; ++i){
                suffixArray[i] = i;
        }
        sort(suffixArray, suffixArray + n, smaller_first_char);
        //{suffixArray contains the list of suffixes sorted by their first character}

        for (int i=0; i<n; ++i){
                bh[i] = i == 0 || str[suffixArray[i]] != str[suffixArray[i-1]];
                b2h[i] = false;
        }

        for (int h = 1; h < n; h <<= 1){
                //{bh[i] == false if the first h characters of suffixArray[i-1] == the first h characters of suffixArray[i]}
                int buckets = 0;
                for (int i=0, j; i < n; i = j){
                        j = i + 1;
                        while (j < n && !bh[j]) j++;
                        Next[i] = j;
                        buckets++;
                }
                if (buckets == n) break; // We are done! Lucky bastards!
                //{suffixes are separted in buckets containing strings starting with the same h characters}

                for (int i = 0; i < n; i = Next[i]){
                        cnt[i] = 0;
                        for (int j = i; j < Next[i]; ++j){
                                Rank[suffixArray[j]] = i;
                        }
                }

                cnt[Rank[n - h]]++;
                b2h[Rank[n - h]] = true;
                for (int i = 0; i < n; i = Next[i]){
                        for (int j = i; j < Next[i]; ++j){
                                int s = suffixArray[j] - h;
                                if (s >= 0){
                                        int head = Rank[s];
                                        Rank[s] = head + cnt[head]++;
                                        b2h[Rank[s]] = true;
                                }
                        }
                        for (int j = i; j < Next[i]; ++j){
                                int s = suffixArray[j] - h;
                                if (s >= 0 && b2h[Rank[s]]){
                                        for (int k = Rank[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
                                }
                        }
                }
                for (int i=0; i<n; ++i){
                        suffixArray[Rank[i]] = i;
                        bh[i] |= b2h[i];
                }
        }
        for (int i=0; i<n; ++i)
        {
                Rank[suffixArray[i]] = i;
        }
        /*
        for (int i=0; i<n; ++i)
        {
                cout<<suffixArray[i]<<" ";
        }cout<<endl;*/
}
// End of suffix array algorithm


//function that calculates LCP
//For ABABA Height holds 0 1 3 0 2

void getHeight(int n)
{
        for (int i=0; i<n; ++i) Rank[suffixArray[i]] = i;
        Height[0] = 0;
        for (int i=0, h=0; i<n; ++i)
        {
                if (Rank[i] > 0)
                {
                        int j = suffixArray[Rank[i]-1];
                        while (i + h < n && j + h < n && str[i+h] == str[j+h])
                        {
                                h++;
                        }
                        Height[Rank[i]] = h;
                        if (h > 0) h--;
                }
        }
        /*
        for (int i=0; i<n; ++i)
        {
                cout<<Height[i]<<" ";
        }cout<<endl;*/
}
// End of longest common prefixes algorithm
int main()
{

        char tc[6];
        gets(tc);
        int T=atoi(tc);
        while(T--)
        {
                gets(str);
                int Len=strlen(str);

                suffixSort(Len);
                getHeight(Len);

                //use suffixArray and Height 1D arrays

                int diff,suffixsize,results=0;
                for(int i=0;i<Len;++i)
                {
                        suffixsize=(Len-suffixArray[i]);
                        diff=suffixsize-Height[i];
                        results=results+diff;
                }
                printf("%d\n",results);

        }
        return 0;
}
/*
consider the folowing example:
ABABA

first we construct suffix array for this string:
1 A 0
2 ABA 1
3 ABABA 3
4 BA 0
5 BABA 2

Each number in third column shows the longest common prefix (LCP) of consecutive suffixes
for example LCP[5]=2 because LCP BA and BABA is BA and 2 is the length of BA


now the first question is :what is substring?
ans:any substring of string S is a prefix of some suffixes of S


now we know what we should do!!!!!!
scan the suffix array from start to end:
LCP [1]=0 //no common prefix with last element so because the length of A is one we can only construct one substring P[1]=1
LCP[2]=1 //so ignore all common cases with last suffix and count the remainder substrings: AB,ABA =3-1 ,P[2]=2 ,3 is length(SUFFIX[2]) and 1 is LCP[1]
LCP[3]=3 /// distinct substring are: ABAB ,ABABA => 5-3 ,P[3]=2
.....
.....
.....
let P[i]=length(SUFFIX[i])-LCP[i]
obviosly the sum of all P[i] will give us the number of distinct substrings of S
*/
