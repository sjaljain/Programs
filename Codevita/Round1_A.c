#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
 int s,t,k;
 if(scanf("%d%d%d",&s,&t,&k)!=3){printf("Invalid Input\n");return 0;}
 if(s<0 || t<s || k<=0){printf("Invalid Input\n");return 0;}
 int *v,*p;
 v=(int *)malloc((t+1)*sizeof(int));
 p=(int *)malloc((t+1)*sizeof(int));
 v[0]=0;v[1]=0;
 int i,j;
 for(i=2;i<=t;i++)v[i]=1;
 for(i=2;i<=sqrt(t);i++)
      for(j=2*i;j<=t;j+=i)
                 v[j]=0;
 
 //int l;        
 //for(l=0;l<=t;l++)
 //printf("%d ",v[l]);
 int x=0;
 for( i=s;i<=t;i++)
 {
         if(v[i]==1)p[x++]=i;
         } 
         if(k>x)printf("No prime number is present at this index\n");
         else printf("%d\n",p[k-1]);
          
         //getchar();
         //getchar();
         return 0;   
}
