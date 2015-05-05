#include <stdio.h>
int LinearSearch(char string  [],int  key )
{  
  int k, count =0;
  for (int k=0;string [k]!='\0';k++)
  {
   if(string [k]==key)
   {
    count++;
   }
  }
  return count;
}

int main_occurence()
{
	int i=0, count=0;
	int occurence [26]={0};
	char source  [15]={'\0'} , destn[20]={'\0'};
	scanf("%s",source);
	printf("%s\n",source);

	scanf("%s",destn);
	printf("%s\n",destn);

	while(source[i])
	{    
	    count=LinearSearch(destn,source[i]);		
		 occurence[source[i]-'a']=count;
		i++;
	}

	for(int i=0;i<26;i++)
	 {		
		 if(occurence[i])
			 printf("%c %d \n",'a'+i,occurence[i]);
	 }

 return 0;
}