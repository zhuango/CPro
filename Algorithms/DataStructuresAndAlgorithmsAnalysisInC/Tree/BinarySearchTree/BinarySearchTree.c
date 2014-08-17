#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

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

//Binary tree's root is "Root", insert a element data
//return a inserted binary tree.
TreeNode *Insert(TreeNode *Root, ElementType data)
{
	//eventurely, insert to a NULL position.
	if(Root == NULL) {
		Root = (TreeNode *)malloc(sizeof(TreeNode));
		Root->Data = data;
		Root->Left = Root->Right = NULL;
	//Not a NULL, then find continuely.
	}else {
		if(data > Root->Data)
			Root->Right = Insert(Root->Right, data);
		else if(data < Root->Data)
			Root->Left = Insert(Root->Left, data);
	}

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

//Pre order, that is , print left child, parent, then right child.
void PreOrderPrint(TreeNode *root)
{
	if(root->Left != NULL)
		PreOrderPrint(root->Left);
	PrintElement(root->Data);
	if(root->Right != NULL)
		PreOrderPrint(root->Right);
}

int main(void)
{
	TreeNode *Root = NULL;
	Root = Insert(Root, 6);
	Root = Insert(Root, 4);
	Root = Insert(Root, 9);
	Root = Insert(Root, 10);
	Root = Insert(Root, 13);
	Root = Insert(Root, 5);
	Root = Insert(Root, 8);
	Root = Insert(Root, 12);
	Root = Insert(Root, 0);

	printf("6 9 10 13 5 8 12 0\n");
	printf("Pre Order: ");
	PreOrderPrint(Root);
	printf("\n");

	printf("Max: ");
	PrintElement(FindMax(Root)->Data);
	printf("\n");
	printf("Min: ");
	PrintElement(FindMin(Root)->Data);
	printf("\n");

	Root = Delete(Root, 13);
	printf("Pre Order: ");
	PreOrderPrint(Root);
	printf("\n");

	exit(EXIT_SUCCESS);
}
