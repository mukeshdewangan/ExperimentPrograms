#include <stdio.h>
typedef struct node { 
    int data; 
    struct node* left; 
	bool Predecessor ;
    struct node* right; 
	bool Succesor ;
}NODE ;
/* If Predecessor = true then its threaded 
else left child;

If Succesor =true then its threaded 
right child */


void printArray(int ints[], int len);

void printPathsRecur(struct node* node, int path[], int pathLen);
/* 
 Given a binary search tree, print out 
 its data elements in increasing 
 sorted order. 
*/ 
void printTree(NODE * node) { 
  if (node == NULL) return; 
  printTree(node->left); 
  printf("%d ", node->data); 
  printTree(node->right); 
} 
 
/* 
 Helper function that allocates a new node 
 with the given data and NULL left and right 
 pointers. 
*/ 


NODE * NewNode(int data) { 
  NODE * node = new(NODE);    // "new" is like "malloc" 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  node->Predecessor=false;
  node->Succesor=false;
  return(node); 
} 
  
/* 
 Give a binary search tree and a number, inserts a new node 
 with the given number in the correct place in the tree. 
 Returns the new root pointer which the caller should 
 then use (the standard trick to avoid using reference 
 parameters). 
*/ 
NODE * insert(NODE * node, int data) { 
  // 1. If the tree is empty, return a new, single node 
  if (node == NULL) { 
    return(NewNode(data)); 
  } 
  else { 
    // 2. Otherwise, recur down the tree 
    if (data <= node->data) node->left = insert(node->left, data); 
    else node->right = insert(node->right, data); 

    return(node); // return the (unchanged) node pointer 
  } 
} 
NODE * InsertIterative (NODE * root ,int data )
{
	if(root==NULL )
	{
	     return(NewNode(data)); 
	}
	NODE * ptr =root ;
	NODE * save =NULL;
	NODE * newInsert=NewNode(data);
	while(ptr!=NULL)
	{  
	 if(ptr->data > data )
	 {
		save =ptr;	
		 ptr=ptr->left;

	 }
	 else
	 {
		save =ptr;	
		 ptr=ptr->right;
	 }
	}
	if(save->data > data)
	{
	  save->left=newInsert;
	}
	else 
	{
	 save->right=newInsert;
	}
   return root ;
}
NODE * InsertThreaded (NODE * root , int data )
{
  if(root==NULL )
	{
	     return(NewNode(data)); 
	}
	NODE * ptr =root ;
	NODE * save=NULL ;
	NODE * newInsert=NewNode(data);
	while(ptr!=NULL)
	{  
	 if((ptr->data > data)) 
	 {
		 if((ptr->Predecessor==false))
		 {
		 save =ptr;	
		 newInsert->right=ptr;
		 newInsert->Succesor=true;
		 ptr=ptr->left;
		 }
		 else 
			 break;
	 }
	 else if((ptr->data < data))
	 {
		 if((ptr->Succesor==false))
		 {
		 newInsert->left=ptr;
		 newInsert->Predecessor=true;
		 save =ptr;	
		 ptr=ptr->right;
		 }
		 else 
			 break;
	 }
	}
	if(ptr==NULL)
	{
	if(save->data > data)
	{
	  save->left=newInsert;
	  //save->Predecessor=true;
	}
	else 
	{
	  save->right=newInsert;
	  //save->Succesor=true;
	}
	}
	else
	{
	if(ptr->data > data)
	{
	  ptr->left=newInsert;
	  //save->Predecessor=true;
	}
	else 
	{
	  ptr->right=newInsert;
	  //save->Succesor=true;
	}
	}
	
   return root ;
}
/* 
 Compute the "maxDepth" of a tree -- the number of nodes along 
 the longest path from the root node down to the farthest leaf node. 
*/ 
int maxDepth(NODE * node) { 
  if (node==NULL) { 
    return(0); 
  } 
  else { 
    // compute the depth of each subtree 
    int lDepth = maxDepth(node->left); 
    int rDepth = maxDepth(node->right); 
    // use the larger one 
    if (lDepth > rDepth) return(lDepth+1); 
    else return(rDepth+1); 
  } 
} 
/* 
 Given a binary tree, print out all of its root-to-leaf 
 paths, one per line. Uses a recursive helper to do the work. 
*/ 
void printPaths(NODE * node) { 
  int path[1000]; 
  printPathsRecur(node, path, 0); 
} 

/* 
 Recursive helper function -- given a node, and an array containing 
 the path from the root node up to but not including this node, 
 print out all the root-leaf paths. 
*/ 
void printPathsRecur(struct node* node, int path[], int pathLen)
{
   if(node ==NULL  )
   {    return ;   }
	
   path[pathLen]=node->data;
	pathLen++;
   if (node ->left==NULL && node ->right==NULL) 
   {    printArray( path ,pathLen);   }
   else 
   {
   printPathsRecur (node ->left,path,pathLen);
   printPathsRecur(node->right,path,pathLen);
   }
}

// Utility that prints out an array on a line. 
void printArray(int ints[], int len) 
{
	for(int i=0;i<len;i++)
	{	
	 printf(" %d ",ints[i]);
	}
	printf("\n");
}
NODE * ImageBST (NODE *root )
{
	if(root==NULL)
		return NULL;	
	NODE * Left =ImageBST(root->left);
	NODE * Right=ImageBST(root->right);
	 root->left=Right;
	 root->right=Left;
	 return root;

}
int CountNode(NODE * node)
{
  if(node ==NULL)
	   return 0;
  return (CountNode(node->left)+CountNode(node->right)+1);
}
int CountPossibleTree(NODE *root)
{
	if(root==NULL)
		return 0;
	/*else if(root->left!=NULL && root->right!=NULL)
	{
		return (CountPossibleTree(root->left)+CountPossibleTree(root->right)+5);
	}
	else if(root->left!=NULL)
	{
	  return (CountPossibleTree(root->left)+2);
	}
	else if(root->right!=NULL)		
	{
	  return (CountPossibleTree(root->right)+2);
	}	*/
	else
	{
         int count = 1;   // Start by counting the root.
         count += CountPossibleTree(root->left);  // Add the number of nodes
                                            //     in the left subtree.
         count += CountPossibleTree(root->right); // Add the number of nodes
                                           //    in the right subtree.
         return count;  // Return the total.
    }

}

/* 
 For the key values 1...numKeys, how many structurally unique 
 binary search trees are possible that store those keys. 
 Strategy: consider that each value could be the root. 
 Recursively find the size of the left and right subtrees. 
*/ 
int countTrees(int numKeys) { 

  if (numKeys <=1) { 
    return(1); 
  } 
  else { 
    // there will be one value at the root, with whatever remains 
    // on the left and right each forming their own subtrees. 
    // Iterate through all the values that could be the root... 
    int sum = 0; 
    int left, right, root; 

    for (root=1; root<=numKeys; root++) { 
      left = countTrees(root - 1); 
      right = countTrees(numKeys - root); 

      // number of possible trees with this root == left*right 
      sum += left*right; 
    } 

    return(sum); 
  } 
} 


int main_treepath ()
{
  /*node *Root=NULL;
  Root=insert (Root,3);
  Root=insert (Root,6);
  Root=insert (Root,5);
  Root=insert (Root,1);
  
  Root=insert (Root,8);
  Root=insert (Root,2);
  printTree(Root);*/
/* Root=InsertIterative (Root,3);
  Root=InsertIterative (Root,6);
  Root=InsertIterative (Root,5);
  Root=InsertIterative (Root,1);
  
  Root=InsertIterative (Root,8);
  Root=InsertIterative (Root,2);
  printTree(Root);*/
  NODE *Root=NULL;
  Root=InsertThreaded (Root,3);
  Root=InsertThreaded (Root,6);
  
  Root=InsertThreaded (Root,1);
  Root=InsertThreaded (Root,5);
  Root=InsertThreaded (Root,8);
  Root=InsertThreaded (Root,2);
  printTree(Root);

  //printf("Depth =%d \n",maxDepth(Root));
  // printPaths(Root);
  // Root =ImageBST(Root);
  //puts("\nprinting the image of tree");
  //printTree(Root);

  // printf("\n Tree Possible %d ",countTrees(3));
  //printf("\n2nd method  Tree Possible %d ",CountPossibleTree(Root));
  //printf(" %d ",CountNode(Root));
  return 0;
}