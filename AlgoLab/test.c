#include<stdio.h>

#define void int
int main()
{
     int i=200;
     {
      int i=100;
      printf("%d",i);
      }
      printf(" %d",i);
}
