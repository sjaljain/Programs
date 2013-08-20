/*
Sajal Jain 09EC1017
Assignment 7 - Modified KMP
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
#define MAX 100000



void kmpFailureFunction(char T[],int fail[],int len)
{
    int i=0, j=-1;
    fail[i]=j;
    while (i<len)
    {
        while (j>=0 && T[i]!=T[j]) j=fail[j];
        i++; j++;
        fail[i]=j;
    }
}

void kmpSearch(char T[],int fail[],int len,int lenT,vector<int> &indices)
{
    int i=0, j=0;
    while (i<len)
    {
        while (j>=0 && T[i]!=T[j]) j=fail[j];
        i++; j++;
        if (j==lenT)
        {
            if((i-j-lenT)>=0)
                indices.push_back(i-j-lenT);
            j=fail[j];
        }
    }
}

int main()
{
    char T[MAX];
    char S[MAX];
    vector<int> indices;
    int *fail;
    int len,lenT,lenS;

    printf("*** String matching\n");
    printf("S = ");
    scanf("%s",S);
    printf("T = ");
    scanf("%s",T);
    lenT=strlen(T);
    lenS=strlen(S);
    printf("\nn = |S| = %d\n",lenS);
    printf("m = |T| = %d\n\n",lenT);

    strcat(T,S);
    len=lenT+lenS;

    fail=new int[len+1];

    kmpFailureFunction(T,fail,len);
    kmpSearch(T,fail,len,lenT,indices);

    int matches=indices.size();
    printf("%d matches found at indices ",matches);
    for(int i=0;i<indices.size();i++)
        printf("%d ",indices[i]);

    printf("\n\n");


    char T1[MAX],T2[MAX];
    vector<int> indices1,indices2;
    int *fail1,*fail2;
    printf("*** Pattern matching\n");
    printf("S = ");
    scanf("%s",S);
    printf("T = ");
    scanf("%s",T);

    //Splitting the strings into T1 and T2
    int x=0;
    while(T[x]!='*'){T1[x]=T[x];x++;}T1[x]='\0';
    int y=x+1;
    while(T[y]!='\0'){T2[y-x-1]=T[y];y++;}T2[y-x-1]='\0';

    int lenT1=strlen(T1);
    int lenT2=strlen(T2);
    lenT=lenT1+lenT2;
    lenS=strlen(S);
    printf("\nn = |S| = %d\n",lenS);
    printf("m = |T| = %d\n\n",lenT);


    strcat(T1,S);
    len=lenT1+lenS;
    fail1=new int[len+1];

    kmpFailureFunction(T1,fail1,len);
    kmpSearch(T1,fail1,len,lenT1,indices1);

    strcat(T2,S);
    len=lenT2+lenS;
    fail2=new int[len+1];

    kmpFailureFunction(T2,fail2,len);
    kmpSearch(T2,fail2,len,lenT2,indices2);

    printf("Pattern matches at index pairs ");
    for(int i=0;i<indices1.size();i++)
        for(int j=0;j<indices2.size();j++)
        {
            if(indices2[j]>=indices1[i]+lenT1)printf("(%d,%d) ",indices1[i],indices2[j]);
        }

    printf("\n");



    return 0;
}
