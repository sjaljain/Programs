#include<iostream>

using namespace std;

int main()
{
int T;cin>>T;
while(T--)
{ 
int value;
cin>>value;          
int result = 1;
while (result <= value) result <<= 1;   
result/=2;
value=value-result;
cout<<2*value+1<<endl;

}
return 0;
}
