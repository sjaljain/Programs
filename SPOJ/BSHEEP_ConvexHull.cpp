#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct Point
{
    int X, Y;
    int index;
    Point ( ) { };
    Point ( int _X, int _Y,int _index )
    {
        X = _X;
        Y = _Y;
        index=_index;
    }
    inline bool operator < ( const Point &NewPoint ) const
    {
        return ( ( Y < NewPoint.Y ) || ( ( Y == NewPoint.Y ) && ( X < NewPoint.X ) ) );
    }
};

inline bool LeftTurn ( const Point &P1, const Point &P2, const Point &P3 )
{
    return ( ( ( P2.X - P1.X ) * ( P3.Y - P2.Y ) - ( P3.X - P2.X ) * ( P2.Y - P1.Y ) ) <= 0 );
}

inline void MakeHull ( const int &N, Point Points [ ], int &HullSize, Point Hull [ ] )
{
    sort ( Points, Points + N );
    int idx = 0;
    Hull[idx++] = Points[0];
    Hull[idx++] = Points[1];
    for ( int i = 2; i < N; i++ )
    {
        while ( ( idx >= 2 ) && ( LeftTurn ( Hull[idx - 2], Hull[idx - 1], Points[i] ) ) ) idx--;
        Hull[idx++] = Points[i];
    }
    int idy = idx + 1;
    for ( int i = N - 2; i >= 0; i-- )
    {
        while ( ( idx >= idy ) && ( LeftTurn ( Hull[idx - 2], Hull[idx - 1], Points[i] ) ) ) idx--;
        Hull[idx++] = Points[i];
    }
    HullSize = idx;
}

inline double FindDist ( const Point &P1, const Point &P2 )
{
    return sqrt ( ( P2.X - P1.X ) * ( P2.X - P1.X ) + ( P2.Y - P1.Y ) * ( P2.Y - P1.Y ) );
}

int main ( void )
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf ( "%d", &N );
        Point Points[N], Hull[2 * N];
        int Cnt = 0;
        for ( int i = 0; i < N; i++ )
        {
            int X, Y;
            scanf ( "%d %d", &X, &Y );
            Points[Cnt++] = Point ( X, Y ,i+1);
        }
        if(N==1){printf("0.00\n1\n\n");continue;}
        int HullSize = 0;
        MakeHull ( Cnt, Points, HullSize, Hull );
        double Dist = 0;
        for ( int i = 0; i < HullSize; i++ ) Dist += FindDist ( Hull[i], Hull[ ( i + 1 ) % HullSize ] );
        printf ( "%.2lf\n", Dist );
        for(int i=0;i<HullSize-1;i++)printf("%d ",Hull[i].index);
        printf("\n\n");
    }
    return 0;
}
