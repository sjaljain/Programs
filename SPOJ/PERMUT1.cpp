#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

int main()
{
 int a[99][13];
 int t,n,k;
 scanf("%d",&t);
 while(t>0){
        scanf("%d%d",&n,&k);
        int i,j,m,l;
        for(i=0;i<=k;i++)
            a[i][0]=0;
        for(i=0;i<=n;i++)
            a[0][i]=1;
        for(i=1;i<=k;i++){
            for(j=1;j<=n;j++){
                m = i;
                a[i][j]=0;
                l=0;
                while(m>=0&&l<j){
                    a[i][j]+=a[m][j-1];
                    l++;
                    m--;
                }
            }
        }
        cout<<a[k][n]<<endl;
        t--;
    }
 return 0;
}
