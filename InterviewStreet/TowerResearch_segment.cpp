#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cassert>
using namespace std;

struct node
{
	int div[101];//all values sum range is 1-100
	int inc;//number of increments (flag to keep the count of updates)
}s[1100000];

int a[110000];
int n,q;

void make_tree(int start,int end,int num)
{
    //num=1 is the root, Add values from 'a' after num>n. Then propagate
    //the values to the root
	if(start==end)
	{
		/*s[num].div[0]=s[num].div[1]=s[num].div[2]=0;//Initializing to 0
		s[num].div[a[start]%3]=1;
		*/
		for(int p=1;p<=100;p++)
		 s[num].div[p]=0;

		s[num].div[a[start-1]]++;


		s[num].inc=0;//This is the flag for lazy propagation (counting number of updates)
		return;
	}

	else
	{
		make_tree(start,(start+end)/2,2*num);
		make_tree((start+end)/2+1,end,2*num+1);
        //Propagating values to the root
        for(int p=1;p<=100;p++)
		{
		    s[num].div[p]=s[2*num].div[p]+s[2*num+1].div[p];
		}
        //s[num].inc=0;

		//s[num].div[2]=s[2*num].div[2]+s[2*num+1].div[2];

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
		/*
		swap(s[num].div[0],s[num].div[1]);
		swap(s[num].div[0],s[num].div[2]);
		*/
		//s[num].div[0]
		for(int p=1;p<60;p++)
            {
                if(s[num].div[p])//printf("%d %d\n",num,p);
                {
                    s[num].div[p]-=1;
                    s[num].div[p-(p/3)]+=1;
                }
            }
        for(int p=60;p<=100;p++)
        {
            if(s[num].div[p])//printf("%d %d\n",num,p);
                {
                    s[num].div[p]-=1;
                    s[num].div[p-20]+=1;
                }
        }
		return;

	}


	update(start,(start+end)/2,2*num,i,j);
	update((start+end)/2+1,end,2*num+1,i,j);

//	printf("1\n");
    //update values of all nodes till root
/*
	for(int k=0;k<3;k++)
		s[num].div[k]=s[2*num].div[k]+s[2*num+1].div[k];
*/
    for(int p=1;p<=100;p++)
		{
		    s[num].div[p]=s[2*num].div[p]+s[2*num+1].div[p];
		}
//	printf("2\n");

    //Rippling the effect of increment to the root node
    //Remember the flag is kept for the nodes lower in the level than the flag
    //All nodes above the flag need to be updated
    /*
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
*/
    for(int i=1;i<=min(20,s[num].inc);i++)
	{
	    for(int p=1;p<60;p++)
            {
                if(s[num].div[p])//printf("%d %d\n",num,p);
                {
                    s[num].div[p]-=1;
                    s[num].div[p-(p/3)]+=1;
                }
            }
        for(int p=60;p<=100;p++)
        {
            if(s[num].div[p])//printf("%d %d\n",num,p);
                {
                    s[num].div[p]-=1;
                    s[num].div[p-20]+=1;
                }
        }
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
    /*
            if(ctr%3==0)
                return s[num].div[0];
            else if(ctr%3==1)
                return s[num].div[2];
            return s[num].div[1];
    */
          int dum[101];
          for(int p=1;p<=100;p++)dum[p]=s[num].div[p];

          for(int i=1;i<=min(20,ctr);i++)
            {
                for(int p=1;p<60;p++)
                    {
                        if(!dum[p])continue;
                        dum[p]--;
                        dum[p-(p/3)]++;
                    }
                for(int p=60;p<=100;p++)
                {
                    if(!dum[p])continue;
                    dum[p]--;
                    dum[p-20]++;
                }
            }
            int ans=0;
            for(int p=1;p<=100;p++)
                {
                    ans+=dum[p]*p;
                }
                return ans;
	}
	ctr+=s[num].inc;

	int p1=query(start,(start+end)/2,2*num,i,j,ctr);
	int p2=query((start+end)/2+1,end,2*num+1,i,j,ctr);
//	printf("%d \n",p1);

	return p1+p2;
}
int main()
{

    int T;
    scanf("%d",&T);
    while(T--)
    {

        memset(a,0,sizeof(a));
        //memset(s,0,sizeof(a));

        scanf("%d",&n);//n=Number of integers
        for(int i=0;i<n;i++)scanf("%d",&a[i]);

        make_tree(1,n,1); //Initially all elements are 0

        int n2=1;while(n2<n)n2*=2;n2*=2;
/*
    	for(int i=1;i<=n2;i++)
    		printf("%d %d\n",s[i].div[0],s[i].div[1]);
*/

        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            node temp;
            int l,r,code;

            scanf("%d%d%d",&code,&l,&r);
            //l++;r++;
            if(code==0)
                printf("%d\n",query(1,n,1,l,r,0));
            else
                update(1,n,1,l,r);
        }


    /*	for(int i=1;i<=2*n+1;i++)
            printf("%d%d%d\n",s[i].div[0],s[i].div[1],s[i].div[2]);*/
    }
    return 0;


}
