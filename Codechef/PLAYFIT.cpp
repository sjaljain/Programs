#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
    {
      int N;
      scanf("%d",&N);
      vector<int> v(N,0),min(N,0);
      for(int i=0;i<N;i++)scanf("%d",&v[i]);
      int max_diff=0;

      int small=v[0];
      for(int i=1;i<N;i++)
	{
	  int diff=v[i]-small;
	  if(diff>max_diff)max_diff=diff;
	  if(v[i]<small)small=v[i];
	}
      if(!max_diff)printf("UNFIT\n");
      else printf("%d\n",max_diff);
    }
  return 0;
}
