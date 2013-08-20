#include<iostream>
#include<vector>

using namespace std;

void clockwise(int i);
void anticlockwise(int i);

int A[1000][1000],B[1000][1000]={0};
int N;

int main()
{
	cin>>N;
		
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>A[i][j];
			
	for(int i=0;i<N;i++)
		if(i%2==0)clockwise(i); 
		else anticlockwise(i);
		
		//cout<<endl;
		if(N%2==1) B[N/2][N/2]=A[N/2][N/2];
		
	for(int i=0;i<N;i++)
		{
		for(int j=0;j<N;j++)
			cout<<B[i][j]<<" ";
		cout<<endl;
		}
		
		
	
	return 0;
}

void clockwise(int i)
{
	int num=N-2*i;
	for(int j=i;j<i+num-1;j++)
		B[i][j+1]=A[i][j];
		
	for(int k=i;k<i+num-1;k++)
		B[k+1][i+num-1]=A[k][i+num-1];
			
			
	for(int j=i+1;j<i+num;j++)
		B[i+num-1][j-1]=A[i+num-1][j];
		
	for(int k=i+1;k<i+num;k++)
		B[k-1][i]=A[k][i];
		
}


void anticlockwise(int i)
{
	int num=N-2*i;
	
	for(int j=i+1;j<i+num;j++)
		B[i][j-1]=A[i][j];
		
	for(int k=i+1;k<i+num;k++)
		B[k-1][i+num-1]=A[k][i+num-1];

	for(int j=i;j<i+num-1;j++)
		B[i+num-1][j+1]=A[i+num-1][j];
		
	for(int k=i;k<i+num-1;k++)
		B[k+1][i]=A[k][i];
			
			

		
	
		
}
