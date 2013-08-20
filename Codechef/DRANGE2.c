#include<stdio.h>

#include<stdlib.h>


 

inline int FAST_IO() 


{

	int xxxx;


	char ch;

	int Negativity=0;


	while (((ch=getchar_unlocked()) < 48 || ch > 57) && ch != '-');


	xxxx=0;

	if (ch == '-') Negativity=1;


	else xxxx = ch-48;


	while ((ch=getchar_unlocked()) >= 48 && ch <= 57) xxxx=xxxx*10+ch-48;


	if (Negativity) return -xxxx;


	else return xxxx;


}  

 

int main()


{

	int *a,T,n,m,i,max,min,w,x,y,z;


	T=FAST_IO();


	while(T--){


		n=FAST_IO();


		a=(int*)malloc((n+1)*sizeof(int));

		

		m=FAST_IO();


		while(m--){


			w=FAST_IO();


			x=FAST_IO();


			y=FAST_IO();


			z=FAST_IO();


			if(w==2){


				a[x]-=z;


				if(y!=n)


					a[y+1]+=z;


			}

			if(w==1){


				a[x]+=z;


				if(y!=n)


					a[y+1]-=z;


			}

		}


		a[1]++;


		max=a[1];


		min=a[1];

	

		

		for(i=2;i<=n;++i)


		{

			a[i]++;


			a[i]+=a[i-1];


			if(a[i]<min)


				min=a[i];


			if(a[i]>max)


				max=a[i];


		}

 

		printf("%d\n",max-min);


	}

	return 0;


}
