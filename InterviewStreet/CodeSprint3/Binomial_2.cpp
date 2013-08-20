#include <stdio.h>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <time.h>
#include <fstream>
#include <sstream>
using namespace std;

#define MOD 142857 = 27*11*13*37

long long FacMod1[28];
long long FacModInv1[28];

long long FacMod2[12];
long long FacModInv2[12];

long long FacMod3[14];
long long FacModInv3[14];

long long FacMod4[38];
long long FacModInv4[38];


const long long m1=27;
const long long m2=11;
const long long m3=13;
const long long m4=37;


long long modPow(long long a, long long x,long long m) {
    long long res = 1;
    while(x > 0) {
        if(x & 1)res = (res * a) % m;
        a = (a * a) % m;
        x >>= 1;
    }
    return res;
}
long long modInverse(long long a,long long m) {
    return modPow(a, m-2,m);
}

int main(void){
    int i,j,T;

    long long ans1,ans2,ans3,ans4, n, k , N, K, num=1, den=1;
    FacMod1[0]=FacModInv1[0]=1;
    FacMod1[m1]=FacModInv1[m1]=1;
    for(i=1;i<m1;i++){
        num*=i; num%=m1;
        FacMod1[i]=num;
        den*=modInverse(i,m1); den%=m1;
        FacModInv1[i]=den;
    }
    num=1;den=1;
    FacMod2[0]=FacModInv2[0]=1;
    FacMod2[m2]=FacModInv2[m2]=1;
    for(i=1;i<m2;i++){
        num*=i; num%=m2;
        FacMod2[i]=num;
        den*=modInverse(i,m2); den%=m2;
        FacModInv2[i]=den;
    }
    num=1;den=1;
    FacMod3[0]=FacModInv3[0]=1;
    FacMod3[m3]=FacModInv3[m3]=1;
    for(i=1;i<m3;i++){
        num*=i; num%=m3;
        FacMod3[i]=num;
        den*=modInverse(i,m3); den%=m3;
        FacModInv3[i]=den;
    }
    num=1;den=1;
    FacMod4[0]=FacModInv4[0]=1;
    FacMod4[m4]=FacModInv4[m4]=1;
    for(i=1;i<m4;i++){
        num*=i; num%=m4;
        FacMod4[i]=num;
        den*=modInverse(i,m4); den%=m4;
        FacModInv4[i]=den;
    }

    cin>>T;
    while(T--){
        scanf("%lld %lld",&N,&K);
        long long Ncpy=N;
        ans1=1;
        while(N){
            n=N%m1;  k=K%m1;
            if(n<k){ ans1=0; break; }
            ans1*=FacMod1[n];
            ans1*=FacModInv1[k];
            ans1*=FacModInv1[n-k];
            ans1%=m1;
            N/=m1;   K/=m1;
        }
        ans2=1;
        N=Ncpy;
        while(N){
            n=N%m2;  k=K%m2;
            if(n<k){ ans2=0; break; }
            ans2*=FacMod2[n];
            ans2*=FacModInv2[k];
            ans2*=FacModInv2[n-k];
            ans2%=m2;
            N/=m2;   K/=m2;
        }
        ans3=1;
        N=Ncpy;
        while(N){
            n=N%m3;  k=K%m3;
            if(n<k){ ans3=0; break; }
            ans3*=FacMod3[n];
            ans3*=FacModInv3[k];
            ans3*=FacModInv3[n-k];
            ans3%=m3;
            N/=m3;   K/=m3;
        }
        ans4=1;
        N=Ncpy;
        while(N){
            n=N%m4;  k=K%m4;
            if(n<k){ ans4=0; break; }
            ans4*=FacMod4[n];
            ans4*=FacModInv4[k];
            ans4*=FacModInv4[n-k];
            ans4%=m1;
            N/=m4;   K/=m4;
        }

        printf("%lld %lld %lld %lld\n",ans1,ans2,ans3,ans4);
    }
    return 0;
}
