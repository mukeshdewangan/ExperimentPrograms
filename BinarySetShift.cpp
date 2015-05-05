#include <stdio.h>
#include <string.h>
#include <malloc.h>
int power(int base , int expo)
{ 
	int result=1;
  while(expo>0)
  {
   result=result*base ;
   expo--;
  }
  return result;
}

//Create  the Bool Array Digit denotes the Binary representation of 
 
void BoolArray(bool *Digit ,unsigned  int dig,unsigned int num,char str[])
{
  for(int i=0;i<dig;i++)
  {	  
  //generates the Bool 
  Digit[i] = num & 0x01; 
	  num=num>>1;
  }  
  printf("{ ");
  for(int i=0;i<dig;i++)
  {	    
	  if(Digit[i])
		  printf("%c ",str[i]);
  }
  printf("}\n"); 
}
int main ()
{
	printf("Enter the String \n");
	char string[20]={'\0'};
	fgets(string,20,stdin);
    unsigned int n=strlen(string)-1;
	printf("size of Boolean Array %d\n",n);
	bool (* arr) =  (bool *)malloc (sizeof(bool)*n ); 
	int total =power(2,n) ;
	//here we pass the total no of the permutation  to be generated , since it is 2^n  hence total =2^n
	
	// we pass the each no one by one 
	for(int i=0;i<total;i++)
	{
		BoolArray(arr,n,i,string);
	}
  return 0;
}