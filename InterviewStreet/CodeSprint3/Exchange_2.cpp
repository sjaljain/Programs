#include<iostream>
#include<string>
using namespace std;

int main()
{
int K;
cin>>K;
char *P = new char [K]();
for(int i=0;i<K;i++)
{
cin>>P[i];
}
string *matrix = new string [K] ();
for(int i=0;i<K;i++)
{
cin>>matrix[i];
}
for(int i=0;i<K;i++)
{
for(int j=i;j<K;j++)
{
if(P[i]>P[j] && i<j && matrix[i][j]=='Y')
{
char temp;
temp = P[i];
P[i]=P[j];
P[j]=temp;
}
if(P[i]<P[j] && i>j && matrix[i][j]=='Y')
{
char temp;
temp = P[i];
P[i]=P[j];
P[j]=temp;
}

}

}
for(int i=0;i<K;i++)
{
cout<<P[i];
if(i<(K-1))
cout<<" ";
}
delete [] P;
delete [] matrix;
return 0;
}
