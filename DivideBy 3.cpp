#include <stdio.h>
float divideBy3(int num)
{   float abc=0;
	while(num>3)
	{
	 abc++;
	 num-=3;
	}
	switch(num)
	{
	case 0: break;
	 case 1:abc+=0.333333f; break;
	 case 2:abc+=0.666666f;
	}
	return abc;
}
int main_divide ()
{
	int fl;
  puts ("Enter the interger value to b divided by 3 ");
  scanf("%d",&fl);
  printf("\n Answer %f ",divideBy3(fl));
  return 0;
}