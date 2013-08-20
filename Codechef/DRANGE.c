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
    int T;
    T=FAST_IO();
    while(T--)
    {
    int N,i;
    N=FAST_IO();
    int *v,*p;
    v=(int*)malloc((N)*sizeof(int));
    p=(int*)malloc((N+1)*sizeof(int));
    //v=new int[N];
    //p=new int[N+1];    
    for( i=0;i<N;i++){v[i]=i+1;p[i]=0;}p[N]=0;
    
    int M;
    scanf("%d",&M);
    for(i=0;i<M;i++)
    {
            int w,x,y,z;
            w=FAST_IO();
            x=FAST_IO();
			y=FAST_IO();
			z=FAST_IO();
            if(w==1){p[x-1]+=z;p[y]-=z;}
            else {p[x-1]-=z;p[y]+=z;}
            }
    
    int k=0;
    int min=999999,max=-999999;
    for( i=0;i<N;i++)
    {
            k+=p[i];
            v[i]+=k;
            if(v[i]>max)max=v[i];
            if(v[i]<min)min=v[i];
            }
    
    //for(long long int i=0;i<N;i++)
         // cout<<v[i]<<" ";
     printf("%d\n",max-min);
    }
    
   
    //getchar();
    //getchar();
    return 0;
}
