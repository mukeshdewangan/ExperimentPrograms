#include <stdio.h>
#include <string.h>

void ReverseSent(char *string )
{
	printf("%s\n",string);
	int length = strlen (string);
	int i=length-1;
	int pre=length-1;
	while(i>=0)
	{
		if(string[i]==' ')
		{
		  for(int j=i+1;j<=pre;j++)
		  { 
			  printf("%c",string[j]);
		  }
		  printf(" ");				  
		  pre=i;
		}
		i--;
	}
	 for(int j=i+1;j<=pre;j++)
		  { printf("%c",string[j]);}
}
char * ReverseSentence  (char *string )
{
   char * ptr =  strtok(string," ,");
 
   while(ptr!=NULL)
   {
	printf("%s ",ptr);
    ptr=strtok(NULL," ,");
	
   }
   return string;
}

int main/*_reversesentence*/ ()
 {
	char string[] ="Hello it is Raman";
	ReverseSentence(string);

	return 0;
}