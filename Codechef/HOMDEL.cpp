#include<stdio.h>
#include<iostream>

#define INF 99999

using namespace std;

int N;
long long int dist[251][251];

// A function to print the solution matrix
void printSolution(long long int dist[][251]);
// Solves the all-pairs shortest path problem using Floyd Warshall algorithm
void floydWarshell (long long int graph[][251])
{
    /* dist[][] will be the output matrix that will finally have the shortest 
      distances between every pair of vertices */
    int i, j, k;
 
    /* Initialize the solution matrix same as input graph matrix. Or 
       we can say the initial values of shortest distances are based
       on shortest paths considering no intermediate vertex. */
    for (i = 1; i <= N; i++)
        for (j = 1; j <= N ; j++)
            dist[i][j] = graph[i][j];
 
    /* Add all vertices one by one to the set of intermediate vertices.
      ---> Before start of a iteration, we have shortest distances between all
      pairs of vertices such that the shortest distances consider only the
      vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
      ----> After the end of a iteration, vertex no. k is added to the set of
      intermediate vertices and the set becomes {0, 1, 2, .. k} */
    for (k = 1; k <= N; k++)
    {
        // Pick all vertices as source one by one
        for (i = 1; i <= N; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 1; j <= N; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
    // Print the shortest distance matrix
    //printSolution(dist);
}
 
/* A utility function to print solution */
void printSolution(long long int dist[][251])
{
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 1; i <=N; i++)
    {
        for (int j = 1; j <=N; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
 
// driver program to test above function
int main()
{
    cin>>N;
    long long int graph[251][251];
    for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                    cin>>graph[i][j];
 
    // Print the solution
    floydWarshell(graph);
    int M;
    cin>>M;
    int S,G,D;
    for(int i=0;i<M;i++)
    {
            cin>>S>>G>>D;
            S++;G++;D++;
            int time=dist[S][G]+dist[G][D];
            cout<<time<<" "<<time-dist[S][D]<<endl;
    }
    //getchar();
    //getchar();
    return 0;
}
