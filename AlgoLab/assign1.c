#include<stdio.h>
#include<stdlib.h>

int N,K;

void print(int *arr)
{
	int i;
	for(i=0;i<N;i++)
	printf("%d",arr[i]);
	
	printf("\n");
	return ;
}

int recurse(int *arr,int filled_val,int remain)
{
	
	int cnt=0;
	/*Case with the final array*/
	if(remain==0)
	{
		print(arr);
		return 1;
	}

	if(K-filled_val==remain)
	{
		int filled=N-remain;		
		arr[filled]=filled_val+1;
		cnt+=recurse(arr,filled_val+1,remain-1);
	}
	else
	{
		int filled=N-remain;
		if(filled_val+1<=K)
		{
			arr[filled]=filled_val+1;
			cnt+=recurse(arr,filled_val+1,remain-1);
		}
		if(filled_val>=1)
		{		
		arr[filled]=filled_val;
		cnt+=recurse(arr,filled_val,remain-1);
		}
	}

	return cnt;
	

}


int main()
{

printf("Enter value of N: ");
scanf("%d",&N);
printf("Enter value of K: ");
scanf("%d",&K);
int *arr;
arr = (int *)malloc((N)*sizeof(int));
printf("The possibilities are: \n");
printf("Total number of possibilities = %d\n",recurse(arr,0,N));

return 0;
}


