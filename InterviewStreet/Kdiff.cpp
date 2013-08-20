#include<iostream>
#include<set>

using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;
    multiset<int> s;
    for(int i=0;i<N;i++)
    {
            int a;cin>>a;
            s.insert(a);
            }
    int count=0;
    multiset<int>::iterator pos;
    for(pos=s.begin();pos!=s.end();pos++)
             count+=s.count((*pos)+K);
    
    cout<<count;
               
    
    return 0;
}
