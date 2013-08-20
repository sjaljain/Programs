/*
 Codechef- CKISSHUG
 */

#include<iostream>
#include<cstdio>

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
    printf("%d\n",(mod_pow(2, N/2, 1000000007) * (3 + N % 2) - 2) % 1000000007);
    }
    return 0;
}
