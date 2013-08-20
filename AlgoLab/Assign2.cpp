#include<iostream>
#include<vector>
#include <stdlib.h>
#include <time.h>

#define pp pair<double,double> 

struct Index { 
    double t;
    int status; 
    int interval_id;
    Index(double _t, int _status,int _interval_id) { t = _t; status = _status; interval_id=_interval_id;}
};

using namespace std;

bool cmp ( const Index& a, const Index& b){
     if(a.t==b.t) return (a.status<b.status);
     else return (a.t<b.t);}
     
void generate(double &st_index,double &end_index)
{
     double a=(double)rand() / (double)RAND_MAX;
     double b=(double)rand() / (double)RAND_MAX;
     while(a==b)b=(double)rand() / (double)RAND_MAX;
     
     if(a<b){st_index=a;end_index=b;}
     else {st_index=b;end_index=a;}
     return;
     }
     
int main()
{
    int N;cout<<"How many intervals ? ";cin>>N;
    vector< Index > v;
    vector< pp > interval;
    srand ( time(NULL) );
    double st_index,end_index;
    for(int i=0;i<N;i++)
    {
            generate(st_index,end_index);
            cout<<"Interval       "<<i<<" = ["<<st_index<<","<<end_index<<"]"<<endl;
            interval.push_back(pp(st_index,end_index));
            v.push_back(Index(st_index,1,i));
            v.push_back(Index(end_index,2,i));
           
            }
     sort(v.begin(),v.end(),cmp);        
     //for(int i=0;i<2*N;i++)
     //       cout<<v[i].t<<" "<<v[i].status<<endl;
                    
    int count=0,max=0,id=0;
    //Total number of maximum overlaps
    for(int i=0;i<2*N;i++)
    {
            
            if(v[i].status==1)count++;
            else count--;
            
            if(count>max){max=count;id=i;}
            }
            
            
    //Finding the range of maximum overlap
    double right_lim=v[id+1].t;
    double left_lim=v[id].t;
    cout<<"Leftmost maximum overlap is ["<<left_lim<<","<<right_lim<<"]"<<endl;
    cout<<"Number of overlapping intervals is "<<max<<endl;
    //Finding the intervals of overlap
    cout<<"Indices of overlapping intervals are:"<<endl;
    for(int i=0;i<N;i++)
    {
            if(interval[i].first <= left_lim && interval[i].second >=right_lim)
                   cout<<"\t"<<i;
            }
            cout<<endl;
     cout<<"Total number of intervals = "<<max<<endl;      
       
     return 0;   
}
