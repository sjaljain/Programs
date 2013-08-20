#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
int T;
cin>>T;
while(T--)
{
    int v[100000];
    string str;
    cin>>str;
    int s=str.length();
    for(int i=0;i<str.length();i++)
        v[i]=str[i]-'0';

    if(!next_permutation(v,v+s))
    {
        cout<<-1<<endl;
    }
    else
    {
        for(int i=0;i<s;i++)
        {
            cout<<v[i];
        }
        cout<<endl;
    }
}
return 0;
}

