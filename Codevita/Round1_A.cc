#include<stdio.h>
#include<math.h>

int main()
{
 int s,t,k;
 scanf("%d%d%d",&s,&t,&k);
 if(s<0 || t<0 ||k<=0){printf("Invalid Input\n";return 0;}
 int v[150001]={1};
 int p[150001];
 v[0]=0;v[1]=0;
 for(int i=2;i<=sqrt(t);i++)
 {
         int j=2*i;
 
         for(;j<=t;j+=i)
         {
                       v[j]=0;
                 }
                 
         }
         
// for(int l=0;l<=t;l++)
// cout<<v[l]<<" ";
 int x=0;
 for(int i=s;i<=t;i++)
 {
         if(v[i]==1);p[x++]=i;
         } 
         if(k>x)cout<<"No prime number is present at this index"<<endl;
         else cout<<p[k-1]<<endl;
         
         getchar();
         //getchar();
         return 0;   
}
