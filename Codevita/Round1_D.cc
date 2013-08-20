#include<stdio.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;


int check_if_anagram(string t1, string t2)
{
	if(t1.length() != t2.length())
		return 0;
	int f = 0,f1;
	for(int i=0;i<t1.length();i++)
	{
		f1 = 0;
		for(int j=0;j<t2.length();j++)
		{
			if(t2[j] == t1[i])
			{
				f1++;
			}
		}
		if(f1==0)
		{
			return 0;
		}
		if(f1>1)
		{
			int c = 0;
			for(int k=0;k<t1.length();k++)
			{
				if(t1[k] == t1[i])
				c++;
			}
			if( c != f1)
			return 0;
		}
	}
	return 1;
}	
				


int main()
{
	vector <string> data;
	vector<string>::iterator it1,it2,it3;
	vector <string> group;
	string text,temp;
	vector <int> num;
	getline(cin,text);

	temp.clear();
	for(int i=0;i<text.length();i++)
	{
		if(text[i] == ' ' || text[i] == ',' || text[i] == '!' || text[i] == '.'  || text[i] == '\'' || text[i] == '\"' || text[i+1] == 0)		{
			if(text[i+1] == 0)
				temp.push_back(text[i]);
			data.push_back(temp);	
			//cout<<temp<<endl;
			temp.clear();
		}
		else
		{	
			if(text[i] >= 'A' && text[i] <='Z')
				text[i]+=32;
			temp.push_back(text[i]);
		}
	}
	for(it1 = data.begin(); it1 != data.end() ; it1++)
	{

		group.clear();
		group.push_back(*it1);
		for(it2 = it1+1; it2 != data.end() ; it2++)
		{
			if(check_if_anagram(*it1,*it2) == 1 && (*it1).compare(*it2) != 0)
			{
				//cout<<"anagram"<<" "<<*it1<<endl;
				int n = it2 - data.begin();
				int n1 = it1 - data.begin();
				vector <int>::iterator itt;
				int f = 0;
				for(itt = num.begin(); itt != num.end(); itt++)
				{	
					if( *itt == n || *itt == n1)
					{
						f = 1;
						break;
					}
				}
				int f1 = 0;
				for(it3 = group.begin(); it3 != group.end(); it3++)
				{	
					if( (*it2).compare(*it3) == 0)
					{
						f1 = 1;
						break;
					}
				}

				if(f == 0 && f1 == 0)
				 {
					group.push_back(*it2);
					num.push_back(n);
				}
				//data.erase(it2);
			}
			//else
			//cout<<*it1<<" "<<*it2<<" "<<"not anagram"<<endl;	
		}
		if(group.size() > 1)
		{
			for(it3 = group.begin(); it3!=group.end() ; it3++)
				cout<<*it3<<" ";
			cout<<endl;
		}
		//data.erase(it1);
	}





}
					



