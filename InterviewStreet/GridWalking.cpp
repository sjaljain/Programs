#include<iostream>
#include<vector>

using namespace std;

#define MOD 1000000007

int count(int *init,int *dim,int M);
int N;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
              int M;
              cin>>N>>M;
              int *init;
              init=new int[N];
              int *dim;
              dim=new int[N];
              for(int i=0;i<N;i++)
                      cin>>init[i];
              for(int i=0;i<N;i++)
                      cin>>dim[i];
              
              cout<<count(init,dim,M)<<endl;
              }
 return 0;   
}

int count(int *init,int *dim,int M)
{
    int total=0;
    if(M==0)return 1;
    int *cpy;
    cpy = new int[N];
    for(int i=0;i<N;i++)cpy[i]=init[i];
    for(int i=0;i<N;i++)
    {
            if(init[i]<dim[i])
                         {
                         cpy[i]=init[i]+1;
                         total+=count(cpy,dim,M-1)%MOD;
                         }
            if(init[i]>1)
                         {
                         cpy[i]=init[i]-1;
                         total+=count(cpy,dim,M-1)%MOD;
                         }
            }
    return total;
    
}
    
    
    
