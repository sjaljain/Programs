#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

struct power
{
    int x,y;
    power(int _x,int _y){x=_x;y=_y;}
};

bool cmp(const power &a,const power &b)
{
    return a.x<b.x;
}

int main()
{
    int s,n;
    scanf("%d%d",&s,&n);
    vector<power> v;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v.push_back(power(a,b));
    }
    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<n;i++)
    {
        if(s<v[i].x){printf("NO");return 0;}
        else
        {
            s+=v[i].y;
        }
    }
    printf("YES");

return 0;
}
