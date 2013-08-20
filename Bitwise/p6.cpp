#include<iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        vector<int> > A(N+1,vector<int> (N+1,0));
        int M;
        scanf("%d",&M);
        while(M--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            A[a][b]=1;
            A[b][a]=1;
        }
    }

return 0;
}
