/* Sajal Jain , 09EC1017
 * SPOJ
 * PICAD - Dynamic Programming
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
#include <cstring>
#include <fstream>
using namespace std;

#define pp pair <int,int>
#define inf 999999999
#define MOD 1000000007
#define maxn 1007

typedef long long LL;

int main()
{
     int T;
     scanf("%d",&T);
     while(T--)
     {
         int p1,p2,alpha,beta,n,k;
         scanf("%d %d %d %d %d %d",&p1,&p2,&alpha,&beta,&n,&k);
         vector<int> v(k,0);
         v[0]=p1;v[1]=p2;
         int count=0;
         for(int i=2;i<k;i++)
         {
            long long int a,b;
            a=LL(alpha)*LL(v[i-1]);
            b=LL(beta)*LL(v[i-2]);
            v[i]=(int)((a+b+n)%n);
            if(i>5)
                {
                    if(v[i]==v[i-1] && v[i-2]==v[i-3] && v[i]==v[i-2])break;
                    if(v[i]==v[i-2] && v[i-1]==v[i-3]){count=k-i;break;}
                }
         }

         vector<int> seq1(k),seq2(k);
         seq1[0]=v[0];seq2[0]=v[0];
         int size1=1,size2=1;


         for(int i=1;i<k;i++)
         {
                //solving seq 1
                if(i>5)
                {
                    if(v[i]==v[i-1] && v[i-2]==v[i-3] && v[i]==v[i-2])break;
                    if(v[i]==v[i-2] && v[i-1]==v[i-3]){count=k-i;break;}
                }


                if(size1%2==1)//searching for higher element
                {
                    if(v[i]>seq1[size1-1]){seq1[size1]=v[i];size1++;}
                    else seq1[size1-1]=v[i];
                }
                else if(size1%2==0)
                {
                    if(v[i]<seq1[size1-1]){seq1[size1]=v[i];size1++;}
                    else seq1[size1-1]=v[i];
                }
                //solving seq 2
                if(size2%2==1)//searching for higher element
                {
                    if(v[i]<seq2[size2-1]){seq2[size2]=v[i];size2++;}
                    else seq2[size2-1]=v[i];
                }
                else if(size2%2==0)
                {
                    if(v[i]>seq2[size2-1]){seq2[size2]=v[i];size2++;}
                    else seq2[size2-1]=v[i];
                }

         }
         printf("%d\n",max(size1,size2)+count);
     }

     return 0;
 }


