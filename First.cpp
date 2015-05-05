#include <stdio.h>
void FindMonoIncreasing(char * args, int *larg_start,int *larg_end)
{
  int i=1;
  int start=0,end=0;
  int MaxSub=0;
  *larg_start=0;
  *larg_end=0;
  
  while(args[i]!='\0')
  {
    if(args[i]>args[i-1])
	{
	 (end)++;
	}
	else 
	{
	 if(MaxSub<(end-start))
	 {
	  *larg_start = start;
	  *larg_end = end;
	  MaxSub=(end-start);
	 }
	 start=i;
	 end=start;
	}
	i++;
  }
  
  printf("largest monotonic Increasing subarray size %d \n",MaxSub+1);
  
}
int main(/*int argc , char * args[]*/ )
{
int number=0,st=0,en=0;
int * start=&st ,*end=&en;
char args[20] ="1457891245246972";
 //if(argc>=2)
 {
  //number =atoi(args[1]);
  //printf("Number input /10 =%d ",number/10);
  
  FindMonoIncreasing(args,start , end);
 } 
 //else 
 { 
 //printf("Wrong Input");
 }
 for(int i=*start ;i <=*end;i++)
 {
  printf("%c",args[i]);
 }
 return 0;
}