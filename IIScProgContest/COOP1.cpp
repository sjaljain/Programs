#include<iostream>
#include<vector>

using namespace std;

#define pp pair<float,float>

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
	vector< pp > v;
	//vector< pp > f;
	
	int N;cin>>N;int a;
	for(int i=0;i<N;i++){cin>>a;v.push_back(pp(a,0));}
	
	//for(int j=0;j<N;j++)cout<<v[j].first<<" " <<v[j].second<<endl;
	
	for(int i=0;i<N;i++){cin>>v[i].second;}
	
	//for(int j=0;j<N;j++)cout<<v[j].first<<" " <<v[j].second<<endl;

	//for(int j=0;j<N-1;j++)cout<<v[j].first<<" " <<v[j].second<<endl;



	f.push_back(v[0]);
	//cout<<f[0].first<<" "<<f[0].second;
	for(int i=1;i<N;i++)
	{
		float max_sum=v[i].first*v[i].second;float max_prob=v[i].second;
		cout<<max_sum<< " " <<max_prob;
		for(int j=i-1;j>=0;j++)
		{
			if(max_sum<v[j].first+v[j].second*v[i].second*v[i].first){max_sum=f[j].first+f[j].second*v[i].second*v[i].first;max_prob=f[j].second*v[i].second;}
		}
		f.push_back(pp(max_sum,max_prob));
	}
	cout<<f[N-1].first<<endl;

	
}
return 0;
	
}

