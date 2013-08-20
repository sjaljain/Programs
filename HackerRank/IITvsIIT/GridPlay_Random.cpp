#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int nextCopStatex[]={0,-1,0,0,0,1};
int nextCopStatey[]={0,0,1,0,-1,0};

int nextDRStatex[]={0,-1,-1,0,0,1,0,1,1,-1};
int nextDRStatey[]={0,-1,0,-1,0,0,1,-1,1,1};

int dist(int *dr,int *cop)
{
    return abs(cop[0]-dr[0])+abs(cop[1]-dr[1]);
}

bool StateValid(int *state)
{
    if(state[0]<0 || state[0]>19)return false;
    if(state[1]<0 || state[1]>19)return false;
    return true;
}

bool StateDRValid(int *state)
{
    if(state[0]<=2 || state[0]>=17)return false;
    if(state[1]<=2 || state[1]>=17)return false;
    return true;
}



/* Head ends here */
void calculate_move(char player, int *dr,int* cop1, int* cop2, int* cop3) {
//add logic here
//There are 5 states next to the current one for each cop
//Start with cop1

        //Cop 1 code starts here
        int maxState[3][2];

        int max_dist=dist(dr,cop1);
        int next_state[2],drNextState[2];
        for(int i=1;i<=5;i++)
        {
            next_state[0]=cop1[0]+nextCopStatex[i];
            next_state[1]=cop1[1]+nextCopStatey[i];
            if(!StateValid(next_state))continue;
            if(dist(dr,next_state)<=max_dist)
            {
                maxState[0][0]=next_state[0];
                maxState[0][1]=next_state[1];
                max_dist=dist(dr,next_state);
            }
        }
        vector<int> next;
        for(int i=1;i<=5;i++)
        {
            next_state[0]=cop1[0]+nextCopStatex[i];
            next_state[1]=cop1[1]+nextCopStatey[i];
            if(!StateValid(next_state))continue;
            if(dist(dr,next_state)==max_dist)
            {
               next.push_back(i);
            }
        }
        int a=rand()%(next.size());
        //cout<<a<<endl;
        next_state[0]=cop1[0]+nextCopStatex[next[a]];
        next_state[1]=cop1[1]+nextCopStatey[next[a]];
        maxState[0][0]=next_state[0];
        maxState[0][1]=next_state[1];
        next.clear();

        //Cop 2 code starts here

        max_dist=dist(dr,cop2);

        for(int i=1;i<=5;i++)
        {
            next_state[0]=cop2[0]+nextCopStatex[i];
            next_state[1]=cop2[1]+nextCopStatey[i];
            if(!StateValid(next_state))continue;
            if(dist(dr,next_state)<=max_dist)
            {
                maxState[1][0]=next_state[0];
                maxState[1][1]=next_state[1];
                max_dist=dist(dr,next_state);
            }
        }

        for(int i=1;i<=5;i++)
        {
            next_state[0]=cop2[0]+nextCopStatex[i];
            next_state[1]=cop2[1]+nextCopStatey[i];
            if(!StateValid(next_state))continue;
            if(dist(dr,next_state)==max_dist)
            {
               next.push_back(i);
            }
        }
        a=rand()%(next.size());
        //cout<<a<<endl;
        next_state[0]=cop2[0]+nextCopStatex[next[a]];
        next_state[1]=cop2[1]+nextCopStatey[next[a]];
        maxState[1][0]=next_state[0];
        maxState[1][1]=next_state[1];
        next.clear();


        //Cop 3 code starts here

        max_dist=dist(dr,cop3);

        for(int i=1;i<=5;i++)
        {
            next_state[0]=cop3[0]+nextCopStatex[i];
            next_state[1]=cop3[1]+nextCopStatey[i];
            if(!StateValid(next_state))continue;
            if(dist(dr,next_state)<=max_dist)
            {
                maxState[2][0]=next_state[0];
                maxState[2][1]=next_state[1];
                max_dist=dist(dr,next_state);
            }
        }

        for(int i=1;i<=5;i++)
        {
            next_state[0]=cop3[0]+nextCopStatex[i];
            next_state[1]=cop3[1]+nextCopStatey[i];
            if(!StateValid(next_state))continue;
            if(dist(dr,next_state)==max_dist)
            {
               next.push_back(i);
            }
        }
        a=rand()%(next.size());
        //cout<<a<<endl;
        //a=next.size()-a-1;
        next_state[0]=cop3[0]+nextCopStatex[next[a]];
        next_state[1]=cop3[1]+nextCopStatey[next[a]];
        maxState[2][0]=next_state[0];
        maxState[2][1]=next_state[1];
        next.clear();


        //Doctor code here

        int min_dist=0;

        for(int i=1;i<=9;i++)
        {
            //if(cop1[0]<=5 && cop2[0]<=5 && cop3[0]<=5 && i!=1)continue;
            //if(cp1[0]<=5 && cp2[0]<=5 && cp3[0]<=5 && dist(dr,cp1)>=15 && dist(dr,cp1)>=15 && dist(dr,cp1)>=15 && i!=1)continue;
            next_state[0]=dr[0]+nextDRStatex[i];
            next_state[1]=dr[1]+nextDRStatey[i];
            if(StateDRValid(dr) && !StateDRValid(next_state))continue;
            if(!StateValid(next_state))continue;
            max_dist=100;
            for(int i=0;i<=2;i++)
            {
                if(dist(next_state,maxState[i])<=max_dist)
                max_dist=dist(next_state,maxState[i]);
            }
            if(max_dist>=min_dist)
            {
                drNextState[0]=next_state[0];
                drNextState[1]=next_state[1];
                min_dist=max_dist;
            }
        }

        if(player=='C')
        {
            for(int i=0;i<3;i++)
            {
                printf("%d %d ",maxState[i][0],maxState[i][1]);
            }
        }
        else
        printf("%d %d",drNextState[0],drNextState[1]);



}

/* Tail starts here */
int main() {
    srand ( time(NULL) );
    int dr[2],cop1[2],cop2[2],cop3[2];
    char player;
    cin>>player;
    cin>>dr[0]>>dr[1];
    cin>>cop1[0]>>cop1[1]>>cop2[0]>>cop2[1]>>cop3[0]>>cop3[1];
    /*
    for(int i=1;i<=10;i++)
    {
        calculate_move('C',dr,cop1,cop2,cop3);
        cout<<endl;
        calculate_move('R',dr,cop1,cop2,cop3);
    }
    */
    calculate_move(player,dr,cop1,cop2,cop3);
}
