//@BEGIN_OF_SOURCE_CODE
/*
 it is giving wrong ans -- look for multiple connections between same nodes (make a matrix)
*/
#include<iostream>
#include<list>
#include<queue>
#include<vector>

#define maxn 102
#define MIN(a, b) (a > b ? b:a)
using namespace std;

int N, S, T, C, Res;
int P[maxn];
int B[maxn][maxn];
int Cap[maxn];

struct ss {
        int x;
        int cost;
};

class comp {
public :
        bool operator() (const ss &a, const ss &b) {
                return a.cost < b.cost;
        }
};

list<int>L[maxn];
priority_queue<ss, vector<ss>, comp> Q;

void Recur(int n, int c) {
        int p;
        if(n == S) return;
        p = P[n];
        B[p][n] -= c;
        B[n][p] += c;
        Recur(P[n],c);
}

int Dij() {
        ss temp, dump;
        int u, v, c;
        list<int>::iterator p;
        temp.cost = 1000000;
        temp.x = S;
        Q.push(temp);
        P[S] = -1;
        Cap[S] = 1000000;
        while(!Q.empty()) {
                temp = Q.top();
                Q.pop();
                u = temp.x;
                for(p = L[u].begin(); p != L[u].end(); p++) {
                        v = *p;
                        if(B[u][v] == 0) continue;
                        c = MIN(temp.cost,B[u][v]);
                        if(v == T) {
                                P[v] = u;
                                Recur(v, c);
                                Res += c;
                                return 1;
                        }
                        else if( Cap[v] < c) {
                                dump.cost = c;
                                dump.x = v;
                                P[v] = u;
                                Cap[v] = c;
                                Q.push(dump);
                        }
                }
        }
        return 0;
}

void Set() {
        int i;
        for(i = 1; i<= N; i++){
                Cap[i] = 0;
                P[i] = 0;
        }
        while(!Q.empty()) Q.pop();
}

void Cal() {
        Res = 0;
        Set();
        while(Dij()) {
                Set();
        }
        //cout<<"The bandwidth is "<<Res<<".\n";
		cout<<Res;
}

int main() {
        int u, v, c, nt = 1, i;
        //freopen("h.txt","r",stdin);
                S=1;T=26;//source destination total_number_of_connections
                int C;cin>>C;
                while(C--) {
                        char ch1,ch2;
                        cin>>ch1>>ch2>>c;
                        u=ch1-64;v=ch2-64;
                        L[u].push_back(v);//undirected graph example, change for directed
                        L[v].push_back(u);
                        B[u][v] += c;
                        B[v][u] += c;
                }
                //cout<<"Network "<<nt++<<endl;
                Cal();
                cout<<endl;
                for(i = 1; i<= N; i++) {
                        L[i].clear();
                        for( u = 1; u <= N; u++)
                                B[i][u] = 0;
                }
        
        return 0;
}
//@END_OF_SOURCE_CODE
