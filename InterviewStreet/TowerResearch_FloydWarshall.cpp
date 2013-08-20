#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cassert>
#include <climits>
#include <functional>
#include <bitset>

#define dim 2
#define FOR(k,a,b) for(typeof(a) k=(a); k < (b); ++k)
#define inf 1000000000

typedef long long LL;
#define pp pair<int,int>
using namespace std;
class Prioritize
{
public:
    int operator() ( const pair<int, int>& p1, const pair<int, int>& p2 )
    {
        return p1.second < p2.second;
    }
};

#define VAR(a,b) __typeof(b) a=(b)
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)

#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> vi;
typedef vector<vi> vvi;


class INPUT {
  static const int BUFSIZE = 1<<16;
  static char buffer[];
  char *bufpos;
  char *bufend;
  void grabBuffer();
 public:
  INPUT() { grabBuffer(); }
  bool eof() { return bufend==buffer; }
  char nextChar() { return *bufpos; }
  inline char readChar();
  inline void skipWS();
  unsigned readUnsigned();
  unsigned long long readUnsignedLL();
  int readInt();
};

char INPUT::buffer[INPUT::BUFSIZE];

void INPUT::grabBuffer() {
  bufpos = buffer;
  bufend = buffer + fread( buffer, 1,BUFSIZE,stdin);
}

char INPUT::readChar() {
  char res = *bufpos++;
  if(bufpos==bufend) grabBuffer();
  return res;
}

inline bool myisspace(char c) { return c<=' '; }

void INPUT::skipWS() {
  while(!eof() && myisspace(nextChar())) readChar();
}

unsigned INPUT::readUnsigned() {
  skipWS();
  unsigned res = 0;
  while(!eof() && isdigit(nextChar())) {
    res = 10u * res + (readChar()-'0');
  }
  return res;
}

unsigned long long INPUT::readUnsignedLL() {
  skipWS();
  unsigned long long res = 0;
  while(!eof() && isdigit(nextChar())) {
    res = 10u * res + (readChar()-'0');
  }
  return res;
}

int INPUT::readInt() {
  skipWS();
  bool neg = false;
  if(!eof() && nextChar()=='-') { neg=true; readChar(); }
  int res = static_cast<int>(readUnsigned());
  if(neg) res = -res;
  return res;
}

int N;

void floydWarshall (vector<vector<long long int> > &graph)
{
    vector<vector<long long int> > dist;
    vector<long long int> v(N,inf);
    //vector<int> v1(N,inf);
    for(int i=0;i<N;i++)
    {
        dist.push_back(v);

    }
    int i, j, k;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            dist[i][j] = graph[i][j];
            if(i==j)dist[i][j]=0;
        }


    for (k = 0; k < N; k++)
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if(dist[i][k]==inf || dist[k][j]==inf)continue;
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];

                }

            }
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        graph[i][j]=dist[i][j];
    }


}

INPUT input;

int main()
{
    int T;
    //scanf("%d",&T);
    T=input.readInt();
    while(T--)
    {
        int M;
        //scanf("%d %d",&N,&M);
        N=input.readInt();M=input.readInt();
        priority_queue<pp, vector<pp > , Prioritize > Q;
        vector<vector<long long int> > cost;
        vector<long long int> v(N,inf);
        for(int i=0;i<N;i++)
            cost.push_back(v);
        vector< pp > G[N];


        for(int i=0;i<M;i++)
        {
            int u,v,w;
            u=input.readInt();v=input.readInt();w=input.readInt();
            if(cost[u][v]<w)continue;
            cost[u][v]=w;
             G[u].push_back(pp(v,w));
        }
        for(int i=0;i<N;i++)cost[i][i]=0;

        int Q1;
        //scanf("%d",&Q);
        Q1=input.readInt();

        if(Q1<1000)
        {
            for(int i=0;i<Q1;i++)
            {
            int u,v1;
            //scanf("%d %d",&u,&v);
            u=input.readInt();v1=input.readInt();
            int d[N];
            int s=u;
            for(int i=0;i<N;i++)
            {
                d[i] = inf;
            }
            d[u] = 0;
            Q.push(pp(s,d[s]));
            while(!Q.empty())
            {
                u = Q.top().first;
                Q.pop();
                int size = G[u].size();
                for(int i = 0 ; i < size ; i++)
                {
                    int v = G[u][i].first;
                    int w = G[u][i].second;
                    //cout<<u<<" "<<v<<" "<<w<<endl;
                    if(d[v] > d[u] + w)
                    {
                        d[v] = d[u] + w;
                        Q.push(pp(v,d[v]));
                    }
                }
            }
            printf("%d\n",d[v1]);
            }
            //follow Djikstra

            return 0;
        }
        floydWarshall(cost);

        for(int i=0;i<Q1;i++)
        {
            int u,v;
            //scanf("%d %d",&u,&v);
            u=input.readInt();;v=input.readInt();
            printf("%lld\n",cost[u][v]);
        }
    }

    return 0;
}
