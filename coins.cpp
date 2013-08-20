/*
 * Sajal Jain
 * Adobe interview question
 * There are coins of 25 10 5 and 1 Rs. You got to tell in how many ways you can make change for an amount X.
 * A working code was required,
 */

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int X;cin>>X;
    int A[]={1,5,10,25};
    int table[X+1][4];
    for(int i=0;i<=X;i++)
    {
        for(int j=0;j<=3;j++)
        {
            if(i==0){table[i][j]=1;continue;}
            //if((i-A[j])<0){table[i][j]=1;continue;}
            table[i][j]=0;
            if(i-A[j]>=0)table[i][j]+=table[i-A[j]][j];
            if (j-1>=0)table[i][j]+=table[i][j-1];
        }
    }
//    for(int i=0;i<=X;i++)
//    {
//        for(int j=0;j<=3;j++)
//        cout<<table[i][j]<<" ";
//
//        cout<<endl;
//    }
    cout<<table[X][3];
    return 0;
}
