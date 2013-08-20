#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cassert>
using namespace std;

struct node
{
	int div[3];//div[0] is the value, div[1] =number of values greater than 60 and div[2] = less than 60
	int inc;//number of increments (flag to keep the count of updates)
}s[1100000];

int a[110000];

void make_tree(int start,int end,int num)
{
    //num=1 is the root, Add values from 'a' after num>n. Then propagate
    //the values to the root
	if(start==end)
	{
		/*s[num].div[0]=s[num].div[1]=s[num].div[2]=0;//Initializing to 0
		s[num].div[a[start]%3]=1;
		*/

		s[num].inc=0;//This is the flag for lazy propagation (counting number of updates)
		return;
	}

	else
	{
		make_tree(start,(start+end)/2,2*num);
		make_tree((start+end)/2+1,end,2*num+1);
        //Propagating values to the root
		s[num].div[0]=s[2*num].div[0]+s[2*num+1].div[0];
		s[num].div[1]=s[2*num].div[1]+s[2*num+1].div[1];
		s[num].div[2]=s[2*num].div[2]+s[2*num+1].div[2];

		return;
	}
}


//Increasing numbers between start and end by 1
void update(int start,int end,int num,int i,int j)
{
//	printf("1\n");
	if(i>end || j<start)
		return;

	else if(i<=start && j>=end)
	{
		s[num].inc++;//flag updated
		//node values updated
		swap(s[num].div[0],s[num].div[1]);
		swap(s[num].div[0],s[num].div[2]);
		return;

	}


	update(start,(start+end)/2,2*num,i,j);
	update((start+end)/2+1,end,2*num+1,i,j);

//	printf("1\n");
    //update values of all nodes till root
	for(int k=0;k<3;k++)
		s[num].div[k]=s[2*num].div[k]+s[2*num+1].div[k];
//	printf("2\n");

    //Rippling the effect of increment to the root node
    //Remember the flag is kept for the nodes lower in the level than the flag
    //All nodes above the flag need to be updated


	if(s[num].inc%3==1)
	{
		swap(s[num].div[0],s[num].div[1]);
		swap(s[num].div[0],s[num].div[2]);
	}
	if(s[num].inc%3==2)
	{
		swap(s[num].div[0],s[num].div[1]);
		swap(s[num].div[1],s[num].div[2]);
	}




	return;

}

int query(int start,int end,int num,int i,int j,int ctr)
{

	if(i>end || j<start)
		return 0;
	else if(i<=start && j>=end)
	{
//		printf("!! %d %d\n",num,s[num].div[1]);
		if(ctr%3==0)
			return s[num].div[0];
		else if(ctr%3==1)
			return s[num].div[2];
		return s[num].div[1];
	}
	ctr+=s[num].inc;

	int p1=query(start,(start+end)/2,2*num,i,j,ctr);
	int p2=query((start+end)/2+1,end,2*num+1,i,j,ctr);
//	printf("%d \n",p1);

	return p1+p2;
}
int main()
{

	int n,q;
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(a));

	scanf("%d%d",&n,&q);//n=Number of integers, Q=number of queries
	make_tree(1,n,1); //Initially all elements are 0

//	for(int i=1;i<=n;i++)
//		printf("%d\n",s[i].div[0]);


	for(int i=0;i<q;i++)
	{
		node temp;
		int l,r,code;

		scanf("%d%d%d",&code,&l,&r);
		l++;r++;
		if(code==1)
			printf("%d\n",query(1,n,1,l,r,0));
		else
			update(1,n,1,l,r);
	}


/*	for(int i=1;i<=2*n+1;i++)
		printf("%d%d%d\n",s[i].div[0],s[i].div[1],s[i].div[2]);*/
}
