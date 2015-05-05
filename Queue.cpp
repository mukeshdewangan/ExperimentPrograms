#include <queue>
#include <stdio.h>

int main_queue ()
{

 std::queue <int> treeQ ;
 treeQ.push(3);
 treeQ.push(8);
 treeQ.push(5);

 while(!treeQ.empty())
 {	
	 printf(" %d ",treeQ.front());    
	 treeQ.pop();
 }
 return 0;
}