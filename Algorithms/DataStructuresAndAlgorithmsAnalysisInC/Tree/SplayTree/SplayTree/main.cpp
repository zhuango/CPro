#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "SplayTree.h"

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

static TreeNode *SingleRotateWithRight(TreeNode *heigh)
{
    TreeNode *low;

    low = heigh->Right;
    heigh->Right = low->Left;
    low->Left = heigh;

    return low;
}

static TreeNode *SingleRotateWithLeft(TreeNode *heigh)
{
    TreeNode *low;

    low = heigh->Left;
    heigh->Left = low->Right;
    low->Right = heigh;

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

TreeNode* Find(TreeNode *root, ElementType data)
{
    if(root->Data == data)
    {
        return root;
    }

    if(data > root->Data)
    {
        if()
    }
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
