//Job Processing Heapify

#include <iostream>
#include <queue>
using namespace std;

int main ()
{
  priority_queue<int> mypq;

  int N,M;
  scanf("%d%d",&N,&M);
  for(int i=0;i<M;i++)
    mypq.push(0);

  for(int i=0;i<N;i++)
  {
      int a;
      scanf("%d",&a);
      int b=mypq.top();
      b=b-a;
      mypq.pop();
      mypq.push(b);
  }
  int min=0;
  for(int i=0;i<M;i++)
  {
      if(min>mypq.top())min=mypq.top();
      mypq.pop();
  }
  cout<<min*(-1)<<endl;

  return 0;
}
