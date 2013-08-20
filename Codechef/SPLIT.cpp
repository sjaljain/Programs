#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    vector<int> cnt(500,0), cut;
    for (int i = 0, k = 0; i < n; ++i) {
      int s;
      cin >> s;
      cout<<(cnt[s]&1)<<"-"<<(k&1)<<endl;
      if ((cnt[s]&1) != (k&1)) {
	cut.push_back(i);
	++k;
      }
      ++cnt[s];
    }
    cout << cut.size() << endl;
 
    for (int i = 0; i < cut.size(); ++i)
      cout << cut[i] << (i+1==cut.size()?'\n':' ');
  }
}
 
