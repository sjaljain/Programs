/* Sajal Jain , 09EC1017
 * Algorithm Laboratory Autumn 2012
 * Greedy Graph (NP complete)
 */

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Part 1 are given to the desert-dwelling families, and the houses in Part 2 to the forest-dwelling families
struct location
{
  double x;
  double y;
  int tribe_id;
  location(double _x,double _y,int _tribe_id){x=_x;y=_y;tribe_id=_tribe_id;}
};

bool distance(location A,location B,double delta)
{
    double dist;
    dist=sqrt(pow((A.x-B.x),2));
    dist+=sqrt(pow((A.y-B.y),2));
    if(dist<=delta)return true;
    else return false;
}

void SOLVE(int n1,int n2,double delta,vector <location> L);

int main()
{
    int n1,n2;
    double delta;
    printf("n1 = ");scanf("%d",&n1);
    printf("n2 = ");scanf("%d",&n2);
    printf("delta = ");scanf("%lf",&delta);
    printf("Houses are located at:\n");
    srand ( time(NULL) );

    vector<location> L1,L2;
    L1.push_back(location(-1,-1,0));//Inserting dummy variable
    L2.push_back(location(-1,-1,0));//Inserting dummy variable
    //Inserting location and tribe_ids
    int tribe_id=1;
    for(int i=1;i<=n1+n2;i++)
    {
            double a=(double)rand() / (double)RAND_MAX;
            double b=(double)rand() / (double)RAND_MAX;
            if(i<=n1)
                L1.push_back(location(a,b,1));
            else
                L1.push_back(location(a,b,2));

            if(i<=n2)
                L2.push_back(location(a,b,2));
            else
                L2.push_back(location(a,b,1));

    }
    //Printing house locations
    for(int i=1;i<=n1+n2;i++)
            printf("(%lf,%lf) ",L1[i].x,L1[i].y);
    printf("\n");

    //We can create different L and push them into SOLVE function
    //and test the randomness of the greedy algorithm

    SOLVE(n1,n2,delta,L1);
    printf("\n\n\n--------------------------\nUsing Different Original Partition\n--------------------------\n\n\n");
    SOLVE(n1,n2,delta,L2);


    return 0;
}

void SOLVE(int n1,int n2,double delta,vector <location> L)
{
    vector<int> swapped(n1+n2+1,0);
    vector<int> G[n1+n2+1];
    //Creating undirected graph from the given node ids in O(n^2)
    //Adjacency list with node ids
    for(int i=1;i<=n1+n2;i++)
        for(int j=i+1;j<=n1+n2;j++)
        {
           if(distance(L[i],L[j],delta))
           {
               G[i].push_back(j);
               G[j].push_back(i);
           }
        }


    int tribe1_loc_id=1,tribe2_loc_id=1;
    int tot_gain=1;

    while(tot_gain>0)
    {
        //Finding number of cross edges
        int num_cross_edges=0;
        for(int i=1;i<=n1+n2;i++)
        {
            for(int j=0;j<G[i].size();j++)
            {
                if(L[i].tribe_id!=L[G[i][j]].tribe_id)
                num_cross_edges++;
            }
        }
        printf("\tNumber of cross edges = %d\n",num_cross_edges/2);

        int max1_gain=-99999,max2_gain=-99999;

        //Finding 'r' - gain from shifting 1 to 2
        tot_gain=0;
        for(int i=1;i<=n1+n2;i++)
        {
            int temp_gain=0;
            if(L[i].tribe_id==2 || swapped[i])continue;
            for(int j=0;j<G[i].size();j++)
            {
                if(L[G[i][j]].tribe_id==1)temp_gain--;
                else temp_gain++;
            }

            if(temp_gain>max1_gain)
            {
                tribe1_loc_id=i;
                max1_gain=temp_gain;
            }
        }
        //cout<<max1_gain<<" "<<tribe1_loc_id<<endl;

        //Finding 's' - gain from shifting 2 to 1
        for(int i=1;i<=n1+n2;i++)
        {
            int temp_gain=0;
            if(L[i].tribe_id==1 || i==tribe1_loc_id || swapped[i])continue;
            for(int j=0;j<G[i].size();j++)
            {
                if(L[G[i][j]].tribe_id==2)temp_gain--;
                else temp_gain++;
            }

            if(temp_gain>max2_gain)
            {
                tribe2_loc_id=i;
                max2_gain=temp_gain;
            }
        }
        //cout<<max2_gain<<" "<<tribe2_loc_id<<endl;
        tot_gain=max1_gain+max2_gain;
        if(tot_gain<=0)break;
        L[tribe1_loc_id].tribe_id=2;
        L[tribe2_loc_id].tribe_id=1;
        swapped[tribe1_loc_id]=1;
        swapped[tribe2_loc_id]=1;


        printf("\t   +++ Switching node %d to Part 2: Gain = %d\n",tribe1_loc_id,max1_gain);
        printf("\t   +++ Switching node %d to Part 1: Gain = %d\n",tribe2_loc_id,max2_gain);
    }

    printf("\t   +++ No further refinement possible\n");
    printf("Tribe 1 families get the houses:\n");
    for(int i=1;i<=n1+n2;i++)
         if(L[i].tribe_id==1)
            printf("\t%d",i);
    printf("\nTotal number of houses = %d",n1);
    printf("\nTribe 2 families get the houses:\n");
     for(int i=1;i<=n1+n2;i++)
         if(L[i].tribe_id==2)
            printf("\t%d",i);
    printf("\nTotal number of houses = %d",n2);
}

