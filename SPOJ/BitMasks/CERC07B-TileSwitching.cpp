
using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

#define D(x) cout << #x " is " << x << endl

int rows, cols;
bool on[20][20];
bool backup[20][20];

#define inside(i, j) (0 <= (i) && (i) < rows && 0 <= (j) && (j) < cols)
#define toggle(x) x = !x

#define mp make_pair

void dance(int i, int j){
  int di[] = {+0, +0, +1, -1};
  int dj[] = {+1, -1, +0, +0};

  toggle(on[i][j]);
  for (int k=0; k<4; ++k){
    if (inside(i + di[k], j + dj[k])){
      toggle(on[i + di[k]][j + dj[k]]);
    }
  }

}

void print(){
  for (int i=0; i<rows; ++i){
    for (int j=0; j<cols; ++j){
      cout << on[i][j] << " ";
    }
    cout << "\n";
  }
}

int main(){

  while (cin >> rows >> cols && rows && cols){


    for (int i=0; i<rows; ++i){
      for (int j=0; j<cols; ++j){
        char c;
        cin >> c;
        on[i][j] = (c == '.');
      }
    }

    //print();
    memcpy(backup, on, sizeof on);

    bool solved = false;
    //int min=1000000;
    vector<pair<int, int> > ans(rows*cols+1);

    //Brute-force the cells to switch on the first row
    for (int set=0; set<(1<<cols); ++set){
      memcpy(on, backup, sizeof on);
      vector<pair<int, int> > path;
      for (int j=0; j<cols; ++j){
        if (set & (1 << j)){
          dance(0, j);
          path.push_back(mp(0, j));
        }
      }

      //Now deduce the following rows
      for (int i=1; i<rows; ++i){
        for (int j=0; j<cols; ++j){
          if (!on[i-1][j]){
            dance(i, j);
            path.push_back(mp(i, j));
          }
        }
      }

      bool ok = true;
      for (int i=0; i<rows; ++i){
        for (int j=0; j<cols; ++j){
          ok &= on[i][j];
        }
      }
      if (ok && path.size() < ans.size()){
        ans = path;
        solved = true;
      }
    }

    if (!solved){
      cout <<"Damaged billboard."<< endl;
    }else{
      cout <<"You have to tap "<<ans.size()<<" tiles."<< endl;
      //for (int i=0; i<ans.size(); ++i){
        //cout << ans[i].second + 1 << " " << ans[i].first + 1 << endl;
      //}
    }
    //cout << endl;
  }
  return 0;
}
