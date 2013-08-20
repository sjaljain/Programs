/*
 * Write a program that searches a directed graph for vertices which are inaccessible from a given starting vertex.

A directed graph is represented by n vertices where tex2html_wrap_inline31 , numbered consecutively tex2html_wrap_inline33 , and a series of edges p -> q which connect the pair of nodes p and q in one direction only.

A vertex r is reachable from a vertex p if there is an edge p -> r, or if there exists some vertex q for which q is reachable from p and r is reachable from q.

A vertex r is inaccessible from a vertex p if r is not reachable from p. 
* 
* FLOYD WARSHALL ALGORITHM
* */

#include<iostream>
#include<vector>
#include<algorithm>

#define MAXN 102
#define INF 999999999L

using namespace std;

int main() {
	int t = 1, n, N, i, j, k;
	while ((cin >> N) && (n = N)) {
		double g[MAXN][MAXN];
		for(i=0;i<MAXN;i++)for(j=0;j<MAXN;j++)	g[i][j] = INF;
		while ((cin >> i) && i) while ((cin >> j) && j) g[i][j] = 1;
		
		// Floyd-Warshall DP
		for(k=1;k<N+1;k++)
			for( i=1;i<N+1;i++)
				for( j=1;j<N+1;j++)
			g[i][j] = min(g[i][j], g[i][k]+g[k][j]);


		cin >> t;
		while (t--) {
			cin >> i;
			vector<int> ans;
			for( j=1;j<N+1;j++) if (g[i][j] == INF)	ans.push_back(j);
			cout << ans.size();
			for(j=0;j<ans.size();j++) cout << " " << ans[j];
			cout << endl;
		}
	}
	return 0;
}
