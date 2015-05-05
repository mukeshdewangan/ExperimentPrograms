#include <stdio.h>
#include <malloc.h>
#include <assert.h>
typedef struct Node {
  int info;
  struct Node * next; 
}NODE ;

NODE * AddNumber(NODE * first ,NODE * second );
NODE * Split(NODE * root );
NODE * ReverseList (NODE * root);
NODE * newNode (int info)
{
	NODE * NEWNODE = (NODE *) malloc(sizeof(NODE));
	NEWNODE->info=info;
	NEWNODE->next=NULL;
	return(NEWNODE);
}

NODE * InsertAtFirst(NODE *root,int info)
{
   if(root==NULL )
   {
    root=newNode(info);
	return root;
   }   
   NODE * infoNode = newNode(info);
   infoNode->next=root;
  // root->next=infoNode;
   return infoNode;
}
NODE *InsertAtLast (NODE *root,int info)
{
   if(root==NULL )
   {
    root=newNode(info);
	return root;
   }   
   NODE * infoNode = newNode(info);
   NODE * ptr =root;
   while(ptr->next!=NULL)
   {
	   ptr=ptr->next;
   }
   ptr->next=infoNode;
   return root; 

}

void Display(NODE * root )
{
  if(root==NULL)
  {printf("empty list\n");
   return ;
  }
  NODE * ptr= root;
  int count=0 ;
  while(ptr!=NULL)
  {
	count++;
	printf("\n");
	printf("%d = %d \t",count,ptr->info);
    ptr=ptr->next;	 
  }
}
NODE * AddNumber(NODE * first ,NODE * second )
{
	assert(! (first==NULL&& second==NULL ));
	if(first==NULL) return second;
	if(second==NULL) return first;
	NODE * result =NULL ;
	NODE *ptr1 = first,*ptr2=second ,*ptr_res=NULL;
	int carry =0;
	while (ptr1!=NULL && ptr2 !=NULL )
	{
	  int digit =(ptr1->info + ptr2->info + carry)%10;
	  carry =(ptr1->info + ptr2->info)/10;
	  result=InsertAtLast(result,digit);
	  ptr1=ptr1->next;
	  ptr2=ptr2->next;
	}
   return result;
}
//Split the  linked list into 2 equal parts 
//this function returns the pointer to the second list 
//since the first list has obviously passing pointer
NODE * Split(NODE * root )
{
  assert(root!=NULL);
 
  NODE * slow =root;
  NODE *fast=slow->next ;
  NODE *latest=NULL;
  while(fast!=NULL)
  {  
    latest = slow;
	slow=slow->next;
	fast = (fast->next)? (fast->next)->next:NULL;
  } 
  latest->next=NULL;
  return slow;  
}

NODE * HelperRecursion(NODE * ptr ,NODE ** newStart)
{ 
	if(ptr->next==NULL)
	{	  		
		*newStart=ptr;
	}
	else 
	{
		NODE * temp = HelperRecursion(ptr->next,newStart);
		temp->next=ptr;	
	}
	return ptr;
}
NODE * ReverseList (NODE * root)
{
   if(root==NULL) 
   {
     printf("Empty List how can i reverse !!!\n"); return root;
   }
   NODE * newStart=NULL ;
   HelperRecursion(root,&newStart);
   root->next=NULL;
   return newStart;
}
NODE * OddEven(NODE * start)
{
	NODE * Even =NULL , * odd =NULL ;
	NODE * EvenLastSeen =NULL,*OddLastSeen=NULL;
	NODE * ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->info % 2)
		{
			if(odd==NULL)
			{	odd=ptr;	}
			else 
			{  OddLastSeen->next=ptr;}
			OddLastSeen=ptr;
		}
		else //even info
		{
		  if(Even==NULL)
		  { Even=ptr;}
		  else 
		  { EvenLastSeen->next=ptr;}
		  EvenLastSeen=ptr;
		}
	ptr=ptr->next;	 
 	}
	if(odd==NULL){return Even;}
	if (Even==NULL){return odd;}
	OddLastSeen->next=Even;
	EvenLastSeen->next=NULL;
	return odd;
}
int main_reverselist()
{
	NODE * root=NULL ;	
	//root=InsertAtFirst(root,3);		
	root=InsertAtFirst(root,1);
	root=InsertAtFirst(root,5);
	root=InsertAtFirst(root,6);
	root=InsertAtFirst(root,8);
	root=InsertAtFirst(root,9);
	root=InsertAtFirst(root,2);
	printf("\nDispalying 1 st poly");
	Display(root);
	//NODE * revroot=ReverseList(root);
	//printf("\nDispalying 1st poly after reversing\n");
	//Display(revroot);

	/*NODE * nodesplit = Split(root); 
	printf("\nDispalying 1st part");
		Display(root);
	printf("\nDispalying 2nd part");
	Display(nodesplit);*/
	
	/*NODE *secondRoot=NULL;
	secondRoot=InsertAtFirst(secondRoot,2);
	secondRoot=InsertAtFirst(secondRoot,9);
	secondRoot=InsertAtFirst(secondRoot,4);
	printf("\nDispalying 2nd poly");
	Display(secondRoot);

	NODE *result = AddNumber(root,secondRoot);
	printf("\nDispalying result  poly");
	Display(result);*/
		printf("\nDispalying Odd-Even poly");
	NODE *NewRoot = OddEven(root);
	Display(NewRoot);


 return 0;
}