#include<iostream>
#include<vector>
#include<math.h>
#define size 5050000
#define mod 10007
using namespace std;
vector<bool> prime(size);
int arr[671000];
int ans[2*size];
int k=2;

int modulo(int a ,int b, int c)
{
    int x=1,y=a;
    while(b>0)
    {
        if(b%2==1)
        {
            x= (x*y)%c;
        }
        y=(y*y)%c;
        b=b/2;
    }
    return x%c;
}

void sieve(int n)
{
     int x=n/2, y=(int)sqrt(n);
     arr[1]=2;
     for(int i=1;i<=x;i++)
         prime[i]=false;
     for (int i=1; i<=y; i++)
     {
         if (!prime[i])
         {
             for (int j=3*i+1;j<=x;j+=(2*i+1))
                 prime[j] = true;
         }
     }
     for (int i=1; i<=x; i++)
         if(!prime[i])
          arr[k++]=2*i+1;
}

int binarysearch(int n)
{
    int start=1,end=671000;
    int mid=(start+end)/2;
    arr[0]=1;
    while(!(n<arr[mid] && n>arr[mid-1]) && !(n==arr[mid]))
    {
         mid=(start+end)/2;
         if(n<arr[mid])
              end=mid;
         else if(n>arr[mid])
              start=mid;
        // cout<<arr[mid]<<" ";
    }
    if(n==arr[mid])
    return mid;
    return mid-1;

}


int main()
{
    sieve(2*size);
    //for(int i=1;i<1000;i++)
      //cout<<arr[i]<<" ";
    //cout<<k<<" "<<arr[k-1]<<"\n";
            int n;
    while((scanf("%d",&n))!=EOF)
    {
//             scanf("%d",&n);
             //n=t;
             if(n==1)
             {
               printf("0\n");
               continue;
             }
             int temp=binarysearch(n);
             int ans=modulo(2,temp-1,mod);
              printf("%d\n",ans);
    }
    //system("pause");
}
