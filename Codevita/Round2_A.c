#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    double L;
    double R,N;
    if(scanf("%lf",&L)!=1){printf("Invalid Input");return 0;}
    if(scanf("%lf",&R)!=1){printf("Invalid Input");return 0;}
    if(scanf("%lf",&N)!=1){printf("Invalid Input");return 0;}
    char *c;
    scanf("%s",c);
    if(strcmp(c,"MONTHLY")!=0){printf("Invalid Input");return 0;}
    double I=R/12;
    double emi;
    emi=(L*I)*pow(1+I,N);
    printf("emi=%lf",emi);
    emi/=(pow((1+I),N)-1);
    printf("emi=%lf",emi);

    return 0;
}
