#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    int sum=0;
    for(int i=0;i<n;i++)
            sum+=v[i];
            
    int out1=1;        
    if(v[0]!=0)
    out1=-1;
    
    int out2=-1;
    
    int m=sum%3;
    //cout<<m;
    
    if(m==0)out2=1;
    if(m==1 || m==2)
    {
        for(int i=0;i<n;i++)
        if((v[i]-m)%3==0){v[i]=-1;out2=1;break;}
        }
       
    if(out2!=1) 
         {
          
                    int i;
                    for( i=0;i<n;i++)
                            if(v[i]%3==1){v[i]=-1;break;}
                            
                    for(int k=i+1;k<n;k++)
                            if(v[k]%3==1){v[k]=-1;out2=1;break;}
                            
                                      }   
           
           
    if(out1!=-1 && out2==1)
    {
               for(int l=n-1;l>=0;l--)
                       if(v[l]!=-1)
                              cout<<v[l];
               }
    else cout<<-1;
    
    //getchar();
    //getchar();
    
    return 0;
}
