#include <iostream>
#define MAX 1000
using namespace std;
void printArray(int a[MAX],int length)
{
    for(int q = 0; q<length; q++)
    {
        cout<<a[q]<<" ";
    }
    cout<<"\n";
}
int stringLength(char p[MAX])
{
    int length = 0;
    while(p[length]!='\0')
    {
        length++;
    }
    return length;
}
void preKMP(int pi[MAX],char p[MAX])
{
    int m = stringLength(p);
    pi[0] = 0;
    int k=0,i=1;
    while(i<m)
    {
        if(p[i]==p[k])
        {
            k++;
            pi[i] = k;
            i++;
        }
        else
        {
            if(k!=0)
            {
                k = pi[k-1];
            }
            else
            {
                pi[i] = 0;
                i++;
            }
        }
    }
    printArray(pi,m);
}
void KMP(char pattern[MAX], char target[MAX])
{
    int pi[MAX];
    preKMP(pi,pattern);
    int n = stringLength(target);
    int m = stringLength(pattern);
    int i=0,k=0;
    while(i<n)
    {
        if(target[i]==pattern[k])
        {
            i++;
            k++;
        }
        else
        {
            if(k!=0)
            {
                k = pi[k-1];
            }
            else
            {
                i++;
            }
        }
        if(k==m)
        {
            cout<<"Found at "<<m<<endl;
            k = pi[k-1];
        }
    }
}
int main()
{
    char p[MAX],s[MAX];
    cin>>p;
    cin>>s;
    KMP(p,s);
    return 0;
}
