/*
 Codechef- CROWD
 */

#include<iostream>
#include<cstdio>

using namespace std;

void multiply(unsigned long long int A[3][3],unsigned long long int B[3][3])
{
    unsigned long long int mult[3][3];
    int mod=1000000007;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            {
                mult[i][j]=0;
                for(int k=0;k<3;k++)
                {
                    mult[i][j]+=A[i][k]*B[k][j];
                    mult[i][j]=mult[i][j]%mod;

                }
            }
    }
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            A[i][j]=mult[i][j];
    return ;

}

void mod_pow_matrix(unsigned long long int num[3][3], unsigned long long int pow)
{
    unsigned long long int test[3][3]={{1,0,0},{0,1,0},{0,0,1}};
    for(; pow; pow >>= 1)
    {
        if (pow & 1)
            multiply(test,num);
        multiply(num,num);
    }
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            num[i][j]=test[i][j]; //to pass value back to the main()

    return;
}

unsigned long long int mod_pow(unsigned long long int num, unsigned long long int pow, int mod)
{
    unsigned long long int test;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            test = (test * num) % mod;
        num = (num * num) % mod;
    }

    return test;

}


int main()
{
    int T;
    unsigned long long int N;
    scanf("%d",&T);
    while(T--)
    {
    scanf("%llu",&N);
    if(N==1){printf("%d\n",0);continue;}
    if(N==2){printf("%d\n",0);continue;}
    if(N==3){printf("%d\n",1);continue;}
    unsigned long long int A[3][3]={{1,1,1},{1,0,0},{0,1,0}};
    mod_pow_matrix(A,N-3);
    int mod=1000000007;
    unsigned long long int two = mod_pow(2,N, mod);
    unsigned long long int sub=A[0][0]*7+A[0][1]*4+A[0][2]*2;
    //cout<<two<< " "<<sub;
    int ans=(((two+mod)%mod)-((sub+mod)%mod)+mod)%mod;
    printf("%d\n",ans);

    }
    return 0;
}
