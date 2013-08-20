#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
    int T;
    cin>>T;
    char ch;cin>>ch;
    for(int t=1;t<=T;t++)
    {
        string str;
        getline(cin,str);
        int open=0,close=0,opens=0,closes=0;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]!=':' && str[i]!='(' && str[i]!=')')
                continue;
            if(str[i]=='(')
               open++;
            if(str[i]==')')
                close++;
            if(str[i]==':')
            {
                if(i+1<str.length() && str[i+1]==')')
                {
                    closes++;
                    i++;
                }
            }
            if(str[i]==':')
            {
                if(i+1<str.length() && str[i+1]=='(')
                {
                    opens++;
                    i++;
                }
            }

        }
        int done=0;
        int x=open-close;
        if(x==0)done=1;
        else if(x<0){if(x+opens>=0)done=1;}
        else if(x>0){if(x-closes<=0)done=1;}

        if(done==0)
            cout<<"Case #"<<t<<": NO"<<endl;
        else
            cout<<"Case #"<<t<<": YES"<<endl;
    }
    cin>>T;

    return 0;
}
