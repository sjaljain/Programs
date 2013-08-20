#include<cstdio>
#include<cstring>
const long long oo=1000000007;
int T,i;
long long N,Ans;
long long A[4],a[4],B[4][4],b[4][4],C[65][4][4];
void Mul1()
{
	int i,j;
	memset(a,0,sizeof(a));
	for(i=0;i<4;++i) if(A[i])
		for(j=0;j<4;++j) if(B[i][j])
			a[j]=(a[j]+A[i]*B[i][j])%oo;
	memcpy(A,a,sizeof(A));
}
void Mul2()
{
	int i,j,k;
	memset(b,0,sizeof(b));
	for(i=0;i<4;++i)
		for(j=0;j<4;++j) if(B[i][j])
			for(k=0;k<4;++k) if(B[j][k])
				b[i][k]=(b[i][k]+B[i][j]*B[j][k])%oo;
	memcpy(B,b,sizeof(B));
}
long long Mul(long long x)
{
	int i=0;
	for(;x;)
	{
		++i;
		if(x&1)
		{
			memcpy(B,C[i],sizeof(B));
			Mul1();
		}
		x/=2;
	}
	return (A[0]+2*A[1]+3*A[2]+A[3])%oo;
}
long long Quick(long long x,long long y)
{
	long long s=1;
	for(;y;)
	{
		if(y&1) s=s*x%oo;
		x=x*x%oo,y/=2;
	}
	return s;
}
int main()
{
	B[0][0]=1;B[1][0]=2;B[2][0]=3;B[3][0]=1;
	B[0][1]=1;B[1][2]=1;B[2][3]=1;


	for(i=1;i<=64;++i)
	{
		memcpy(C[i],B,sizeof(C[i]));
		Mul2();
	}
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld",&N);
		A[0]=1,A[1]=2;A[2]=5;A[3]=12;
		Ans=(Quick(2,N)+oo-Mul(N))%oo;
		printf("%d\n",Ans);
	}
	return 0;
}
