#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 251;

int main()
{
  int T;cin>>T;while(T--){
    int n;cin>>n;
    int a[251],L[251];
    int i;
    for(i=0;i<n;i++)cin>>a[i];
    for (i = 0; i < n; i++) {
      L[i] = 1;
      for (int j = 0; j < i; j++) {
	if (L[i] <= L[j] && a[i] == (a[j] + 1))
	  L[i] = L[j] + 1;
     }
    }
 int largest = 0;
 for (i = 0; i < n; i++) {
     if (L[i] > largest)
  largest = L[i];
 }

 cout<<n-largest<<endl;
  }
    return 0;
}
