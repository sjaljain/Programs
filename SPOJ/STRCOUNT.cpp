#include<iostream>
#include<vector>

using namespace std;
 long long int A[64][64]={0};
int main()
{
 
  A[0][0]=1;
 for(int n=1;n<=63;n++)
    {
      A[n][0]=1;A[n][n]=1;
      for(int k=1;k<=n-1;k++)
	{
	  A[n][k]=A[n-1][k];
          for(int i=0;i<=k;i++)
		A[n][k]+=A[n-k-1][i];
	
	  for(int i=1;i<k;i++)
	    A[n][k]+=A[n-i-1][k];
	}
      // A[n][n]=1;
    }

  for(int n=1;n<=63;n++)
    {
    for(int k=0;k<=n;k++)
      cout<<A[n][k]<<" ";
    cout<<endl;
    }
  
  return 0;
}
