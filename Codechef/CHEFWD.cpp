/*
 Codechef- CHEFWD
 */

#include<iostream>
#include<cstdio>

#define mod 1000000007

using namespace std;

void fib_multiply(long long A[2][2],long long B[2][2])
{
    long long mult[2][2];
    int N=2;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            {
                mult[i][j]=0;
                for(int k=0;k<N;k++)
                {
                    mult[i][j]+=A[i][k]*B[k][j];
                    mult[i][j]=mult[i][j]%mod;

                }
            }
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            A[i][j]=mult[i][j];
    return ;

}
//
//void fib_mod_pow_matrix(long long num[2][2], long long pow)
//{
//    long long test[2][2]={{1,0},{0,1}};
//    for(; pow; pow >>= 1)
//    {
//        if (pow & 1)
//            fib_multiply(test,num);
//        fib_multiply(num,num);
//    }
//    for(int i=0;i<2;i++)
//        for(int j=0;j<2;j++)
//            num[i][j]=test[i][j]; //to pass value back to the main()
//
//    return;
//}


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
                    mult[i][j]+=A[i][k]*B[k][j];
                    mult[i][j]=mult[i][j]%mod;

                }
            }
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            A[i][j]=mult[i][j];
    return ;

}

//void lucas_mod_pow_matrix(long long  num[4][4], long long pow)
//{
//    long long test[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
//    for(; pow; pow >>= 1)
//    {
//        if (pow & 1)
//            lucas_multiply(test,num);
//        lucas_multiply(num,num);
//    }
//    for(int i=0;i<4;i++)
//        for(int j=0;j<4;j++)
//            num[i][j]=test[i][j]; //to pass value back to the main()
//
//    return;
//}
//
//long long L(long long N)
//{
//    long long A[4][4]={{2,1,-2,-1},{1,0,0,0},{0,1,0,0},{0,0,1,0}};
//    lucas_mod_pow_matrix(A,N-1);
//    return A[1][0];
//}


long long F(long long N, long long &x)
{
    long long A[2][2]={{1,1},{1,0}};
    fib_mod_pow_matrix(A,N);
    x=(A[1][0]+A[1][1])%mod;
    return A[1][0];
}



int main()
{
    int T;
    scanf("%d",&T);
    long long F[32][2][2];
    F[0][0][0]=1;F[0][1][1]=1;F[0][1][0]=1;F[0][1][1]=0;
    for(int i=1;i<=32;i++)
    {
        F[i][0][0]=F[i-1][0][0];F[i][0][1]=F[i-1][0][1];F[i][1][0]=F[i-1][1][0];F[i][1][1]=F[i-1][1][1];
        fib_multiply(F[i],F[i]);
    }



    while(T--)
    {
        long long N;
        scanf("%llu",&N);
        long long ans=0;
        long long fn2=0;
        long long fn1=F(N+1,fn2);
        long long fn3=(fn1+fn2)%mod;
        long long fn4=(fn2+fn3)%mod;
        ans+=(L(N+5)-fn4-fn4-fn2-fn2-fn1-fn1-fn1-fn3+mod+mod+mod+mod+mod+mod+mod+mod)%mod;
        printf("%llu\n",ans);
    }
    return 0;
}
