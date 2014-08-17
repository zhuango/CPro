#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

typedef int ElementType;

typedef struct TreeNode
{
	ElementType Data;
	struct TreeNode *Left;
	struct TreeNode *Right;
	unsigned short Height;
}TreeNode;

#endif
