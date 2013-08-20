#include<iostream>
#include<set>
using namespace std;


int main()
{
int n,k;
cin >> n >> k;
if(k > n) k=n;
int i,x;
multiset<int> s;
multiset<int>::iterator it;
for(i=0;i<n;i++) {
    cin >> x;
    s.insert(x);
}

//start calculating cost
int factor = 0;
unsigned long long int cost=0;
int count = 0;
it = s.end(); it--;
while(count!=n)
{
    if(count%k==0) factor+=1;
    cost+=(*it * factor);
    it--;
    count++;
}
cout << cost << endl;
cin >> cost;
}
