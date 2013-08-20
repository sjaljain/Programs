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

bool StateMatch(int *state1,int *state2)
{
    if(state1[0]==state2[0] && state1[1]==state2[1])
    return true;
    else return false;
}



/* Head ends here */
void calculate_move(char player, int *dr,int* cop1, int* cop2, int* cop3) {

int rand1=rand()%2;

int maxState[3][2];
int Heuristic=1000,H;
int nextHstate[3][2];
if(rand1==0)
{
for(int i=1;i<=5;i++)
{
    for(int j=1;j<=5;j++)
    {
        for(int k=1;k<=5;k++)
        {
            nextHstate[0][0]=cop1[0]+nextCopStatex[i];
            nextHstate[0][1]=cop1[1]+nextCopStatey[i];
            if(!(StateValid(nextHstate[0])))continue;
            nextHstate[1][0]=cop2[0]+nextCopStatex[j];
            nextHstate[1][1]=cop2[1]+nextCopStatey[j];
            if(!(StateValid(nextHstate[0])))continue;
            nextHstate[2][0]=cop3[0]+nextCopStatex[k];
            nextHstate[2][1]=cop3[1]+nextCopStatey[k];
            if(!(StateValid(nextHstate[0])))continue;
            H=dist(dr,nextHstate[0])+dist(dr,nextHstate[1])+dist(dr,nextHstate[2]);
            if(StateMatch(nextHstate[0],nextHstate[1]))H+=2;
            if(StateMatch(nextHstate[1],nextHstate[2]))H+=2;
            if(StateMatch(nextHstate[0],nextHstate[2]))H+=2;
            if(H<Heuristic)
            {
                Heuristic=H;
                //cout<<H<<endl;
                maxState[0][0]=nextHstate[0][0];
                maxState[0][1]=nextHstate[0][1];
                maxState[1][0]=nextHstate[1][0];
                maxState[1][1]=nextHstate[1][1];
                maxState[2][0]=nextHstate[2][0];
                maxState[2][1]=nextHstate[2][1];
            }
        }
    }
}
}
else
{
for(int i=5;i>=1;i--)
{
    for(int j=5;j>=1;j--)
    {
        for(int k=5;k>=1;k--)
        {
            nextHstate[0][0]=cop1[0]+nextCopStatex[i];
            nextHstate[0][1]=cop1[1]+nextCopStatey[i];
            if(!(StateValid(nextHstate[0])))continue;
            nextHstate[1][0]=cop2[0]+nextCopStatex[j];
            nextHstate[1][1]=cop2[1]+nextCopStatey[j];
            if(!(StateValid(nextHstate[0])))continue;
            nextHstate[2][0]=cop3[0]+nextCopStatex[k];
            nextHstate[2][1]=cop3[1]+nextCopStatey[k];
            if(!(StateValid(nextHstate[0])))continue;
            H=dist(dr,nextHstate[0])+dist(dr,nextHstate[1])+dist(dr,nextHstate[2]);
            if(StateMatch(nextHstate[0],nextHstate[1]))H+=2;
            if(StateMatch(nextHstate[1],nextHstate[2]))H+=2;
            if(StateMatch(nextHstate[0],nextHstate[2]))H+=2;
            if(H<Heuristic)
            {
                Heuristic=H;
                //cout<<H<<endl;
                maxState[0][0]=nextHstate[0][0];
                maxState[0][1]=nextHstate[0][1];
                maxState[1][0]=nextHstate[1][0];
                maxState[1][1]=nextHstate[1][1];
                maxState[2][0]=nextHstate[2][0];
                maxState[2][1]=nextHstate[2][1];
            }
        }
    }
}
}

//Doctor code here
    Heuristic=1000;
    int next_state[2],drNextState[2];
    for(int i=1;i<=9;i++)
    {
        next_state[0]=dr[0]+nextDRStatex[i];
        next_state[1]=dr[1]+nextDRStatey[i];
        if(!StateValid(next_state))continue;
        H=dist(next_state,maxState[0])+dist(next_state,maxState[1])+dist(next_state,maxState[2]);
        H+=(abs(next_state[0]-10)+abs(next_state[1]-10));
        if(H<Heuristic)
        {
            Heuristic=H;
            drNextState[0]=next_state[0];
            drNextState[1]=next_state[1];

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
