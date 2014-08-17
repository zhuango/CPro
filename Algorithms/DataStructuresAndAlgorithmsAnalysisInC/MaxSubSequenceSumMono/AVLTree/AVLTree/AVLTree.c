#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "BinarySearchTree.h"

int Height(TreeNode *Node)
{
	if(Node == NULL)
		return -1;
	else
		return Node->Height;
}
TreeNode* FindMax(TreeNode *Root)
{
	//The Rightest node is the Max.
	TreeNode *index = Root;
	while(index->Right != NULL)
		index = index->Right;
	return index;
}

TreeNode* FindMin(TreeNode *Root)
{
	//The Leftest node is the Min.
	TreeNode *index = Root;
	while(index->Left != NULL)
		index = index->Left;
	return index;
}

TreeNode* DeleteMin(TreeNode *Root)
{
	TreeNode *index = Root;
	while(index->Left != NULL)
		index = index->Left;
	free(index);
	return Root;
}

int Max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

static TreeNode *SingleRotateWithRight(TreeNode *heigh)
{
	TreeNode *low;

	low = heigh->Right;
	heigh->Right = low->Left;
	low->Left = heigh;

	heigh->Height = Max(Height(heigh->Left), Height(heigh->Right)) + 1;
	low->Height = Max(Height(low->Left), Height(low->Right)) + 1;

	return low;
}

static TreeNode *SingleRotateWithLeft(TreeNode *heigh)
{
	TreeNode *low;

	low = heigh->Left;
	heigh->Left = low->Right;
	low->Right = heigh;

	heigh->Height = Max(Height(heigh->Left), Height(heigh->Right)) + 1;
	low->Height = Max(Height(low->Left), Height(low->Right)) + 1;

	return low;
}

static TreeNode *DoubleRotateWithRight(TreeNode *heigh)
{
	heigh->Right = SingleRotateWithLeft(heigh->Right);
	return SingleRotateWithRight(heigh);
}

static TreeNode *DoubleRotateWithLeft(TreeNode *heigh)
{
	heigh->Left = SingleRotateWithRight(heigh->Left);
	return SingleRotateWithLeft(heigh);
}
TreeNode *Insert(TreeNode *Root, ElementType data)
{
	if(Root == NULL) {
		Root = (TreeNode *)malloc(sizeof(TreeNode));
		Root->Data = data;
		Root->Height = 0;
		Root->Left = Root->Right = NULL;
	}
	else if(data < Root->Data) {
		Root->Left = Insert(Root->Left, data);
		if(Height(Root->Left) - Height(Root->Right) == 2) {
			if(data < Root->Left->Data)
				Root = SingleRotateWithLeft(Root);
			else
				Root = DoubleRotateWithLeft(Root);
		}
	}
	else if(data > Root->Data) {
		Root->Right = Insert(Root->Right, data);
		if(Height(Root->Right) - Height(Root->Left) == 2) {
			if(data > Root->Right->Data)
				Root = SingleRotateWithRight(Root);
			else
				Root = DoubleRotateWithRight(Root);
		}
	}
	Root->Height = Max(Height(Root->Left), Height(Root->Right)) + 1;
	return Root;
}

TreeNode* Delete(TreeNode *Root, ElementType data)
{
	TreeNode *TempCell;
	if(Root == NULL) {
		printf("Element not found\n");
	}else if(data < Root->Data) {
		Root->Left = Delete(Root->Left, data);
	}else if(data > Root->Data) {
		Root->Right = Delete(Root->Right, data);
	}else if(Root->Left != NULL && Root->Right != NULL) {
		Root->Data = FindMin(Root->Right)->Data;
		Root->Right = DeleteMin(Root->Right);
	}else {
		TempCell = Root;
		if(Root->Left == NULL)
			Root = Root->Right;
		else if(Root->Right == NULL)
			Root = Root->Left;
		free(TempCell);
	}

	return Root;
}

//Print dependent the type of element.
void PrintElement(ElementType data)
{
	printf("%d ", data);
}

//In order, that is , print left child, parent, then right child.
void InOrderPrint(TreeNode *root)
{
	if(root->Left != NULL) {
		InOrderPrint(root->Left);
	}
	PrintElement(root->Data);
	printf("|");
	if(root->Right != NULL) {
		InOrderPrint(root->Right);
	}
}
/*
#define LengthQueue 20
TreeNode *queue[LengthQueue];
unsigned int head = 0;
unsigned int tail = 0;

void Enqueue(TreeNode *node)
{
	queue[(tail + 1) % LengthQueue] = node;
	tail = (tail + 1) % LengthQueue;
}

TreeNode *Unqueue()
{
	unsigned int pos = head;
	head = (head + 1) % LengthQueue;
	return queue[pos];
}

unsigned short IsQueueEmpty()
{
	if(head != tail)
		return 0;
	else
		return 1;
}
*/

unsigned int TreeHeigh(TreeNode *root)
{
	if(root == NULL)
		return 0;
	if(root->Left == NULL && root->Right == NULL)
		return 0;
	else {
		unsigned int heighLeft = TreeHeigh(root->Left);
		unsigned int heighRight = TreeHeigh(root->Right);
		return heighLeft > heighRight ? heighLeft : heighRight + 1;
	}
}
int Pow(int base, int e)
{
	int result = 1;
	while(e > 0) {
		result = result * base;
		e --;
	}
	return result;
}
#define NUM 100
void MakeTreeMap(int printM[NUM][NUM], TreeNode *root, int height, int pos)
{
	if(root == NULL)
		return ;
	printM[height][pos] = root->Data;
	//printf("%d %d %d\n", printM[height][pos], height, pos);
	if(height == 1)
	{
		MakeTreeMap(printM, root->Left, height - 1, pos - 1);
		MakeTreeMap(printM, root->Right, height - 1, pos + 1);
		return ;
	}
	MakeTreeMap(printM, root->Left, height - 1, pos - Pow(2, height - 1));
	MakeTreeMap(printM, root->Right, height - 1, pos + Pow(2, height - 1));
}
void PrintTree(TreeNode *root)
{
	int printM[NUM][NUM];
	int i, j;
	for(i = 0; i < NUM; i++) 
		for(j = 0; j < NUM; j++)
			printM[i][j] = -1;
	int heigh = TreeHeigh(root);
	MakeTreeMap(printM, root, heigh, Pow(2, heigh));
	for(i = heigh + 1; i >= 0; i--) {
		for(j = 0; j < NUM; j++) {
			if(printM[i][j] == -1)
				printf(" ");
			else
				printf("%d", printM[i][j]);
		}
		printf("\n\n");
	}
}
int main(void)
{
	TreeNode *Root = NULL;
	Root = Insert(Root, 6);
	PrintTree(Root);
	Root = Insert(Root, 4);
	PrintTree(Root);
	Root = Insert(Root, 9);
	PrintTree(Root);
	Root = Insert(Root, 10);
	PrintTree(Root);
	Root = Insert(Root, 13);
	PrintTree(Root);
	Root = Insert(Root, 5);
	PrintTree(Root);
	Root = Insert(Root, 8);
	PrintTree(Root);
	Root = Insert(Root, 12);
	PrintTree(Root);
	Root = Insert(Root, 0);
	PrintTree(Root);

	PrintTree(Root);

	printf("6 9 10 13 5 8 12 0\n");
	printf("Pre Order: ");
	InOrderPrint(Root);
	printf("\n");

	printf("Max: ");
	PrintElement(FindMax(Root)->Data);
	printf("\n");
	printf("Min: ");
	PrintElement(FindMin(Root)->Data);
	printf("\n");

	Root = Delete(Root, 13);
	printf("Pre Order: ");
	InOrderPrint(Root);
	printf("\n");

	PrintTree(Root);
	printf("Tree Heigh: %u\n", TreeHeigh(Root));
	exit(EXIT_SUCCESS);
}
