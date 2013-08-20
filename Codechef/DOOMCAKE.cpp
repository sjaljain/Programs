#include<iostream>
#include<string>

using namespace std;

int main()
{
	int T;cin>>T;
	while(T--)
	{
			int A[11]={0};
			int K;
			int ans=1;
			string s;
			cin>>K>>s;
			for(int i=0;i<s.length();i++)
			{
				if(s[i]=='?')A[10]++;
				else A[s[i]-48]++;
			}
			if(s.length()>K) ans=0;
			for(int j=0;j<K;j++)
					if(A[j]>=2) {ans=0;cout<<"NO"<<endl;break;}
					
			if(ans)
			{
				for(int i=0;i<s.length();i++)
				{
					if(s[i]=='?')
					{
						for(int j=0;j<K;j++)
						{
							if(A[j]==0) {A[j]--;s[i]=j+48;break;}
						}
					}
				}
				cout<<s<<endl;
			}
			
			
	}
	return 0;
}
