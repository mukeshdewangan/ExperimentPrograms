#include <stdio.h>
#include <malloc.h>
#include <queue>
 typedef struct node 
{
   int info ;
   node * left;
   node * right;
}NODE ;
 int countLeaf(NODE * root )
 {	
		int left=0;
		int right =0;
	    if((root->left==NULL&&root->right==NULL))
	       return 1;
		if(root->left!=NULL)
		{
			left=countLeaf(root->left);
		}
		if(root->right!=NULL)
		{
			right=countLeaf(root->right);
		}
		return (left+right);

	/*if(root->left!=NULL &root->right!=NULL)
	 {
	  return (countLeaf(root->left)+countLeaf(root->right));
	 }
	 else if((root->left==NULL&&root->right==NULL))
	   return 1;
	 else if(root->right==NULL)
	 {
	  return (countLeaf(root->left));
	 }
	 else 
	 {
	  return (countLeaf(root->right));
	 }*/
 }
 void LowestCommonAncestor(NODE * root , int info1 , int info2 );
 NODE * CreateBST (int Array[],int ,int);
 void BFS(NODE *root)    
{      

 if(root==NULL)
	 return ;
 std::queue <NODE *> treeQ ;
 printf("\nprinting tree level wise\n");
 treeQ.push(root);
 //You don't need to write the root here, it will be written in the loop
 while (!treeQ.empty())
 {
	 NODE * n=treeQ.front();
	 treeQ.pop();
	 printf(" %d ",n->info);
    if (n->left !=NULL)
    {
		//Only write the value when you dequeue it
        treeQ.push(n->left);//enqueue the left child
    }
    if (n->right !=NULL)
    {
       treeQ.push(n->right);//enque the right child
    }
 }
}

 NODE * CreateNew(int info )
 {
	 NODE * newNode = (NODE *)malloc(sizeof(NODE ));
	 newNode->info=info;
	 newNode->left=NULL;
	 newNode->right=NULL;
	 return newNode;
 }

 NODE * InsertNode (NODE *point , int info )
 {    	
	 if(point==NULL)
	 {
	   return (CreateNew(info));
	 }
	 else
	 {
		 if(info <= point->info )
		 {
		   point->left= InsertNode(point->left ,info);
		 }
		 else
		 {
		  point ->right=InsertNode(point->right,info);
		 }
		 return point;
	 }
 }

 int InOrderDisplay(NODE * Point ) 
 {
   if(Point ==NULL)
   {
     return 0;
   }
   InOrderDisplay(Point->left);
   printf(" %d ",Point->info);
   InOrderDisplay(Point->right);
  
   return 0;
 }
 int main_tree ()
 {
 /*  NODE * root = NULL ;
   root= InsertNode(root, 4);
   root= InsertNode(root, 8);
   root= InsertNode(root, 2);
   root= InsertNode(root,3);
   root= InsertNode(root, 7);
   root= InsertNode(root,1);
   root= InsertNode(root,9);*/
  // InOrderDisplay(root);
   /*int count =countLeaf(root);
   printf("\ntotal leaf node %d \n",count);*/
   
   //BFS(root);

  
   int Array [11]={1,2,3,4,5,6,7,8,9,10,11};
   int size =11;
   NODE * newRoot = NULL;
//   newRoot=CreateBST(Array,size,newRoot);
   InOrderDisplay(newRoot);
   BFS(newRoot);
   return 0;
 }

 void LowestCommonAncestor(NODE * root , int info1 , int info2 )
 {
    if(root==NULL) 
	{
	  printf("Tree is empty \n");
	  return ;
	}

	int path1[10]={0};
	int path2[10]={0};
	NODE *ptr= root;
	while(ptr!=NULL)
	{ 
		if(ptr->info==info1)
		{ 
		  printf("found \n");
		  
		}
		if(ptr->info < info1)
		{
			ptr=ptr->right;
		}
		else if(ptr->info > info1)
		{
			ptr=ptr->left;
		}
		else
			break;
	}
 }

 /*NODE * CreateBST (int Array[],int start , int end ,NODE *newRoot )
 {
    int mid = start +(end-start)/2;
	
 }*/