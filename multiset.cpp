// multiset::begin/end
#include <iostream>
#include <set>
using namespace std;

int main ()
{
  int myints[] = {42,71,71,71,12};
  multiset<int> mymultiset (myints,myints+5);

  multiset<int>::iterator it;

  cout << "mymultiset contains:";
  for ( it=mymultiset.begin() ; it != mymultiset.end(); it++ )
    cout << " " << *it;

  cout << endl;

  return 0;
}
