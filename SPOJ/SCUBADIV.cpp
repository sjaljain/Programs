#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>


using namespace std;

#define inf 99999


struct cyl
{
       int nit;
       int oxy;
       int wt;
       cyl(int _nit,int _oxy,int _wt){nit=_nit;oxy=_oxy;wt=_wt;}
       };
       
bool cmp(const cyl& a, const cyl& b) { return a.wt < b.wt; }

int main()
{
    int T;cin>>T;   
    while(T--)
    {
              vector<cyl> v;
              int N,O;
              cin>>N>>O;
              int a,b,c;
              int n;cin>>n;
              while(n--)
              {
                                 scanf("%d%d%d",&a,&b,&c);
                                 v.push_back(cyl(a,b,c));
                                 }
             sort(v.begin(),v.end(),cmp);
              
             //for(int i=0;i<v.size();i++)
//             {
//                     cout<<v[i].nit<<" "<<v[i].oxy<<" "<<v[i].wt<<endl;        
//                     }                         
              
              int A[80][80];
              for(int i=0;i<=N;i++)
                      for(int j=0;j<=O;j++){
                                            A[i][j]=inf;}
               A[0][0]=0;
               for(int k=0;k<v.size();k++)
               {                             
               for(int i=N;i>=0;i--)                                                 
               {
                       for(int j=O;j>=0;j--)
                       {
                               int p=i-v[k].nit;
                               int q=j-v[k].oxy;
                               if(p<=0){p=0;}
                               if(q<=0){q=0;}
                               A[i][j]=min(A[i][j],A[p][q]+v[k].wt);
                               
                               
                               }
                       }
                       }
                       //for(int i=0;i<=N;i++)
//                       {
//                               for(int j=0;j<=O;j++)
//                               cout<<A[i][j]<<" ";
//                               
//                               cout<<endl;
//                               }

                                 cout<<A[N][O]<<endl;
                               
            
            }   
              //getchar();
//              getchar();
//              getchar();
    return 0;
}
