#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

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
    if(state[0]>=19 && state[1]==19)return false;
    if(state[1]<=2 || state[1]>=17)return false;
    return true;
}



/* Head ends here */
void calculate_move(char player, int *dr,int* cop1, int* cop2, int* cop3) {

    int maxState[3][2];
    maxState[0][0]=cop1[0];
    maxState[0][1]=cop1[1];
    maxState[1][0]=cop2[0];
    maxState[1][1]=cop2[1];
    maxState[2][0]=cop3[0];
    maxState[2][1]=cop3[1];
    int next_state[2],drNextState[2];
    int max_dist;
    int done=1;
    //If all are in the same position check
    if(maxState[0][0]==maxState[1][0] && maxState[0][0]==maxState[2][0]&& maxState[0][1]==maxState[1][1] && maxState[1][1]==maxState[2][1])
    {
        done=0;
        int x=maxState[0][0];
        int y=maxState[0][1];
        //cout<<"here"<<x<<" "<<y<<endl;
        if(dr[0]==x+1 && dr[1]==y+1){       maxState[0][0]=x;maxState[0][1]=y;  maxState[1][0]=x;           maxState[1][1]=min(19,y+1); maxState[2][0]=min(19,x+1);     maxState[2][1]=y;}
        else if(dr[0]==x && dr[1]==y+1){    maxState[0][0]=x;maxState[0][1]=y;  maxState[1][0]=max(0,x-1);  maxState[1][1]=y;           maxState[2][0]=min(19,x+1);     maxState[2][1]=y;}
        else if(dr[0]==x-1 && dr[1]==y+1){  maxState[0][0]=x;maxState[0][1]=y;  maxState[1][0]=max(0,x-1);  maxState[1][1]=y;           maxState[2][0]=x;               maxState[2][1]=min(19,y+1);}
        else if(dr[0]==x-1 && dr[1]==y){    maxState[0][0]=x;maxState[0][1]=y;  maxState[1][0]=x;           maxState[1][1]=min(19,y+1); maxState[2][0]=x;               maxState[2][1]=max(0,y-1);}
        else if(dr[0]==x-1 && dr[1]==y-1){  maxState[0][0]=x;maxState[0][1]=y;  maxState[1][0]=max(0,x-1);  maxState[1][1]=y;           maxState[2][0]=x;               maxState[2][1]=max(0,y-1);}
        else if(dr[0]==x && dr[1]==y-1){    maxState[0][0]=x;maxState[0][1]=y;  maxState[1][0]=max(0,x-1);  maxState[1][1]=y;           maxState[2][0]=min(19,x+1);     maxState[2][1]=y;}
        else if(dr[0]==x+1 && dr[1]==y-1){  maxState[0][0]=x;maxState[0][1]=y;  maxState[1][0]=x;           maxState[1][1]=max(0,y-1);  maxState[2][0]=min(19,x+1);     maxState[2][1]=y;}
        else if(dr[0]==x+1 && dr[1]==y){    maxState[0][0]=x;maxState[0][1]=y;  maxState[1][0]=x;           maxState[1][1]=max(0,y-1);  maxState[2][0]=x;               maxState[2][1]=min(19,y+1);}
        else done=1;
    }
    if(done==1)
    {

        //Cop 1 code starts here
        max_dist=dist(dr,cop1);
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
                if(!(next_state[0]==maxState[0][0] && next_state[1]==maxState[0][1]))
                {
                    maxState[1][0]=next_state[0];
                    maxState[1][1]=next_state[1];
                }
            }
        }

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
                if(!(next_state[0]==maxState[1][0] && next_state[1]==maxState[1][1]))
                {
                    if(!(next_state[0]==maxState[0][0] && next_state[1]==maxState[0][1]))
                    {
                        maxState[2][0]=next_state[0];
                        maxState[2][1]=next_state[1];
                    }
                }
            }
        }
    }

//Doctor code here
    int min_dist=0;
    int drmindist=100;
    vector<int> nextdrcentre;
    int randr1=rand()%5+3;
    int randr2=rand()%5+14;
    int randr3=rand()%5+3;
    int randr4=rand()%5+14;
    //cout<<randr1<<" "<<randr2<<" "<<randr3<<" "<<randr4<<endl;

    if(!(dr[0]>=randr1 && dr[0]<=randr2 && dr[1]>=randr3 && dr[1]<=randr4))
       {
           //Move towards centre (10,10)
            int centre[2]={10,10};
            int drmin_dist=100;
            for(int i=1;i<=9;i++)
            {
                next_state[0]=dr[0]+nextDRStatex[i];
                next_state[1]=dr[1]+nextDRStatey[i];
                if(!StateValid(next_state))continue;
                if(dist(next_state,centre)<=drmindist)
                    drmindist=dist(next_state,centre);
            }
            for(int i=1;i<=9;i++)
            {
                next_state[0]=dr[0]+nextDRStatex[i];
                next_state[1]=dr[1]+nextDRStatey[i];
                if(!StateValid(next_state))continue;
                if(dist(next_state,centre)==drmindist)
                    nextdrcentre.push_back(i);
            }
            min_dist=0;
            for(int i=0;i<nextdrcentre.size();i++)
            {
                next_state[0]=dr[0]+nextDRStatex[nextdrcentre[i]];
                next_state[1]=dr[1]+nextDRStatey[nextdrcentre[i]];
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
       }
    else
    {
        min_dist=0;
        for(int i=1;i<=9;i++)
        {
            next_state[0]=dr[0]+nextDRStatex[i];
            next_state[1]=dr[1]+nextDRStatey[i];
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
    }


//Done the coding..Print the results
    if(player=='C')
    {
        for(int i=0;i<3;i++)
               printf("%d %d ",maxState[i][0],maxState[i][1]);
    }
    else
    printf("%d %d",drNextState[0],drNextState[1]);
}

/* Tail starts here */
int main() {
    srand(time(NULL));
    int dr[2],cop1[2],cop2[2],cop3[2];
    char player;
    cin>>player;
    cin>>dr[0]>>dr[1];
    cin>>cop1[0]>>cop1[1]>>cop2[0]>>cop2[1]>>cop3[0]>>cop3[1];
    calculate_move(player,dr,cop1,cop2,cop3);
}
