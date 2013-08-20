#include <iostream>
#include <cstdio>
#include <cstring>
#define N 8
using namespace std;
void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", sol[i][j]);
        printf("\n");
    }
}
int isSafe(int sol[N][N],int x,int y)
{
    if(x>=0 && x<N && y>=0 && y<N && sol[x][y]==0)
    {
        return 1;
    }
    return 0;
}
int solveProblem(int move,int x, int y,int sol[N][N],int a[N], int b[N])
{
    if(move==N*N)
    {
        printSolution(sol);
        return 1;
    }
    else
    {
        for(int k=0; k<N; k++)
        {
            int i = x + a[k];
            int j = y + b[k];
            if(isSafe(sol,i,j))
            {
                sol[i][j] = move;
                if(solveProblem(move+1,i,j,sol,a,b)==1)
                {
                    return 1;
                }
                else
                {
                    sol[i][j] = 0;
                }
            }
        }
    }
    return 0;
}
void solve()
{
    int sol[N][N];
    int a[] = {  2, 1, -1, -2, -2, -1,   1,  2};
    int b[] = {  1, 2,  2,  1,  -1, -2,  -2, -1 };
    memset(sol,0,sizeof sol);
    solveProblem(1,0,0,sol,a,b);
}
int main()
{
    solve();
    return 0;
}
