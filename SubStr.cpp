#include <stdio.h>

int SubStr (char *string ,char *pattern);
int main_substr()
{
 char string[] ="He has some thing to do";
 char  pattern[]="do";

 int pos= SubStr(string,pattern);
 printf(" position  %d ",pos );
  return 0;
}

int SubStr (char *string ,char *pattern)
{

 int i=0;
	while(string[i]!='\0')
	{ 
		int k=0;
		if(string[i]==pattern[k])
		{
		while(pattern[k]!='\0')
		{
			if (string[i+k]==pattern[k])
			{
			k++;
			}
			else  
				goto label;
		}

		if(pattern[k]=='\0')
		{
			return i;
		}
		}
		label:
		i++;
	}
	return -1;

}