#include <stdio.h>
#include <malloc.h>
#include <string.h>
int copyString (char * dest ,char * src , int len )
{int i;
 for(i=0;i<len;i++)
 {
   dest[i]=src[i];
 }
 dest[i]='\0';
 return i;
}
int main_string  ()
{
  
  char ** strArr =NULL;
  strArr= (char ** )malloc(sizeof (char)*10);

  for(int i=0;i<10;i++)
  {
   strArr[i]=(char *)malloc(sizeof (char)*15);
  }

  char input[100];

  printf("Enter the sentence \n");
  //fgets(input,100,stdin);
  gets(input);
  
  int i=0;
  int j=0;
  while (input [i]!='\0')
  {
    int start =i;

	int len =0;
	while(input[i])
	{
	 if(input[i]==' ')
		 break;
	  i++;
	}
  len=i-start+1;
   copyString(strArr[j++],(input+start),len);   
  i++;
  }
  for(int i=0;i<j;i++)
   {
    puts(strArr[i]);
   }
   printf("Comparing 1 to 3 %d \n",strcmpi(strArr[0],strArr[2]));
 /* for(int i=0;i<10;i++)
  {
    free(strArr[i]);
  }
  free (strArr);*/
  return 1;
}
