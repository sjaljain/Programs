#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

int main()
{
  int T;cin>>T;while(T--){
    int n;cin>>n;
    vector <int> v(n,0);
   
    int max=0;
    for(int i=0;i<n;i++) scanf("%d",&v[i]);
    
     vector <long long int> sum(n,v[0]);
     max=v[0];
     
     for(int i=1;i<n;i++)
       {
	 if(sum[i-1]>0)sum[i]=sum[i-1]+v[i];
	 else sum[i]=v[i];
	 if(sum[i]>max)max=sum[i];
       }

     long long int count=0,filter=0;
     for(int i=0;i<n;i++)
       {
       if(sum[i]==max)
	 {
	 count++;
	 count+=filter;
	 }
       if(sum[i]==0)filter++;
       if(sum[i]<0)filter=0;
       }

     cout<<max<<" "<<count<<endl;
    
  }
  return 0;
}
