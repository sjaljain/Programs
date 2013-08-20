#include <iostream>
#include <stdlib.h>
using namespace std;

int partition(int* input, int p, int r)
{
    int pivot = input[r];
    
    while ( p < r )
    {
        while ( input[p] < pivot )
            p++;
        
        while ( input[r] > pivot )
            r--;
        
        if ( input[p] == input[r] )
            p++;
        else if ( p < r ) {
            int tmp = input[p];
            input[p] = input[r];
            input[r] = tmp;
        }
    }
    
    return r;
}

int quick_select(int* input, int p, int r, int k)
{
    if ( p == r ) return input[p];
    int j = partition(input, p, r);
    int length = j - p + 1;
    if ( length == k ) return input[j];
    else if ( k < length ) return quick_select(input, p, j - 1, k);
    else  return quick_select(input, j + 1, r, k - length);
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,K;
		int *A1;
		
		cin>>N>>K;
		
		A1 = (int *)malloc(N * sizeof(int));
		for(int i=0;i<N;i++)
			cin>>A1[i];
			
		//int A1[] = { 100, 400, 300, 500, 200 };
        int value=quick_select(A1, 0, N-1, N+1-K);
        
        //for(int i=0;i<N;i++) cout<<A1[i]<<" ";
       // cout<<value;
        int sum=0;
        for(int i=N-1;i>=N-K;i--)
			sum+=A1[i];
        
        cout<<sum<<endl;
	
	}
return 0;
}

