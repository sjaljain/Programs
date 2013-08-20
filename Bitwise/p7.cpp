#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdio>

#define inf 1000000000

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int K,M;
        scanf("%d%d",&K,&M);
        vector<int> G[K+1];
        while(M--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
        }
        for(int i=0;i<K+1;i++)
            sort(G[i].begin(),G[i].end());

        int ans=inf;
        queue<int> Q;
        vector<int> num(K+1,inf);

        num[1]=0;
        Q.push(1);
        while(!Q.empty())
        {
            int x=Q.front();
            Q.pop();
            for(int r=0;r<G[x].size();r++)
            {
                int cur_num=num[G[x][r]];
                int after_num=num[x]+r;
                if(after_num<cur_num)
                {
                    Q.push(G[x][r]);
                    //cout<<G[x][r]<<" ";
                    num[G[x][r]]=after_num;
                }
            }
            ans=min(ans,num[K]);
        }
        if(ans==inf)cout<<-1<<endl;
        else cout<<ans<<endl;


    }
    return 0;
}
