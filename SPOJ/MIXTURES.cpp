#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n,c;
    while(cin>>n)
    {
    vector<long long int> cement(n,0),color(n,0),cost(n,0);
    for(int i=0;i<n;i++)
    {
            cin>>c;
            cement[i]=c;
            }
    color[0]=cement[0];
    color[1]=(cement[0]+cement[1])%100;
    cost[1]=cement[0]*cement[1];
    
    for(int i=2;i<n;i++)
    {
            int x,y;
            x=cost[i-1]+color[i-1]*cement[i];
            y=cost[i-2]+cement[i-1]*cement[i]+color[i-2]*((cement[i]+cement[i-1])%100);
            
            
            if(x<y){cost[i]=x;color[i]=(color[i-1]+cement[i])%100;}
            else {cost[i]=y;color[i]=(cement[i-1]+cement[i])%100;}
            }
            
    //for(int i=0;i<n;i++)cout<<cement[i]<<" ";cout<<endl;
    //for(int i=0;i<n;i++)cout<<color[i]<<" ";cout<<endl;
    //for(int i=0;i<n;i++)cout<<cost[i]<<" ";cout<<endl;   
    
    cout<<cost[n-1]<<endl;
    }
    //getchar();
    //getchar();
    
    
    return 0;
}
