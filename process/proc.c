#include "proc.h"

#define N 51
void proc()
{
  printf("\n\n\n\n");
  char p[N]={'\0'};
  int i=1;
  char*pp="-|/\\";
  for(;i<N;i++)
  {
    p[i-1]='#';
    printf("\t[%-50s][%3d%%][%c]\r",p,2*i,pp[i%4]);
  fflush(stdout);
  usleep(300000);
  }
  printf("\n\n");
} 

