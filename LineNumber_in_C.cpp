#include <stdio.h>
#include <stdlib.h>



//__FILE__ Source file name (string constant) format "patx.c" 
//__LINE__ Current source line number (integer) 
//__DATE__ Date compiled (string constant)format "Dec 14 1985" 
//__TIME__ Time compiled (string constant) format "15:24:26" 
//__TIMESTAMP__ Compile date/time (string constant)format "Tue Nov 19 11:39:12 1997"


//Usage example


static char stamp[] = "***\nmodule " __FILE__ "\ncompiled " __TIMESTAMP__ "\n***";



int main_line()
{ 

FILE *fp;
if ( (fp = fopen("LineNumber_in_C.cpp","r")) == NULL ) 
{ 
printf( "open failed, line %d\n%s\n",__LINE__, stamp ); 
exit( 4 ); 
}


}

