#include <stdio.h>

#include <crtdbg.h>

#define assert(exp)   ( (exp) ? (void) 0 : _ASSERT(#exp, __FILE__, __LINE__) )

int main_Assert ()
{
	int a=9,b=13;
	 assert(a<b);
	printf ("having\n a luck\rnow u rea\bl\n\bise ");
	return 0;
	
}