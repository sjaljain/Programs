#include <iostream>
#include <vector>
#include <cassert>
#include<cstdio>

using namespace std;

static void investigate()
{
        // const unsigned long long N = 1000000ULL * 1000000ULL * 1000000ULL - 1;
        const int max_size = 10500000; // found the number by manual trial & error

        // Generate the Golomb sequence of the first few terms.
        std::vector<int> G;
        G.push_back(0);
        G.push_back(1);
        G.push_back(2);
        G.push_back(2);

        int k = 3;
        while (G.size() < 10500000)
        {
                for (int i = G[k]; i > 0; i--)
                        G.push_back(k);
                k++;
        }

#if 0
        long long cumsum = 0;
        long long cumprod = 0;
        std::cout << "r   M(r)    L(r)" << std::endl;
        for (int i = 1; i < 100; i++)
        {
                cumsum += G[i];
                cumprod += (long long)i * G[i];
                // std::cout << i << "  " << G[i] << "  " << cumsum << "  " << cumprod << std::endl;
                std::cout << i << "  " << cumsum << "  " << cumprod << std::endl;
        }
#else
        long long cumsum = 0;
        long long cumprod = 0;
        for (int i = 1; i < (int)G.size(); i++)
        {
                cumsum += G[i];
                cumprod += (long long)i * G[i];
                if (i % 1000 == 0)
                        //std::cout << i << "  " << G[i] << "  " << cumsum << "  " << (log((double)cumprod) / log(10.0)) << std::endl;
                        //std::cout << i << "  " << G[i] << "  " << cumsum << "  " << cumprod << std::endl;
                        std::cout << i << "  " << cumsum << "  " << cumprod << std::endl;
                if (i == 1000000)
                        break;
        }
#endif
}

// TBD: this class is not robust and need to improve.
class golomb_small
{
        std::vector<int> F;
        int slow_k;

public:
        golomb_small()
        {
                F.push_back(0);
                F.push_back(1);
                F.push_back(3);
                slow_k = 1;
        }

        // Computes G(n). Each call to () must input increasing n.
        int operator() (int n)
        {
                // Find k such that F(k-1) < n <= F(k)
                int k = (int)F.size() - 1;
                while (n > F[k])
                {
                        k++;
                        // Append F[k] = F[k-1] + G[k]
                        while (k > F[slow_k])
                                slow_k++;
                        F.push_back(F.back() + slow_k);
                }

                assert(n > F[k-1]);
                return k;
        }
};

class golomb_large
{
        golomb_small G;
        int k;
        long long F_k, F_k_1, FF_k, FF_k_1;

public:
        golomb_large() : k(1), F_k(1), F_k_1(0), FF_k(1), FF_k_1(0) { }

        long long operator() (long long n)
        {
                // Find k such that F(F(k-1)) < n <= F(F(k)).
                while (n > FF_k)
                {
                        k++;
                        long long G_k = G(k);
                        F_k_1 = F_k;
                        F_k = F_k_1 + G_k;
                        FF_k_1 = FF_k;
                        FF_k = FF_k_1 + k*G_k;
                }
                assert(n > FF_k_1);

                // Back out G_n.
                long long G_n = F_k - (FF_k-n)/k;
                return G_n;
        }
};

void solve(int max_n, vector<long long > &S)
{
        golomb_large G;

        long long sum = 0;
        for (long long n = 1; n <= max_n; n++)
        {
                S[n]= S[n-1]+G(n*n*n);
        }
        //return sum;
}

int main()
{
        //investigate();

        vector<long long >S(1000001,0);
        solve(1000000,S);
        int T;
        scanf("%d",&T);
        while(T--)
        {
            int N;
            scanf("%d",&N);
            printf("%lld\n",S[N]);
        }

        return 0;
}
