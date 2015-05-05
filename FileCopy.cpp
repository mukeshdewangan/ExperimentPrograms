#include <iostream>
#include <fstream>
#include <sys/stat.h>
int main_FileCopy ()
{
	std::ifstream fileInput("RepeatArray.cpp",std::ios::binary);
	std::ofstream fileOutput("testing.txt",std::ios::binary);
	char line[10]={};
	
    int filesize;
    struct stat  results;
    
    if (stat("RepeatArray.cpp", &results) == 0)
	{ 
       filesize= results.st_size;
	}
    else
	{ 
		printf("Error\n"); 
	}

	printf("size of file %d\n",filesize);
	
	const int chunk=10;
	
	int size = filesize;
	while(size>chunk)
	{
	
	fileInput.read(line,chunk);	
	fileOutput.write(line,chunk) ;	
	size =size-chunk;
	}

	fileInput.read(line,size);		
	fileOutput.write(line,size);

	fileInput.close();
	fileOutput.close();
  return 0;
}