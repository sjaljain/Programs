#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
typedef mpz_class _int;
using namespace std;
int main()
	{
		_int sum=0,k;
		for(_int i=10;i<150000000;i+=10)
		{
			k=( i*i+1 );
			if(mpz_probab_prime_p(k.get_mpz_t(),5) )
			 {
				_int next , curr = k;
				mpz_nextprime(next.get_mpz_t(),curr.get_mpz_t());
				if( next == ( i*i + 3 ) )
				 {
					curr= next ;
					mpz_nextprime(next.get_mpz_t() , curr.get_mpz_t());
					if( next == ( i*i + 7 ) )
					 {
						curr = next;
						mpz_nextprime(next.get_mpz_t() , curr.get_mpz_t());
						if ( next == ( i*i + 9 ) )
						 {
							curr = next;
							mpz_nextprime(next.get_mpz_t() , curr.get_mpz_t());
							if(next == ( i*i + 13 ) )
							 {
								curr = next;
								mpz_nextprime(next.get_mpz_t() , curr.get_mpz_t());
								if( next == ( i*i + 27 )) sum += i;
							 }
						 }
					 }
				}
			}
		}
		cout<<sum<<endl;

	}
