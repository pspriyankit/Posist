#include<bits/stdc++.h>
#include<stdio.h>
#include<malloc.h>
#include<ctime>
#include<string>
#include<iostream>
using namespace std;
struct binaryTreeNode{
	time_t timestamp;	
int data; 
string nodeId;
struct binaryTreeNode* referenceNodeId;
string childReferenceNodeId[];
string genesisReferenceNodeId;
string HashValue; 
	struct binaryTreeNode * left;
	struct binaryTreeNode * right;
};

struct node
{
	struct binaryTreeNode * data;
	struct node * next;
};

struct queue
{
	struct node * front;
	struct node * rear;
};

struct queue * enQueue(struct queue * q, struct binaryTreeNode * num)
{
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = num;
	temp -> next = NULL;
	if(q == NULL)
	{
		q = (struct queue*)malloc(sizeof(struct queue));		
		q -> front = temp;
	}
	else
		q -> rear -> next = temp;
	q -> rear = temp;
	return q;
}

struct queue * deQueue(struct queue * q)
{
	struct node * temp = q->front;
	q -> front = q->front->next;
	free(temp);
	if(q->front == NULL)
		return NULL;
	else
		return q;
}

int isQueueEmpty(struct queue * q)
{
	if(q)
		return 0;
	else
		return 1;
}

int isSumProperty(struct binaryTreeNode* node)
{
/* left_data is left child data and right_data is for right 
	child data*/
int left_data = 0, right_data = 0;
/* If node is NULL or it's a leaf node then
	return true */
if(node == NULL ||
	(node->left == NULL && node->right == NULL))
	return 1;
else
{
	if(node->left != NULL)
	left_data = node->left->data;
	if(node->right != NULL)
	right_data = node->right->data;
	if((node->data > left_data + right_data)&&
		isSumProperty(node->left) &&
		isSumProperty(node->right))
	return 1;
	else
	return 0;
}
}

struct binaryTreeNode * insertInBinaryTree(struct binaryTreeNode * root, int num)
{
	if(isSumProperty(root))
{
	struct binaryTreeNode * temp = NULL;
	struct queue * Q = NULL;
	struct binaryTreeNode * newNode = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
	newNode -> data = num;
	newNode -> left = NULL;
	newNode -> right = NULL;
	
	if(root == NULL)
	{
		// If the root is NULL then the newNode is inserted at root
		root = newNode;
		return root;
	}
	
	// else proceed wiht the level order traversal
	Q = enQueue(Q, root);
	
	while(!isQueueEmpty(Q))
	{
		temp = Q -> front -> data;
		
		Q = deQueue(Q);
		
		if(temp -> left != NULL)
		{
			Q = enQueue(Q, temp -> left);
		}
		else
		{
			// Assign the new node to its left
			temp -> left = newNode;
			
			// Delete the queue and return
			free(Q);
			return root;
		}
		if(temp -> right != NULL)
		{
			Q = enQueue(Q, temp -> right);
		}
		else
		{
			// Assign the node to its right
			temp -> right = newNode;
			
			// Delete the queue and return
			free(Q);
			return root;
		}
	}
	
	free(Q);
	return root;
}
else
{
printf("\nThe given tree does not satisfy the children sum property ");	
}
}

void levelOrder(struct binaryTreeNode * root)
{
	struct binaryTreeNode * temp = NULL;
	struct queue * Q = NULL;
	if(root == NULL)
		return;
	Q = enQueue(Q, root);
	while(!isQueueEmpty(Q))
	{
		temp = Q -> front -> data;
		Q = deQueue(Q);
		printf("%d ",temp -> data);
		if(temp -> left)
			Q = enQueue(Q, temp -> left);
		if(temp -> right)
			Q = enQueue(Q, temp -> right);
	}
	free(Q);
}
int findLongestChain(struct binaryTreeNode* node) 
{
   if (node==NULL) 
       return 0;
   else
   {
       int leftDepth = findLongestChain(node->left);
       int rightDepth = findLongestChain(node->right);
 
       /* use the larger one */
       if (leftDepth > rightDepth) 
           return(leftDepth+1);
       else return(rightDepth+1);
   }
}
 
int main(void)
{
	// Initialize the tree
	struct binaryTreeNode * root = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
	root-> data = 16;
	struct binaryTreeNode * l = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
	l -> data = 8;
	struct binaryTreeNode * ll = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
	ll -> data = 4;
	ll -> left = ll -> right = NULL;
	struct binaryTreeNode * lr = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
	lr -> data = 2;
	lr -> left = lr -> right = NULL;
	l -> left = ll;
	l -> right = lr;
	struct binaryTreeNode * r = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
	r -> data = 6;
	
	r -> left = r -> right = NULL;
	
	root -> left = l;
	root -> right = r;
	levelOrder(root);
	
	printf("\n");
	root = insertInBinaryTree(root, 2);
	levelOrder(root);
	int hei=findLongestChain(root);
	cout<<"\nThe longest chain of the genesis node ="<<hei;
	return 0;
}