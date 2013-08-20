#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[300][300][3];
    for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {cin>>A[i][j][0];A[i][j][1]=0;A[i][j][2]=0;}
            
    A[0][0][1]=A[0][0][0];
    A[0][0][2]=A[0][0][0];
    
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)
            {
                    if(i==0 || j==0)
                    {
                            A[i][j][1]=A[i][j][0];
                            A[i][j][2]=A[i][j][0];
                            }
                    else
                    {
                    A[i][j][1]=max(A[i][j-1][1],A[i-1][j][1])+A[i][j][0];
                    A[i][j][2]=max(max(A[i-1][j][1]+A[i][j-1][1],A[i-1][j][2]),A[i][j-1][2])+A[i][j][0];
                    }
                    }
                    }
            for(int i=0;i<n;i++)
            {
                    for(int j=0;j<n;j++)
                    cout<<A[i][j][2]<<" ";
                    
                    cout<<endl;
                    }
    getchar();
    getchar();
    
    return 0;
}
