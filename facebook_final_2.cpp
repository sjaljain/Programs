#include <stdio.h>

#define MIN(a, b) ((a < b) ? a : b)
#define INF 100000000
#define MAXN 110

int numNodes, numEdges, home, school;
int adjacencyMatrix[MAXN][MAXN];

int timeStamp;
int visited[MAXN], parent[MAXN], discovery[MAXN], lowestReachable[MAXN];

int top;
int source[MAXN], destination[MAXN];

int res;

void pushEdge(int u, int v) {
    source[top] = u;
    destination[top] = v;
    top++;
}

void component(int u, int v) {
    int count;
    int i, _u, _v;
    int flag[MAXN];

    count = 0;
    for (i = 0; i < numNodes; ++i)
        flag[i] = 0;
    do {
        top--;

        _u = source[top];
        _v = destination[top];

        flag[_u] = flag[_v] = 1;
    } while (_u != u && _v != v);

    if (flag[home] && flag[school]) {
        for (i = 0; i < numNodes; ++i)
            if (flag[i])
                ++count;
        res = count;
    }
}

void dfsVisit(int u) {
    int v;

    visited[u] = 1;
    timeStamp++;
    lowestReachable[u] = discovery[u] = timeStamp;

    for (v = 0; v < numNodes; ++v) {
        if (adjacencyMatrix[u][v]) {
            if (!visited[v]) {
                pushEdge(u, v);
                parent[v] = u;
                dfsVisit(v);
                if (lowestReachable[v] >= discovery[u])
                    component(u, v);
                lowestReachable[u] = MIN(lowestReachable[u], lowestReachable[v]);
            }
            else if (parent[u] != v && discovery[v] < discovery[u]) {
                pushEdge(u, v);
                lowestReachable[u] = MIN(lowestReachable[u], discovery[v]);
            }
        }
    }
}

int main() {
    int testCases, testNumber;
    scanf("%d", &testCases);

    for (testNumber = 1; testNumber <= testCases; ++testNumber) {
        int i, j;
        int u, v;
        int edgeHomeToSchool;

        scanf("%d %d %d %d", &numNodes, &numEdges, &home, &school);
        for (i = 0; i < numNodes; ++i)
            for (j = 0; j < numNodes; ++j)
                adjacencyMatrix[i][j] = 0;
        for (i = 1; i <= numEdges; ++i) {
            scanf("%d %d", &u, &v);
            adjacencyMatrix[u][v] = adjacencyMatrix[v][u] = 1;
        }

        edgeHomeToSchool = 0;
        if (adjacencyMatrix[home][school])
            edgeHomeToSchool = 1;
        else
            adjacencyMatrix[home][school] = adjacencyMatrix[school][home] = 1;

        timeStamp = 0;
        for (i = 0; i < numNodes; ++i) {
            visited[i] = 0;
            parent[i] = -1;
            discovery[i] = INF;
            lowestReachable[i] = INF;
        }

        top = 0;
        res = 0;

        for (i = 0; i < numNodes; ++i)
            if (!visited[i])
                dfsVisit(i);

        if (res == 2 && !edgeHomeToSchool)
            res = 0;

        printf("%d\n", res);
    }

    return 0;
}
