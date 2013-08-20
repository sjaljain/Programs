
// http://uva.onlinejudge.org/external/110/11096.html
/*
Notes : 
1. Classic convex hull problem 
2. if there are 2 nails, return distance between them * 2
3. if perimeter of convex hull is less than initial length of ribbon, return initial length
4. use data type long long for, 
initial length of ribbon
location of nail
5. it shifts the leftmost+bottomost point to the origin
6. hull contains the final hull in order
*/
// @BEGIN_OF_SOURCE_CODE

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define N 1000000
using namespace std;

struct Point {
    long long x;
    long long y;
    double angle;
} p [100 + 5], hull [100 + 5];

double angle (long long x, long long y)
{
    double theta = atan2 (fabs (y), fabs (x));

    if ( x >= 0 ) return theta;
    return pi - theta;
}

bool cmp (Point a, Point b)
{
    if (fabs (a.angle - b.angle) < 1e-6 )
        return (a.x * a.x + a.y * a.y) < (b.x * b.x + b.y * b.y);
    return a.angle < b.angle;
}

bool isInRight (Point a, Point b, Point c)
{
    if ( c.x * (a.y - b.y) + c.y * (b.x - a.x) + (a.x * b.y - a.y * b.x) < 0 )
        return true;
    return false;
}

double square (double a)
{
    return a * a;
}

int main ()
{
    int testCase;
    scanf ("%d", &testCase);

    while ( testCase-- ) {
        long long initialLength=0;
        int totalPoints;

        cin >>totalPoints;

        for ( int i = 0; i < totalPoints; i++ )
            cin >> p [i].x >> p [i].y;

        // special case if only 1 totalPoints
        if ( totalPoints == 1 ) {
            printf ("%.5lf\n", (double) initialLength);
            continue;
        }

        int id = 0;

        for ( int i = 1; i < totalPoints; i++ )
            if ( p [i].y < p [id].y ) id = i;

        swap (p [id], p [0]);

        // scaling down respective to id
        for ( int i = totalPoints - 1; i >= 0; i-- ) {
            p [i].x -= p [0].x;
            p [i].y -= p [0].y;
        }

        // measure angle according to id
        for ( int i = 1; i < totalPoints; i++ )
            p [i].angle = angle (p [i].x, p [i].y);

        sort (p + 1, p + totalPoints, cmp);

        hull [0] = p [0];
        hull [1] = p [1];
        int top = 1;

        for ( int i = 2; i < totalPoints; i++ ) {
            while (isInRight (hull [top - 1], hull [top], p [i]))
                top--;
            hull [++top] = p [i];
        }

        double finalLength = 0;

        // perimeter of convex hull
        for ( int i = 1; i <= top; i++ )
            finalLength += sqrt (square (hull [i - 1].x - hull [i].x) + square (hull [i - 1].y - hull [i].y));

        finalLength += sqrt (square (hull [top].x - hull [0].x) + square (hull [top].y - hull [0].y));

        if ( finalLength < initialLength ) finalLength = initialLength;

        printf ("%.2lf\n", finalLength);
        
        for(int i=0;i<totalPoints;i++)
			cout<<hull[i].x<<" "<<hull[i].y<<"   ";
    }

	return 0;
}

// @END_OF_SOURCE_CODE
