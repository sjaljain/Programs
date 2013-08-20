#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int T;scanf("%d",&T);
    int n;
    while(T--)
    {
              scanf("%d",&n);
              if(n%2==0)printf("ALICE\n");
              else printf("BOB\n");
              }
              return 0;
}
