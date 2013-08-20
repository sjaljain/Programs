#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	int T;cin>>T;while(T--)
	{
			int num1,num2;
			cin>>num1>>num2;
			int visited[10000]={0};
			queue<int> q;
			q.push(num1);
			while(!q.empty())
			{
					int p=q.front();
					visited[p]=1;
					q.pop();
					
					
			}	
	}
	return 0;
}
