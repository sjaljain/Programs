#include<iostream>

using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
			int N,S;
			int sum=0;
			cin>>N>>S;
			for(int i=1;i<=N;i++)
			{
				int a;
				cin>>a;
				sum+=a;
			}	
			if(sum<=S) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
	}	
	return 0;
}

