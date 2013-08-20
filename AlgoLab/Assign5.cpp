/* Sajal Jain , 09EC1017
 * Assignment 5
 * CabTaxi Numbers
 * Math, Minheap
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct element
{
  int a;
  int b;
  long long int s;
  element(int _a,int _b,long long int _s){a=_a;b=_b;s=_s;}
};

//Queue to check the Cabitax numbers
queue<element> Q;
int cabitax=1;
int notdisplayed=0;

long long int sum_cube(int a,int b)
{
    long long int s;
    long long int _a=(long long int)a;
    long long int _b=(long long int)b;
    s=(_a*_a*_a)+(_b*_b*_b);
    return s;
}

void swap_elem(element &a,element &b)
{
    element temp(0,0,0);
    temp=a;
    a=b;
    b=temp;
}

void deletemin(vector<element> &Heap,int &N)
{
    Heap[1]=Heap[N];
    N--;
    int i=1;
    int heapify=1;
    while(2*i<=N)
    {
        if(2*i<=N && Heap[i].s>Heap[2*i].s)
        heapify=2*i;
        if(2*i+1<=N && Heap[i].s>Heap[2*i+1].s && Heap[2*i+1].s<Heap[2*i].s)
        heapify=2*i+1;
        swap_elem(Heap[i],Heap[heapify]);

        if(heapify==i)break;
        i=heapify;
    }

    return ;
}

void insert(vector<element> &Heap,int &N, element e)
{
    N++;
    Heap[N]=e;
    int i=N;
    while(i>=1)
    {
        if(Heap[i/2].s>Heap[i].s)
        swap(Heap[i/2],Heap[i]);
        i/=2;
    }

    return ;
}

int next_b(int a,int b)
{
    int next;
    if(b==0)
        next=a;
    else next=b+1;

    return next;
}

void check_count(element elem)
{
    if(Q.empty() || Q.front().s==elem.s)
          Q.push(elem);
    else if(Q.front().s!=elem.s)
    {
        Q.pop();
        Q.push(elem);
    }

    if(Q.size()==cabitax)
    {
        printf("CT(%d) = %llu\n",cabitax,Q.front().s);
        while(!Q.empty())
        {
            printf("      = (%d)^3 + (%d)^3\n",Q.front().a,Q.front().b);
            Q.pop();
        }
        cabitax++;
        if(cabitax==6)
            notdisplayed=1;
    }
    if(notdisplayed)
    {
        printf("\nPlease wait for larger Cabitax numbers...\n");
        notdisplayed=0;
    }

}

int main()
{
    int B;
    printf("Enter bound B: ");
    scanf("%d",&B);

    //Initializing the Heap
    vector<element> Heap;
    //Pushing garbage at index 0
    Heap.push_back(element(0,0,0));
    for(int a=1;a<=B;a++)
           Heap.push_back(element(a,1-a,sum_cube(a,1-a)));

    //N will "always" contain the index of the last element
    int N=Heap.size()-1;

    while(N!=0)
    {
        element del(Heap[1].a,Heap[1].b,Heap[1].s);
        check_count(del);
        deletemin(Heap,N);
        int nextb=next_b(del.a,del.b);
        if(nextb<=B)
        {
            element ins(del.a,nextb,sum_cube(del.a,nextb));
            insert(Heap,N,ins);
        }
    }
   return 0;
}
