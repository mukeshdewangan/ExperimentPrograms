#include <string>
using namespace  std;

int main_longestPrefix ()
{
  char   strArr[100] ;
  puts("Enter the sentence separated by , . : or  space ");
  fgets(strArr,100,stdin);
  
  char * ptr = strtok(strArr," ,.:");
  int length =strlen(ptr);
  while(ptr!=NULL)
  {
	  //puts(ptr);
	  int j=0;
	  while(j< length &&  ptr[j]==strArr[j])
	  {	  
		  j++;  
	  }
	  length=j;
     ptr= strtok(NULL ," ,.:");	
  }
 
  printf("Longest prefix length %d ", length);  
  for(int i=0;i<length;i++)
	  printf("%c",strArr[i]);

   printf("\n");
  return 0;
}