#include <stdio.h>
#define MAX 50
int main_files ()
{
	char First[MAX]={'\0'},Second[MAX]={'\0'},Final[MAX]={'\0'};
 printf("Enter the First File ");
 fgets(First,MAX,stdin);
 //scanf("%s",First);
 printf("Enter the Second File ");
 fgets(Second,MAX,stdin);
 //scanf("%s",Second);
 printf("Enter the File on which we have to concatenate ");
 fgets(Final,MAX,stdin);
 //scanf("%s",Final);
 if(First==NULL || Second==NULL)
 {
  puts("error in Files name input"); return 0;
 }

 FILE * FirstFile = fopen(/*"Quick Sort.cpp"*/First,"r");
 FILE * SecondFile =fopen(/*"Occurence count.cpp"*/Second ,"r");
 FILE * Result =fopen(/*"Final.txt"*/Final,"w");
 
 if(FirstFile==NULL)
 {
  puts("Error in opening 1 st File Names ");return 0;
 }if(SecondFile==NULL)
 {
  puts("first File is Correct \nError in opening 2nd File Names ");return 0;
 } 
 char Buffer[MAX]={'\0'};   
 while( ( fgets( Buffer, MAX,FirstFile  ) ) != NULL )
     {
        fputs( Buffer, Result );
     }
   fputs("\n",Result);
 while( ( fgets( Buffer, MAX,SecondFile  ) ) != NULL )
     {
        fputs( Buffer, Result );
     }
 fclose(FirstFile);
 fclose(SecondFile);
 fclose(Result);

 return 0;
}