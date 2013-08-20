/*

Title   : Smallest Permutation
Author  : SHAHID HUSSAIN KHAN

*/

#include<stdio.h>
#define MAX 102

/* A -> Permutation           G -> Adjacency Matrix based on 'Y' or 'N'         status -> used in DFS
   V -> stores vertices of disjoint graphs (one graph at a time)                merge -> used by Merge Sort */
int N=0,A[MAX],G[MAX][MAX],status[MAX],V[MAX][2],v,ind,merge[MAX];

int DFS(int i)
{
     status[i]=2;
     int j;
     for(j=0;j<N;j++)
     if(G[i][j]==1 && status[j]==1) DFS(j);
     V[v][0]=i;
     V[v++][1]=A[i];
}

int Merge(int p,int q,int r)
{
     int i=p,j=q+1,k=0;
     while(i<=q && j<=r) merge[k++] = (V[i][ind]<=V[j][ind])? V[i++][ind] : V[j++][ind];
     if( i>q && j<=r )
         while(j<=r) merge[k++]=V[j++][ind];
     else if( i<=q && j>r )
         while(i<=q) merge[k++]=V[i++][ind];
     for(i=p;i<=r;i++) V[i][ind]=merge[i-p];
}

int Msort(int p,int r)
{
     if(p<r)
     {
            int q=(p+r)>>1;
            Msort(p,q);
            Msort(q+1,r);
            Merge(p,q,r);
     }
}

void solve()
{
     int i,j;
     for(i=0;i<N;i++) status[i]=1;
     for(i=0;i<N;i++)
     if(status[i]==1)
     {
                     v=0;
                     DFS(i);
                     for(ind=0;ind<=1;ind++) Msort(0,v-1);
                     for(j=0;j<v;j++) A[V[j][0]]=V[j][1];
     }
     for(i=0;i<N;i++)
     printf("%d%s",A[i],(i<N-1)?" ":"");
}



int main()
{
    //int T;
    //scanf("%d",&T);
    //while(T--)
    //{
              scanf("%d",&N);
              int i,j;
              for(i=0;i<N;i++)
              scanf("%d",&A[i]);
              char str[MAX];
              for(i=0;i<N;i++)
              {
                              scanf("%s",str);
                              for(j=0;str[j]!='\0';j++)
                              G[i][j]=(str[j]=='Y')?1:0;
              }
              solve();
    //}
    return 0;
}
