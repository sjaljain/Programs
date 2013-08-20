#include<iostream>
#include<vector>
#include<algorithm>

template<template <typename> class P = std::less >
struct compare_pair_second {
    template<class T1, class T2> bool operator()(const std::pair<T1, T2>& left, const std::pair<T1, T2>& right) {
        return P<T2>()(left.second, right.second);
    }
};

#define pp pair<int,int>

using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
	vector< pp > v;
	int n;int temp;
	cin>>n;temp=n;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		v.push_back(pp(a,b));
	}
	
		//cout<<v[0].first;
		std::sort(v.begin(), v.end(), compare_pair_second<>());
		//cout<<v[0].first;

		//for(int i=0;i<temp;i++){cout<<v[i].first<<" " <<v[i].second<<endl;}
	
		//std::sort(v.begin(), v.end(),  boost::bind(&std::pair<int, int>::second, _1) < boost::bind(&std::pair<int, int>::second, _2));
		int count=1;
		int end_time=v[0].second;
		for(int i=1;i<temp;i++)
		{
			if(v[i].first>=end_time) {count++;end_time=v[i].second;}
		}
	cout<<count<<endl;
		
	}	
	return 0;
}
