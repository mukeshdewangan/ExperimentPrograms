#include <stdio.h>


int main_TIME()
{
	printf(" %d  %s  Time %s ,No of times compiled =%d ",__LINE__,__FILE__
		,__TIMESTAMP__,__COUNTER__ );
	return 0;
}
