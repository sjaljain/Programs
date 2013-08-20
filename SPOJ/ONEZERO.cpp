#include<iostream>
#include<vector>
#include<queue>

#define N 100000

using namespace std;

int main()
{
			vector<long long int> v;
			v.push_back(1);
			for(int i=0;i<N;i++)
			{
				v.push_back(v[i]*10);
				v.push_back(v[i]*10+1);
			}
			//for(int i=0;i<N;i++)cout<<v[i]<<" ";
	int T;cin>>T;while(T--)
	{
			int num;
			cin>>num;
			for(int i=0;i<N;i++)
			{
				if(v[i]%num==0) {cout<<v[i]<<endl;break;}
			}
	}
	return 0;
}
