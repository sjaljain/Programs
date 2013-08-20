//
//  main.cpp
//  Queries About Numbers
//
//  Created by Chandan Giri on 04/09/12.
//  Copyright (c) 2012 Chandan Giri. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

#define LL long long

using namespace std;

LL N,K,cnt;
int T,ct;
LL P[100][2];



void solve() {
    LL v,sol=1,c;
    if(T == 1 ) {
        for(int i=0; i<ct; i++) {
            if(K%P[i][0] == 0) {
                v = P[i][0];
                c = 1;
                K /= v;
                while(K%v == 0) {
                    K /= v;
                    c++;
                }
                LL m = (P[i][1]<c)? P[i][1]:c;
                sol = sol*(m+1);
            }
        }
    }
    else {
        if(N%K != 0 ) {
            sol = 0;
        }
        else {
            for(int i=0; i<ct; i++) {
                if(K%P[i][0] == 0) {
                    v = P[i][0];
                    c = 1;
                    K /= v;
                    while(K%v == 0) {
                        K /= v;
                        c++;
                    }
                    sol = sol*(P[i][1]-c+1);
                }
                else
                    sol = sol*(P[i][1]+1);
            }
        }
        if(T == 3)
            sol = cnt-sol;
    }
    if(sol<0)
        sol = 1/0;
    printf("%lld\n",sol);
}

void precompute() {
    LL i,v,N1;
    N1 = N;
    v = sqrt(N1);
    ct=0;
    cnt  = 1;
    for(i=2; i<=v; i++) {
        if(N1 == 1)
            break;
        if(N1%i == 0) {
            P[ct][0] = i;
            P[ct][1] = 1;
            N1 /= i;
            while(N1%i == 0) {
                P[ct][1] ++;
                N1 /= i;
            }
            cnt = cnt*(1+P[ct][1]);
            ct++;
        }
    }
    if(N1>1) {
        P[ct][0] = N1;
        P[ct][1] = 1;
        cnt = cnt*2;
        ct++;
    }
}


int main()
{
    int Q;
    scanf("%lld%d",&N,&Q);
    precompute();
    for(int i=0; i<Q; i++) {
        scanf("%d%lld",&T,&K);
        solve();
    }
    return 0;
}

