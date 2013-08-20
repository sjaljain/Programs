#include<iostream>
#include<set>
#include<string>
typedef unsigned long long int big;
using namespace std;

int main() {

int n,i;
cin >> n;

set<string> s;
set<string>::iterator it;

string s1,temp;
for(i=0;i<n;i++) {
    cin >> s1;
    int len = s1.length();
    int j,k;
    for(j=0;j<len;j++)
        for(k=len-j;k>0;k--) {
            temp = s1.substr(j,k);
            s.insert(temp);
        }
}

it=s.begin();
int curr = 1;
int q;
cin >> q;
big k, len;
len = s.size();
cout << len;
for(i=0;i<q;i++) {
    cin >> k;
    if(k>len) {
       cout << "INVALID\n";
       continue;
    }
    if(curr+(len/2) < k) {
      it = s.end();
      it--;
      curr = len;
    }
    if(curr-(len/2) > k) {
       it = s.begin();
       curr = 1;
    }
    if(k>curr) {
        int j= k-curr;
        while(j) { it++; j--; }
        cout << *it << endl;
        curr = k;
    }
    else if(k<curr) {
        int j=curr-k;
        while(j) { it--; j--;}
        cout << *it << endl;
        curr = k;
    }
    else cout << *it << endl;
}

cin >> i;
}
