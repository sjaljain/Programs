#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	int T;scanf("%d",&T);while(T--){
		int done=0;int i,j;
		//char *position;
		//position=(char *)malloc(100*sizeof(char));
		char A[100][101],B[100][101];
		int R,C;scanf("%d%d",&R,&C);
		char ch;
		scanf("%c",&ch);
		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
			{
					scanf("%c",&A[i][j]);
					B[j][i]=A[i][j];
			}
					scanf("%c",&ch);
		}	
		for(i=0;i<R;i++)A[i][C]='\0';	
		for(i=0;i<C;i++)B[i][R]='\0';	

		//printf("%s",A[0]);
		//printf("%s",strcasestr(A[i],"spoon"));
		
		for(i=0;i<R && !done;i++)
			{
				if(strcasestr(A[i],"spoon")!=NULL){printf("There is a spoon!");done=1;}
			}			
		for( i=0;i<C && !done;i++)
			{
				if(strcasestr(B[i],"spoon")!=NULL){printf("There is a spoon!");done=1;}
			}	
			
		if(!done) printf("There is indeed no spoon!");
		printf("\n");
		
	}
	return 0;	
}
