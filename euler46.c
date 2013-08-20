/*
It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 212
15 = 7 + 222
21 = 3 + 232
25 = 7 + 232
27 = 19 + 222
33 = 31 + 212

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10000

static int is_square(unsigned n);
static char *prime_sieve(unsigned n);

int main(void)
{
  char *sieve = prime_sieve(N);
  unsigned *primes = malloc(sizeof(unsigned) * N);
  unsigned i, j = 0;

  for (i = 0; i < N; i++) {
    if (!sieve[i]) {
      primes[j++] = i;
    }
  }
  primes[j] = 0;

  for (i = 3; i < N; i += 2) {
    if (!sieve[i]) {
      /* skip if i is prime */
      continue;
    }
    for (j = 0; primes[j]; j++) {
      unsigned s;

      if (primes[j] > i) {
        printf("%u\n", i);
        goto FINISH;
      }

      s = (i - primes[j])/2;
      if (is_square(s)) {
        break;
      }
    }
  }
FINISH:
  free(sieve);
  free(primes);

  return 0;
}

char *prime_sieve(unsigned n)
{
  char *sieve = calloc(n, sizeof *sieve);
  unsigned i;
  sieve[0] = sieve[1] = 1;
  for (i = 2; i < n; i++) {
    if (!sieve[i]) {
      unsigned j;
      for (j = i*2; j < n; j += i) {
        sieve[j] = 1;
      }
    }
  }
  return sieve;
}

int is_square(unsigned n)
{
  unsigned sq = sqrt(n);
  return sq*sq == n;
}
