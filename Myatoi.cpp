#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *MYstrdup (const char *s)
{ 
	char *d = (char *)(malloc (strlen (s) + 1)); 
	// Allocate memory     
	if (d != NULL)         
		strcpy (d,s);                            
	// Copy string if okay     
	return d;                                    
	// Return new memory 
} 

int  myatoi(char string[])
{
  int result =0;
  int count =0;
  while(*string>='0' && *string <='9' && *string)
  {
	 //  count ++;
	 // printf("iteration %d",count);
	 // printf("result<<3=%d  and result<<1=%d *string-'0'=%d\n",result <<3,result<<1,*string-'0');
    //  result=(result<<3) + (result<<1) + (*string - '0');
	  result =(result*10)+(*string -'0');		 
	  string++;	
  }
  return result;
}


int main_myatoi()
{
	char string[] ={'1','8','2','0','\0'};
	char *string1 ="6346";
	
  int i= myatoi (string1);
  printf(" the converted %d \n",i);
  printf("sizeof of string is %d \n",sizeof string1);
  return 0;
 /* char * pPath;
  pPath = getenv ("PATH");
  if (pPath!=NULL)
    printf ("The current path is: %s",pPath);
  return 0;*/
  
  char *special ="having tea";
  char *duplicate=NULL;
  duplicate=MYstrdup(special);
  printf("the dup string %s \n",duplicate);
  return 0;
}