/* Sajal Jain , 09EC1017
 * Codechef
 * Oct Long Challenge
 * LUCKY10 - Bruteforce
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
#define dim 2001


int main()
{

     int T;
     scanf("%d",&T);
     while(T--)
     {
         char s1[20001],s2[20001];
         //char *s1,*s2;
         scanf("%s",s1);
         scanf("%s",s2);
         int grps1_13=0,grps1_4=0,grps1_56=0,grps1_7=0,grps1_89=0;
         int grps2_13=0,grps2_4=0,grps2_56=0,grps2_7=0,grps2_89=0;

         for(int i=0;i<strlen(s1);i++)
         {
             if(s1[i]-'0'<=3)grps1_13++;
             else if(s1[i]-'0'==4)grps1_4++;
             else if(s1[i]-'0'>4 && s1[i]-'0'<=6)grps1_56++;
             else if(s1[i]-'0'==7)grps1_7++;
             else if(s1[i]-'0'>7)grps1_89++;
         }
         for(int i=0;i<strlen(s2);i++)
         {
             if(s2[i]-'0'<=3)grps2_13++;
             else if(s2[i]-'0'==4)grps2_4++;
             else if(s2[i]-'0'>4 && s2[i]-'0'<=6)grps2_56++;
             else if(s2[i]-'0'==7)grps2_7++;
             else if(s2[i]-'0'>7)grps2_89++;
         }
         //cout<<grps1_13<<" "<<grps1_4<<" "<<grps1_56<<" "<<grps1_7<<" "<<grps1_89<<endl;
         //cout<<grps2_13<<" "<<grps2_4<<" "<<grps2_56<<" "<<grps2_7<<" "<<grps2_89<<endl;

         int k;
         int count7=0,count4=0;
         if(grps1_7!=0)
         {
             k=min(grps1_7,grps2_56);
             count7+=k;grps1_7-=k;grps2_56-=k;
         }
         if(grps1_7!=0)
         {
             k=min(grps1_7,grps2_13);
             count7+=k;grps1_7-=k;grps2_13-=k;
         }
         if(grps1_7!=0)
         {
             k=min(grps1_7,grps2_4);
             count7+=k;grps1_7-=k;grps2_4-=k;
         }
         if(grps1_7!=0)
         {
             k=min(grps1_7,grps2_7);
             count7+=k;grps1_7-=k;grps2_7-=k;
         }

         if(grps2_7!=0)
         {
             k=min(grps2_7,grps1_56);
             count7+=k;grps2_7-=k;grps1_56-=k;
         }
         if(grps2_7!=0)
         {
             k=min(grps2_7,grps1_13);
             count7+=k;grps2_7-=k;grps1_13-=k;
         }
         if(grps2_7!=0)
         {
             k=min(grps2_7,grps1_4);
             count7+=k;grps2_7-=k;grps1_4-=k;
         }
         if(grps2_7!=0)
         {
             k=min(grps2_7,grps1_7);
             count7+=k;grps2_7-=k;grps1_7-=k;
         }



         if(grps1_4!=0)
         {
             k=min(grps1_4,grps2_13);
             count4+=k;grps1_4-=k;grps2_13-=k;
         }
         if(grps1_4!=0)
         {
             k=min(grps1_4,grps2_4);
             count4+=k;grps1_4-=k;grps2_4-=k;
         }
         if(grps2_4!=0)
         {
             k=min(grps2_4,grps1_13);
             count4+=k;grps2_4-=k;grps1_13-=k;
         }
         if(grps2_4!=0)
         {
             k=min(grps2_4,grps1_4);
             count4+=k;grps2_4-=k;grps1_4-=k;
         }



        //cout<<grps1_13<<" "<<grps1_4<<" "<<grps1_56<<" "<<grps1_7<<" "<<grps1_89<<endl;
        //cout<<grps2_13<<" "<<grps2_4<<" "<<grps2_56<<" "<<grps2_7<<" "<<grps2_89<<endl;

        while(count7--)
            printf("7");
        while(count4--)
            printf("4");
        printf("\n");

     }
     return 0;
}
