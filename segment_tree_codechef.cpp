/*
You are given a sequence of integers A0, A1, ..., AN-1. Initially Ai=i for all i.
You need to perform some strange queries with it. Each query has the form "L R D"
where 0 <= L <= R < N and D is an integer. If D=0 then you need to find the sum
of sines of the numbers AL, AL+1, ..., AR that is sin AL + ... + sin AR.
Otherwise you need to add D to the numbers AL, AL+1, ..., AR.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include<vector>
#include<map>
#include<iostream>

#define MAX1 100000
#define MAX2 600000
#define MAX3 200000

using namespace std;

typedef long long LL;
typedef map<int, int> mp;

int n,q;

int l[MAX1],r[MAX1],D[MAX1],value[MAX3];

double sin_value[MAX2],cos_value[MAX2];

int d[MAX2];


inline int update(int x,int L,int R,int l,int r,int v)
{
        double cos2x, sin2x,cos2x1, sin2x1;
	if(R<l || r<L)
	{
	   return 0;
	}
	if(l<=L && R<=r)
	{
		d[x]+=v;
		return 1;
	}
	int M=(L+R)/2;
	update(2*x,L,M,l,r,v);
	update(2*x+1,M+1,R,l,r,v);
	cos2x=cos(1.*d[2*x]);sin2x=sin(1.*d[2*x]);cos2x1=cos(1.*d[2*x+1]);sin2x1=sin(1.*d[2*x+1]);
        cos_value[x] = (cos_value[2*x]*cos2x-sin_value[2*x]*sin2x) + (cos_value[2*x+1]* cos2x1 -sin_value[2*x+1] * sin2x1);
        sin_value[x] = (sin_value[2*x]*cos2x+cos_value[2*x]*sin2x)+ (sin_value[2*x+1]* cos2x1 +cos_value[2*x+1] * sin2x1);

}


double query(int x,int L,int R,int l,int r,int v)
{
	if(R<l || r<L) return 0.;
	v+=d[x];

	if(l<=L && R<=r)
		return sin_value[x]*cos(1.*v)+cos_value[x]*sin(1.*v);
	int M=(L+R)/2;

	double sin_value1=query(2*x,L,M,l,r,v);

	double sin_value2=query(2*x+1,M+1,R,l,r,v);

	return sin_value1+sin_value2;

}

int main()
{
	scanf("%d%d",&n,&q);//n=total numbers, q=total queries
	int i;
	for(i=0;i<q;i++)
	{
		scanf("%d%d%d",&l[i],&r[i],&D[i]);//left ,right, choice value (update/query)
	}

	int len=0;

//Store All The Value Of L and R in to array

	for(i=0;i<q;i++)
	{
		value[len++]=l[i];
		value[len++]=r[i]+1;
	}

//Sort the Array, which Contain value of L and R

	sort(value,value+len);

//Remove Repeated element from Array and Calculate the Length.

	len=unique(value,value+len)-value;
	len--;
	int m=1;

//Find the minimum value of m which is greater than 2^m > len
	for(m=1;m<len;m*=2);

	memset(d,0,8*m);

//Calculate Sum of SIN and COS value
	for(i=m;i<m+len;i++)
	{
		double Li=value[i-m],Ri=value[i-m+1];

		sin_value[i]=sin((Ri+Li-1)/2) * sin((Ri-Li)/2)/sin(0.5);
		cos_value[i]=cos((Ri+Li-1)/2) * sin((Ri-Li)/2)/sin(0.5);
	}

//Make tree based heap structure

	for(i=m-1;i>0;i--)
	{
		sin_value[i]=sin_value[2*i]+sin_value[2*i+1];
		cos_value[i]=cos_value[2*i]+cos_value[2*i+1];
	}

	for(i=0;i<q;i++)
	{
		int Li=lower_bound(value,value+len+1,l[i])-value;
		int Ri=lower_bound(value,value+len+1,r[i]+1)-value-1;

               if(D[i]) {
			update(1,0,m-1,Li,Ri,D[i]);
		} else {
			double sum=query(1,0,m-1,Li,Ri,0);
			printf("%.7lf\n",sum);
		}
	}
	return 0;
}
