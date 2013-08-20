//@BEGIN_OF_SOURCE_CODE
/*
 * 
Sample Input & Output
4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
0
* 
Network 1
The bandwidth is 25.
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
        cout<<"The bandwidth is "<<Res<<".\n";
}

int main() {
        int u, v, c, nt = 1, i;
        //freopen("h.txt","r",stdin);
        while(cin>> N && N) {//number of nodes
                cin>>S>>T>>C;//source destination total_number_of_connections
                while(C--) {
                        cin>>u>>v>>c;
                        L[u].push_back(v);//undirected graph example, change for directed
                        L[v].push_back(u);//also it does not considers multiple connections between the nodes
                        B[u][v] += c;
                        B[v][u] += c;
                }
                cout<<"Network "<<nt++<<endl;
                Cal();
                cout<<endl;
                for(i = 1; i<= N; i++) {
                        L[i].clear();
                        for( u = 1; u <= N; u++)
                                B[i][u] = 0;
                }
        }
        return 0;
}
//@END_OF_SOURCE_CODE
