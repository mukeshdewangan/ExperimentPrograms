#include <stdio.h>

int main_remove ()
{
  FILE *file;
 int c;
  int n = 0;

  file = fopen("Template.cpp", "r");
  
  if (file==NULL) 
      perror ("Error reading file");
  else
  {
    do {
      c = getc (file);
       printf("%c",c);
      } while (c != EOF);
    fclose (file);
   // printf ("my.txt contains %d $.\n",n);
  }
  return 0;
}
