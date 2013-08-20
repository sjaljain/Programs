#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    string s;
    cin>>s;
    if(s.size()!=10){cout<<"INVALID INPUT"<<endl;return 0;}
    int sum=0;
    int count_q=0,multi;
    for(int i=0,k=10;i<10;i++)
    {
            if(!((s[i]>47 && s[i]<58)||s[i]=='X'||s[i]=='?')){cout<<"INVALID INPUT"<<endl;return 0;}
            if(s[i]=='X' && i!=9){cout<<"INVALID INPUT"<<endl;return 0;}
            else if(s[i]=='X')sum+=1*10;
            else if(s[i]>=48 && s[i]<=57)sum+=k*(s[i]-48);
            else if(s[i]=='?'){count_q++;multi=k;}
            k--;
            //cout<<sum<<" ";
            }
    if(count_q!=1){cout<<"INVALID INPUT"<<endl;return 0;}
    int ans=-1;
    //cout<<sum<<endl;
    for(int i=0;i<=9;i++)
    {
            if((sum+multi*i)%11==0){ans=i;break;}
            }
            if(ans!=-1)cout<<ans<<endl;
            //else if(ans==10)cout<<"X"<<endl;
            else if(multi==1 && (sum+10)%11==0)cout<<"X"<<endl;            
            else cout<<"NO SOLUTION POSSIBLE"<<endl;
            
            
       //getchar();
       //getchar();     
    return 0;   
}
