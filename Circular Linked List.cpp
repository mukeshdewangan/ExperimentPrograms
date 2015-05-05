#include <stdio.h>
#include <malloc.h>

typedef struct ListNode
{ 
	int info ;
	ListNode * next;
}LIST;

LIST * NewNode (int data )
{
	LIST * newListNode =(LIST * )malloc(sizeof(LIST));
	newListNode->info=data;
	newListNode->next=NULL;
	return newListNode;
}
LIST * InsertSorted (LIST * start , int data )
{
	if(start==NULL)
	{
		LIST * Node = NewNode(data);
		Node->next=Node;
	  return (Node);
	}
	if(start->info > data )//Inserting the smallest 
	{
	   LIST * Node = NewNode(data);	 
	   LIST * ptr= start;

	  while(ptr->next!=start)
	  {		
	    ptr=ptr->next;
	  }
	  
      Node->next=start;
	  ptr->next=Node;
	   return Node;
	}
	LIST * ptr = start;LIST* save =start;
	 LIST * Node = NewNode(data);
	while(ptr->next!=start&& ptr->info < data)
	{
		save=ptr;
	  ptr=ptr->next;
	}
	if(ptr->info > data) // Inserting middle element
	{
	 Node->next=save->next;
	   save->next=Node;
	}
	else //ptr->info > data  //inserting last element
	{
	  ptr->next=Node;
	  Node->next=start;
	}
	return start;
}
LIST * Insert (LIST * start , int data )
{
	if(start==NULL)
	{
		LIST * Node = NewNode(data);
		Node->next=Node;
	  return (Node);
	}
	LIST * ptr = start;
	LIST * Node = NewNode(data);
	while(ptr->next!=start)
	{
	  ptr=ptr->next;
	}
	if(ptr->next==start)
	{
	  ptr->next=Node;
	  Node->next=start;
	}
	return start;  //If commented giving Add at First Why ????
}
int Display (LIST * start)
{
  if(start==NULL)
  {
   puts("Empty list ");
   return 0;
  }
  LIST * ptr=start;
  unsigned int count =0;
  while(ptr->next!=start)
	{
		printf(" %d ",ptr->info);
	  ptr=ptr->next;
	  count++;
	}
  printf(" %d ",ptr->info);
  return count;
}
LIST * Search (LIST * start, int key)
{
	if(start==NULL)
	{	 return start;	}
	LIST * ptr = start;
	while(ptr->next!=start)
	{
	 if(ptr->info==key)
	  {
		return  ptr; 
	  }
	 ptr=ptr->next;
	}
	return NULL;
}
int main_Circular_List()
{
  LIST * root =NULL;
  root= InsertSorted(root,13);
  root= InsertSorted(root,36);
   // Display(root);
  root= InsertSorted(root,8);
  root= InsertSorted(root,34); 
  root= InsertSorted(root,23);

  //root= Insert(root,13);
  //root= Insert(root,36);
  // // Display(root);
  //root= Insert(root,8);
  //root= Insert(root,34);
  //root= Insert(root,23);
  Display(root);
  puts("searching 23");
  LIST  * ptr = Search (root,23);
  printf("  %d ",ptr->info);
 return 0;
}