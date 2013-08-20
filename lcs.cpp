#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 100;
void backtrack(char* X,int path[MAX][MAX],int x,int y)
{
    if(path[x][y]==0)
    {
        return;
    }
    else if(path[x][y]==1)
    {
        backtrack(X,path,x-1,y-1);
        cout<<X[x-1];
    }
    else if(path[x][y]==2)
    {
        backtrack(X,path,x-1,y);
    }
    else if(path[x][y]==3)
    {
        backtrack(X,path,x,y-1);
    }
}
void lcs(char* X, char* Y,int m,int n)
{
    int L[MAX][MAX],path[MAX][MAX];
    memset(L,0,sizeof L);
    memset(path,0,sizeof path);
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0||j==0)
            {
                L[i][j] = 0;
                path[i][j] = 0;
            }
            else if(X[i-1]==Y[j-1])
            {
                L[i][j] = 1 + L[i-1][j-1];
                path[i][j] = 1;
            }
            else
            {
                if(L[i-1][j]>L[i][j-1])
                {
                    L[i][j] = L[i-1][j];
                    path[i][j] = 2;
                }
                else
                {
                    L[i][j] = L[i][j-1];
                    path[i][j] = 3;
                }
            }
        }
    }
    cout<<L[m][n]<<endl;
    backtrack(X,path,m,n);
}
int main()
{
    char X[] = "XMJYAUZ";
    char Y[] = "MZJAWXU";
    int m = strlen(X);
    int n = strlen(Y);
    lcs(X,Y,m,n);
    return 0;
}
