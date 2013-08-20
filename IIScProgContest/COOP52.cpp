#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int T;cin>>T;
	while(T--)
	{
	vector< int> v;
	int N,K;
	cin>>N>>K;
	for(int i=0;i<N;i++)
	{
		int a;cin>>a;
		v.push_back(a);	
	}		
	
	sort(v.begin(),v.end());
	int sum=0;
	for(int i=N-K;i<N;i++)
	sum+=v[i];
	
	for(int i=N-K-1;i>=0;i--)
		if(v[N-K]==v[i])sum+=v[i];
	
	cout<<sum<<endl;
	}	
	return 0;
}
