#include<stdio.h>
#include<stdlib.h>
void sort(int *a,int p,int q);
int partition(int *a,int p,int q);

int main()
{
    int i,j,k,n;
    scanf("%d%d",&n,&k);
    int *a=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    sort(a,0,n-1);
    int count=0,start=0,end=0,max=0,candi=a[0],diff=0,p;
    for(i=0;i<n;i++)
    {
        if(k>=a[0]-a[i])
        {
            end=i;
            k-=(a[0]-a[i]);
        }
        else break;
    }
    max=end-start+1;
    //printf("%d\n",end-start+1);
    while(j<n)
    {
        if(a[j]==candi)
         {start++;
          j++;
          continue;
         }
        diff=(end-start+1)*(candi-a[j]);
        candi=a[j];
        k+=diff;
        for(p=i;p<n;p++)
        {
            if(k>=candi-a[p])
             {
              end++;
              k-=candi-a[p];
             }
             else
             break;
        }
        i=p;
            //printf("%d\n",end-start+1);
        if(max<end-start+1)
         max=end-start+1;
        if(i==n)break;

    }
    printf("%d\n",max);



    return(0);
}
void sort(int *a,int p,int q)
{
    int x;
    if(p<q)
    {
        x=partition(a,p,q);
        sort(a,p,x-1);
        sort(a,x+1,q);
    }
}
int partition(int *a,int p,int q)
{
    int i,j,temp;
    i=p-1;
    for(j=p;j<=q;j++)
    {
        if(a[j]>=a[q])
        {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    return(i);
}
