#include <stdio.h>

unsigned int n,m,p[1001][1001];

unsigned int inline scan()
{
    register unsigned int N = 0, C;
    while ((C = getchar_unlocked()) < '0');
    do
    {
        N = (N<<3) + (N<<1) + C - '0';
    }while ((C = getchar_unlocked()) >= '0');

    return N;
}

void inline print(unsigned int *res)
{
    register unsigned int N = * res , rev, count = 0;
    rev = N;
    if (N == 0)
    {
          putchar_unlocked('0');
//          putchar_unlocked('\n');
          return ;
    }
    while ((rev % 10) == 0)
    {
          count++;
          rev /= 10;
    }
    rev = 0;
    while (N != 0)
    {
          rev = (rev<<3) + (rev<<1) + N % 10;
          N /= 10;
    }
    while (rev != 0)
    {
          putchar_unlocked(rev%10 + '0');
          rev /= 10;
    }
    while (count--)
          putchar_unlocked('0');
//    putchar_unlocked('\n');
    return ;
}

void inline print1(unsigned int *res)
{
    register unsigned int N = * res , rev, count = 0;
    rev = N;
    putchar_unlocked(' ');
    if (N == 0)
    {
          putchar_unlocked('0');
          putchar_unlocked('\n');
          return ;
    }
    while ((rev % 10) == 0)
    {
          count++;
          rev /= 10;
    }
    rev = 0;
    while (N != 0)
    {
          rev = (rev<<3) + (rev<<1) + N % 10;
          N /= 10;
    }
    while (rev != 0)
    {
          putchar_unlocked(rev%10 + '0');
          rev /= 10;
    }
    while (count--)
          putchar_unlocked('0');
    putchar_unlocked('\n');
    return ;
}

int main()
{
   register int i,j,k;
   int t;

    int T;
    T=scan();
    while(T--)
    {


    n=scan();
    m=scan();
    int u,v,w;

    for(i=0;i<m;i++)
    {
        u=scan();v=scan();w=scan();
        p[u][v]=w;
    }



    for(k=0;k<n;k++)
	    for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                        t=p[i][k] + p[k][j];
                        if(t<p[i][j])
                        p[i][j]=t;
            }

 	n=scan();
 	while(n--)
 	{
	 		  i=scan();j=scan();;
			  t=p[i][j];
 			  print(&t);

    }


    }
    return 0;
}
