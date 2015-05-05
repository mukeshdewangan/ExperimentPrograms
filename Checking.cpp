#include <stdio.h>
#include <string.h>
#define  OUT 1
#define  IN  0

int main_WordCount()
{  
   FILE * fp = fopen ("string operation.cpp","r");
   if(fp==NULL)
   {
	   printf("Error in opening for reading  ");
     return 1;
   }
   FILE * fout = fopen ("Copy.cpp","w");
   if(fout==NULL)
   {
	   printf("Error in opening for writing   ");
     return 1;
   }

   int state =OUT;
   int line=0, word=0,character=0;
   char ch;
  // char back ='\b';
   while ((ch =getc(fp))!=EOF)
   { 
	fputc(ch ,fout);
	character++;
   if(ch=='\n')
    {   
	 line++;
     fputc('\b',fout);
    }
   if(ch=='\n'||ch=='\t'|| ch==' ')
	{ 
		state =OUT;
	  
    }
   else if(state==OUT)
    {   state =IN;
	    word++;	   
    }   
   printf("%c",ch);

   }
   fclose(fp);
   fclose(fout);

     printf("line count %d ",line);
	 printf("word count %d ",word);
	 printf("character count %d ",character);
	 
	return 0;
}