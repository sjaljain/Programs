#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#define pp pair<string,int>

template<template <typename> class P = std::greater >
struct compare_pair_second {
    template<class T1, class T2> bool operator()(const std::pair<T1, T2>& left, const std::pair<T1, T2>& right) {
        return P<T2>()(left.second, right.second);
    }
};

using namespace std;

int main()
{
	int T;
	cin>>T;
	int case_id=0;
	while(T--)
	{
			case_id++;		    
			vector< pp > v;
			string s;
			int rel;
			for(int i=1;i<=10;i++)
			{
			cin>>s>>rel;
			v.push_back(pp(s,rel));
			}

			std::sort(v.begin(), v.end(), compare_pair_second<>());
			
			int max=v[0].second;
			cout<<"Case #"<<case_id<<":"<<endl;
			cout<<v[0].first<<endl;

			int k=0;
			while(v[++k].second==max && k<10)
			cout<<v[k].first<<endl;

	} 	

    
    return 0;
}



