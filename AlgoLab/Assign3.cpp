/*
Assignment 3 - Algorithm I - Laboratory
Sajal Jain, 09EC1017
 */

#include<iostream>
#include<time.h>
#include<cstdio>
#include<vector>

using namespace std;

int generate(int M)
{
     double a=(double)rand();
     return ((int)a)%M+1;
     }

int main()
{
    srand ( time(NULL) );
    int N,M;
    printf("Enter number of houses (n) : ");
    scanf("%d",&N);
    printf("Enter profit bound (M)     : ");
    scanf("%d",&M);
    vector<int> v(N);
    for(int i=0;i<N;i++)
        v[i]=generate(M);
        //cin>>v[i];
    printf("Profits are ");
    for(int i=0;i<N;i++)
        printf("%d ",v[i]);
    printf("\n");
    int sum=0;
    for(int i=0;i<N;i++)sum+=v[i];
 
    int div=sum/3;

    vector<int> parent(sum,0);
    //parent stores the house number involved with generation of this sum
    //Use of backtracking

    vector<int> v2(N,0);
    vector< vector<int> > A(sum+1,v2);
    //A is the 2d array as defined in the problem statement
    for(int i=0;i<N;i++)
        A[0][i]=1;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0){A[v[0]][0]=1;parent[v[0]]=0;break;}
            else if(A[j][i-1]==1)A[j][i]=1;
            else if(j-v[i]>=0)
            {
                if(A[j-v[i]][i-1]==1){A[j][i]=1;parent[j]=i;}
            }
        }

    }
    int S2,S1;
    for(int i=0;i<=div;i++)
    {
        if(A[i][N-1]==1)S2=i;
    }
    int min1=(sum-S2)-2*S2;
    for(int i=0;i<=(2*sum)/3;i++)
    {
        if(A[i][N-1]==1)S1=i;
    }
    int min2=S1-2*(sum-S1);
    if(min2>min1)
              S1=sum-S2;
    else
              S2=sum-S1;
    
 
    printf("Profit for first son  : %d",S1);
    printf("\nProfit for second son : %d",S2);
    int imb=S1-2*S2;
    printf("\nImbalance (S1 - 2*S2) : %d",imb);

    printf("\nFirst son gets houses   ");
    vector<int> house;
    while(S1!=0)
    {
        house.push_back(parent[S1]);
        S1=S1-v[parent[S1]];
    }
    for(int i=house.size()-1;i>=0;i--)
        printf("%d ",house[i]);

    printf("\nSecond son gets houses  ");
    for(int i=0,j=house.size()-1;i<N;i++)
    {
        if(j<0){printf("%d ",i);}
        else if(i!=house[j]){printf("%d ",i);}
        else j--;

    }

    /*
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            cout<<A[j][i]<<" ";
        }
        cout<<endl;
    }
    */
    //system("pause");

    return 0;
}
