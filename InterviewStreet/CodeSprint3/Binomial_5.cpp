
#include <stdio.h>
#include <math.h>
#include <map>
#include <utility>
#include <vector>
#include <iostream>
#define Prime 27
//#define P 142857
//#define P 1009
using namespace std;
int N,K;
int binomial[50][50];

int modInverse(int a,int m) {
    int res=1;
    for(int i=1;i<=17;i++)
    {
        res=(res*a)%m;

    }
    return res;
}

int power(int a,int b)
{
    if(b==0) return 1;
    int c=a;
    for(int i=2;i<=b;i++)
        a*=c;

    return a;
}

int main()
{

	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d %d",&N,&K);
		int answer=1;
		long long Ncpy=N,Kcpy=K;
		int P[]={27,11,13,37};
		int ans[4];
		//do something different for 3^3 = 27 and store in ans[0]
        int M=K;
        int R=N-M;
         int pow3=1;
         while(power(3,pow3)<=N)pow3++;
         //cout<<pow3;
         pow3++;

         vector<int> Nv(pow3),Rv(pow3),Mv(pow3);
         for(int i=0;i<pow3;i++)
         {
             Nv[i]=(N/power(3,i))%27;
             Rv[i]=(R/power(3,i))%27;
             Mv[i]=(M/power(3,i))%27;
         }

         vector<int> nv(pow3+2),rv(pow3+2),mv(pow3+2);
         //N=n0+n1*3+n2*9

         for(int i=0;i<pow3;i++)
         {
             nv[i]=Nv[i]%3;
             mv[i]=Mv[i]%3;
             rv[i]=Rv[i]%3;
         }
         nv[pow3]=(Nv[pow3-1]/3)%27;nv[pow3+1]=(Nv[pow3-1]/9)%27;
         rv[pow3]=(Rv[pow3-1]/3)%27;rv[pow3+1]=(Rv[pow3-1]/9)%27;
         mv[pow3]=(Mv[pow3-1]/3)%27;mv[pow3+1]=(Mv[pow3-1]/9)%27;

         int e2=0,e0=0;
         for(int i=0;i<pow3+2;i++)
         {
             if(nv[i]<=mv[i])e0++;
             if(nv[i]<=mv[i] && i>=2)e2++;
         }

         //cout<<e0<<" "<<e2<<endl;
         int ans2=(int)power(3,e0);
         ans2*=(int)power(-1,e2);
         //cout<<ans<<endl;
         ans2=(ans2+27)%27;
         //cout<<ans2;
/*
     for(int i=0;i<pow3;i++)
     cout<<Nv[i]<<" "<<Mv[i]<<" "<<Rv[i]<<endl;

     for(int i=0;i<pow3+2;i++)cout<<nv[i]<<" ";cout<<endl;
     for(int i=0;i<pow3+2;i++)cout<<rv[i]<<" ";cout<<endl;
     for(int i=0;i<pow3+2;i++)cout<<mv[i]<<" ";cout<<endl;
*/

     for(int j=0;j<pow3;j++)
     {
         for(int i=2;i<=Nv[j];i++){if(i%3==0)continue;ans2=(ans2*i)%27;}
     }

     for(int j=0;j<pow3;j++)
     {
         for(int i=2;i<=Mv[j];i++){if(i%3==0)continue;ans2=(ans2*modInverse(i,27))%27;}
     }
     for(int j=0;j<pow3;j++)
     {
         for(int i=2;i<=Rv[j];i++){if(i%3==0)continue;ans2=(ans2*modInverse(i,27))%27;}
     }

     //cout<<(ans2+27)%27<<" ";
	 ans[0]=ans2;
	 //cout<<N%27<<" ";

		for(int m=1;m<4;m++)
		{
		    int answer=1;
            for(int i=0;i<=P[m];i++)
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                {
                    binomial[i][j]=1;
                    continue;
                }
                binomial[i][j]=(binomial[i-1][j]+binomial[i-1][j-1])%P[m];
            }

            while(N)
            {
                int Nk=N%P[m];
                int Kk=K%P[m];
                if(Kk>Nk)
                {
                    answer=0;
                    break;
                }
                answer=(answer*binomial[Nk][Kk])%P[m];
                //cout<<answer<<endl;
                N=N/P[m];
                K=K/P[m];
            }
            ans[m]=answer;
            N=Ncpy;K=Kcpy;
		}



		//printf("%d %d %d %d\n",ans[0],ans[1],ans[2],ans[3]);
		for(int i=0;i<142857;i++)
		{
		    if(i%27!=ans[0])continue;
		    if(i%11!=ans[1])continue;
		    if(i%13!=ans[2])continue;
		    if(i%37!=ans[3])continue;
		    printf("%d\n",i);break;
		}
	}

    return 0;
}
