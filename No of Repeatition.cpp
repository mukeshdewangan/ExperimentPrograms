#include <stdio.h>
#include <string.h>
#include <iostream>

//#include <string>
#define max(A,B)  (A)>(B)?(A):(B)
int lengthOfLongestSubstring(std::string s)
{   
	int n = s.length(); 
	int i = 0, j = 0;  
	int maxLen = 0;  
	bool exist[256] = { false }; 
	while (j < n) 
	{     
		if (exist[s[j]])
		{      
			maxLen = max(maxLen, j-i); 
			  while (s[i] != s[j]) 
			  {         exist[s[i]] = false;   
							i++;      
			  }      
			  i++;    
			  j++;    
		} 
		else 
		{     
			exist[s[j]] = true;  
			j++;    
		}  
	}  
	maxLen = max(maxLen, n-i);
return maxLen;
} 

void printArray(char Array[],int size )
{
  for(int i=0;i<size;i++)
	  printf(" %d ",Array[i]);
}
void CharOccurence (char string[] ,int size )
{
	int occurence [26]={0};
	printf("caution all small letters \n");

	int i=0;
	while(string[i])
	{
	   occurence[string[i]-'a']++;
	   i++;
	}
	for(int i=0;i<26;i++)
	 {		
		 if(occurence[i])
		   printf("%c %d \n",'a'+i,occurence[i]);
	 }
}
int main_charOcuurence ()
{
	char pass[100];
	printf("Enter the string \t ");
	scanf("%s",pass);
	
	CharOccurence(pass,strlen(pass));
	printf("\nlongest occ %d\n",lengthOfLongestSubstring("ahvingfunidioys"));
	return 0;
}