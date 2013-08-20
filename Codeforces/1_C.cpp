#include<iostream>
#include<math.h>

#define  pp pair <double,double>
using namespace std;

int main()
{
    pp a,b,c;
    double dist;
    cin>>a.first>>a.second;
    cin>>b.first>>b.second;
    cin>>c.first>>c.second;
    
    dist=sqrt((b.second-a.second)*(b.second-a.second) + (b.first-a.first)*(b.first-a.first));
    double s1,s2;
    s1=(b.second-a.second)/(b.first-a.first);
    s1=(b.second-c.second)/(b.first-c.first);
 return 0;   
}
