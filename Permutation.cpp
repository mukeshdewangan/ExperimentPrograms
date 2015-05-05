#include <stdio.h>
#include <string.h>
void PrintStr(char str[], int end)
{
 for (int i=0;i<=end;i++)
 {
   printf("%c",str[i]);
 }
 printf("\n");
}
void Permute(char str[],int begin , int end)
{
  if(begin==end)
  {
   PrintStr(str,end);
  }
  else 
  { 
	  for(int k=begin;k<=end;k++)
	  {
	  //swap the pair (begin,k)	
	   char temp = str[begin];str[begin]=str[k];str[k]=temp;
	   Permute(str, begin+1 ,end);
  	  //swap the pair (begin,k)	
	   temp = str[k];str[k]=str[begin];str[begin]=temp;
	  }
  }
}

int main/*_permute*/()
{
	char str[]="HEL";
 Permute(str,0 ,strlen(str)-1);
  //const char * ptr=strstr("Heelooaaloochaat","oo");
  //printf("  %s ",ptr);
 return 0;
}