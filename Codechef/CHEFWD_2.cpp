/*
 Codechef- CHEFWD
 Sajal Jain
 Fibonacci Recursion + Matrix Exponentiation

 */

#include<iostream>
#include<cstdio>

#define mod 1000000007

using namespace std;

long long P[65][4][4];//stores precomputed valyes till A^(2^64)
long long test[4][4]={{2,1,-2,-1},{1,0,0,0},{0,1,0,0},{0,0,1,0}};//matrix A

//To calculate mod
long long md(long long n)
{
    return (n+mod)%mod;
}

//To copy matrix B into matrix A
void copy_matrix(long long A[4][4],long long B[4][4])
{
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
        A[i][j]=B[i][j];
}

//To multiply 4*4 matrix and store the result back into A
void lucas_multiply( long long A[4][4], long long B[4][4])
{
    long long mult[4][4];

    int N=4;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            {
                mult[i][j]=0;
                for(int k=0;k<N;k++)
                {
                    mult[i][j]+=(md(A[i][k])*md(B[k][j]));
                    mult[i][j]=md(mult[i][j])%mod;

                }
            }
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            A[i][j]=mult[i][j];
    return ;

}

//To precompute A^1, A^2,A^4,A^8,A^16 and store in P
void precompute()
{
    copy_matrix(P[0],test);
    for(int i=1;i<=64;i++)
    {
        copy_matrix(P[i],P[i-1]);
        lucas_multiply(P[i],P[i-1]);
    }
}


//To compute A^pow using pow's binary value
long long pow_matrix(long long pow)
{
    long long num[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
    int i=0;
    while(pow!=0)
    {
        if(pow&1)
            lucas_multiply(num,P[i]);

        i++;
        pow/=2;
    }
    //cout<<num[0][0]<<" "<<num[0][1]<<" "<<num[0][2]<<endl;
    return (num[0][0]*44+num[0][1]*18+num[0][2]*5)%mod;
}

int main()
{
    int T;
    scanf("%d",&T);
    precompute();
    while(T--)
    {
        long long N;
        scanf("%llu",&N);
        if(N==0 || N==1){printf("0\n");continue;}
        if(N==2){printf("5\n");continue;}
        if(N==3){printf("18\n");continue;}
        else printf("%llu\n",pow_matrix(N-4));
    }
}
