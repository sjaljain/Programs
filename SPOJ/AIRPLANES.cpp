// napisane Monikou 
// namakana dynamika 2^M* M * N *K
#include<iostream> 
#include<cstdlib> 
#include<cstring> 
#include<vector>
#define SIZE(s) ((int)((s).size())) 
#define FOREACH(it,vec) for(typeof((vec).begin())it=(vec).begin();it!=(vec).end();++it) 
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define MAXN 100 
#define MAXM 8 
#define MOD 420047
using namespace std;
int N,M,K; 
long long P[2][MAXN*MAXM][(1<<MAXM)];
bool is_ok(long long x, int t) { // kontrolujem popis xa som v kroku t (rozsah 0 az M-1) 
long long lo,hi; 
lo = x & ((1LL<<(t+1))-1); 
hi = x ^ lo; 
if (lo & (lo<<1)) return false; 
if (hi & (hi<<1)) return false; 
return true; 
}
long long add(long long w, bool x) { // pridam kw hodnotu x (0/1) aw urezem na poslednych M bitov 
w = w&((1LL<<(M-1))-1); 
w = w<<1; 
if (x) w|=1; 
return w; 
}
void print() { 
REP(i,2) 
REP(j,3) 
REP(k,3) 
cout << "P[" << i << "][" << j << "][" << k << "] = " << P[i][j][k] << endl; 
}
int main(void) { 
memset(P,0,sizeof(P)); 
scanf("%d",&N); scanf("%d",&M); scanf("%d",&K);
if (N==0) { printf("0\n"); return 0; }
for(long long i=0;i<(1LL<<M);++i) { 
if (i & (i<<1)) continue; 
int b=0; 
REP(j,M) if (i&(1LL<<j)) ++b; 
P[M%2][b][i] = 1; 
}
for(int n=M;n<N*M;++n) { 
memset(P[(n+1)%2],0,sizeof(P[(n+1)%2])); 
for(long long i=0;i<(1LL<<M);++i) { 
REP(k,K+1) { 
REP(d,2) { 
if (P[n%2][k][i] == 0) continue; // nic nove nepridam 
if (k+d > K) continue; // prilis vela ciernych 
if (d==1 && (i&(1LL<<(M-1)))) continue; // ak pridavam ciernu a vedla nej je tiez cierna 
long long nove = add(i,(bool)d); 
if (!is_ok(nove,n%M)) continue; 
P[(n+1)%2][k+d][nove]+=P[n%2][k][i]; 
P[(n+1)%2][k+d][nove]%=MOD; 
} 
} 
} 
}
long long sum = 0; 
for(long long i=0;i<(1LL<<M);++i) { 
sum+= P[(N*M)%2][K][i]; 
sum%= MOD; 
} 
printf("%lld\n",sum); 
return 0; 
}
