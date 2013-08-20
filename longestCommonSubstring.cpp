#include <iostream>
#include <cstring>
using namespace std;
int LongestCommonSubString(string first,string second)
{
    int n1 = first.length(), n2 = second.length(),max=0;
    if(n1==0||n2==0) return 0;
    if(n1<n2) swap(first,second);
    int *current = new int[n2];
    int *previous = new int[n2];
    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n2; j++)
        {
            if(first[i]!=second[j])
                current[j] = 0;
            else if(i==0||j==0)
                current[j] = 1;
            else
                current[j] = previous[j-1] + 1;

            if(max<current[j])
                max = current[j];
        }
        swap(previous,current);
    }
    delete [] previous;
    delete [] current;
    return max;
}
int main()
{
    cout<<LongestCommonSubString("handler","sandollar");
    return 0;
}

