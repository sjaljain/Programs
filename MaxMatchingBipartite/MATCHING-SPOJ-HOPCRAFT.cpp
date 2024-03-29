#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int BUF_SIZE = 65536;
char input[BUF_SIZE];

struct Scanner {
	char* curPos;

	Scanner() {
		fread(input, 1, sizeof(input), stdin);
		curPos = input;
	}

	void ensureCapacity(){
		int size = input + BUF_SIZE - curPos;
		if (size < 100) {
			memcpy(input, curPos, size);
			fread(input + size, 1, BUF_SIZE - size, stdin);
			curPos = input;
		}
	}

	int nextInt() {
		ensureCapacity();
		while (*curPos <= ' ') ++curPos;
		int res = 0;
		while (*curPos > ' ')
			res = res * 10 + (*(curPos++) & 15);
		return res;
	}
};

const int MAXN1 = 50000;
const int MAXN2 = 50000;
const int MAXM = 150000;

int n1, n2, edges, last[MAXN1], prev[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];

void init(int _n1, int _n2) {
	n1 = _n1;
	n2 = _n2;
	edges = 0;
	fill(last, last + n1, -1);
}

void addEdge(int u, int v) {
	head[edges] = v;
	prev[edges] = last[u];
	last[u] = edges++;
}

void bfs() {
	fill(dist, dist + n1, -1);
	int sizeQ = 0;
	for (int u = 0; u < n1; ++u) {
		if (!used[u]) {
			Q[sizeQ++] = u;
			dist[u] = 0;
		}
	}
	for (int i = 0; i < sizeQ; i++) {
		int u1 = Q[i];
		for (int e = last[u1]; e >= 0 ; e = prev[e]) {
			int u2 = matching[head[e]];
			if (u2 >= 0 && dist[u2] < 0) {
				dist[u2] = dist[u1] + 1;
				Q[sizeQ++] = u2;
			}
		}
	}
}

bool dfs(int u1) {
	vis[u1] = true;
	for (int e = last[u1]; e >= 0; e = prev[e]) {
		int v = head[e];
		int u2 = matching[v];
		if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
			matching[v] = u1;
			used[u1] = true;
			return true;
		}
	}
	return false;
}

int maxMatching() {
	fill(used, used + n1, false);
	fill(matching, matching + n2, -1);
	for (int res = 0;;) {
		bfs();
		fill(vis, vis + n1, false);
		int f = 0;
		for (int u = 0; u < n1; ++u)
			if (!used[u] && dfs(u))
				++f;
		if (!f)
			return res;
		res += f;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif

	Scanner sc;

	int V1 = sc.nextInt();
	int V2 = sc.nextInt();
	init(V1, V2);
	int e = sc.nextInt();

	while(e--){
		int u = sc.nextInt() - 1;
		int v = sc.nextInt() - 1;
		addEdge(u, v);
	}

	printf("%d\n", maxMatching());

	return 0;
}
