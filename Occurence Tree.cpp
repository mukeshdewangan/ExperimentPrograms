#include <stdio.h>
#include <string.h>
struct node { 
    char word[15]; 
	int count;
    struct node* left; 
	struct node* right; 
} ;

/* 
 Given a binary search tree, print out 
 its data elements in increasing 
 sorted order. 
*/ 
void printTreeOccur(struct node* node) { 
  if (node == NULL) return; 
  printTreeOccur(node->left); 
  printf("%s %d\n", node->word,node->count); 
  printTreeOccur(node->right); 
} 

/* 
 Helper function that allocates a new node 
 with the given data and NULL left and right 
 pointers. 
*/ 
struct node* NewNode(char * data) { 
  struct node* node = new(struct node);    // "new" is like "malloc" 
   strcpy(node->word ,data); 
   node->count=1;
  node->left = NULL; 
  node->right = NULL; 
  

  return(node); 
} 
  

/* 
 Give a binary search tree and a number, inserts a new node 
 with the given number in the correct place in the tree. 
 Returns the new root pointer which the caller should 
 then use (the standard trick to avoid using reference 
 parameters). 
*/ 
struct node* insert(struct node* node, char * data)
{ 
  // 1. If the tree is empty, return a new, single node 
  if (node == NULL) 
    {
    struct node *temp = NewNode(data);
	return(temp); 
    } 

    if ((strcmpi(data , node->word))==0)
			node->count++;
	
	else if((strcmpi(data , node->word)<0))
			node->left = insert(node->left, data); 
		
    else 
			node->right = insert(node->right, data); 

    return(node); // return the (unchanged) node pointer 

  } 

int main_Occurence()
{
	struct node * root =NULL;
	char str[100] ={'\0'};
	printf("Enter the sentence \t");
	fgets(str,100,stdin);
	char * pch;
	pch = strtok (str," \n");
	while (pch != NULL)
	 {
	  root=insert (root,pch);
	  pch = strtok (NULL," \n");
	  }
	printTreeOccur(root);
 return 0;
}