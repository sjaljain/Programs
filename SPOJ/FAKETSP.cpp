/* String processing - Extracting numbers*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
  int i,j,k;
   double x,y,result,x2,y2;
  char s[1000],s2[100],s3[100],c;
  result=0;
  gets(s);
  j=0;
  k=0;
  for(i=0;;)
  {
    if(s[i]!='(') i++;
    else if(s[i]=='(')
    {
      i=i+1;
      while(s[i]!=','){s2[j++]=s[i];i++;}
      i=i+1;
      while(s[i]!=')'){s3[k++]=s[i];i++;}
      break;
    }
  }

  s2[j]='\0';
  s3[k]='\0';
  x=atof(s2);
  y=atof(s3);
  while(1)
  {
   i=0;

   c=getchar();
   if(c=='\n') continue;
   else if(c==EOF) break;
   while(c!='\n')
   {
     s[i]=c;
     i++;
     c=getchar();
   }




  j=0;
  k=0;

  for(i=0;;)
  {
    if(s[i]!='(') i++;
    else if(s[i]=='(')
    {
      i=i+1;
      while(s[i]!=','){s2[j++]=s[i];i++;}
      i=i+1;
      while(s[i]!=')'){s3[k++]=s[i];i++;}
      break;
    }
  }
  s2[j]='\0';
  s3[k]='\0';
  x2=atof(s2);
  y2=atof(s3);


  //printf("%f %f ",x2,y2);
  result+=(double)sqrt((x2-x)*(x2-x)+(y2-y)*(y2-y));
  x=x2;
  y=y2;

 printf("The salesman has traveled a total of %.3lf kilometers.\n",result);


 }


return 0;
}

