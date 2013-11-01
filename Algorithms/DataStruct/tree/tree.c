#include<stdio.h>
#include<stdlib.h>

typedef struct Tree{
	int data;
	struct Tree *right;
	struct Tree *left;
	struct Tree *pare;
}Tree;

Tree *insert(Tree *root, int num)
{
	Tree *new, *a = root, *b = NULL;
	/* Init the new element */
	new = malloc(sizeof(Tree));
	new->data = num;
	new->pare = NULL;
	new->left = NULL;
	new->right = NULL;
	/* Find the position */
	while(a != NULL){
		b = a;/* Remeber the father */
		if(new->data > a->data)
			a = a->right;/* In the right */
		else
			a = a->left;/* In the left */
	}

	new->pare = b;/* Set the father for new */

	if(b == NULL)/* Empty tree? */
		root = new;
	else if(new->data > b->data)/* Set right as new */
		b->right = new;
	else
		b->left = new;/* Set left as new */

	return (root);
}

Tree *min_tree(Tree *root)
{
	Tree *index = root;
	while(index->left != NULL)/* Find the most left node */
		index = index->left;

	return index;
}

Tree *max_tree(Tree *root)
{
	Tree *index = root;
	while(index->right != NULL)
		index = index->right;/* Find the most right node */

	return index;
}

Tree *next_tree(Tree *pos)
{
	Tree *index = pos;
	Tree *ret;
	if(index->right != NULL)/* Has right child tree */
		return (min_tree(index->right));

	/* Do not have the right tree */
	ret = index->pare;
	while(ret != NULL && index == ret->right){/* Fathers's left child is this child*/
		index = ret;
		ret = ret->pare;
	}

	return ret;
}

Tree *search_tree(Tree *root, int num)
{
	Tree *index = root;
	while(index != NULL && index->data != num){
		if(num > index->data)
			index = index->right;/* In the right child tree */
		else
			index = index->left;/* In the left child tree */
	}

	if(index == NULL)/* Do not find this node */
		printf("can not find the node!\n");
	return index;
}

Tree *del(Tree *root, Tree *node)
{
	Tree *a = NULL, *b = NULL;

	/* Find node that would be delete */
	if(node->left == NULL || node->right == NULL)/* Has one child OR has no child */
		a = node;
	else
		a = next_tree(node);/* Have Two child */

	/* Set the "b" as the not_NULL_child of "a" */
	if(a->left == NULL)
		b = a->right;
	else
		b = a->left;

	if(b != NULL)/* Has one child */
		b->pare =a->pare;
	if(a->pare == NULL)/* "a" is the root node */
		root = b;
	else if(a == a->pare->right)
		a->pare->right = b;/* "a" is his father's right child */
	else 
		a->pare->left = b;/* "a" is his father's left child */

	if(a != node)/* Node be delete is "node"'s next? */
		node->data = a->data;/* Swap the data */
		/* Swap the data */

	return root;
}

void mid_tree(Tree *root)
{
	if(root != NULL){
		mid_tree(root->left);/* Print left */
		printf("%d ", root->data);/* Print father */
		mid_tree(root->right);/* Print right */
	}
}
void mid_walk_tree(Tree *root)
{
	mid_tree(root);
	printf("\n");
}


int main(void)
{
	Tree *root = NULL;
	Tree *index;
	int i;

	/* Insert 10 */
	printf("Insert 10:\n");
	for(i = 0; i < 10; i++)
		root = insert(root, i);
	mid_walk_tree(root);

	/* MAX */
	index = max_tree(root);
	printf("MAX: %d\n", index->data);

	/* MIN */
	index = min_tree(root);
	printf("MIN: %d\n", index->data);

	/* Search */
	index = search_tree(root, 5);
	printf("Find (5): %d\n", index->data);

	/* Next */
	index = next_tree(index);
	printf("Find(5) next : %d\n", index->data);

	/* Delete the node */
	printf("Delete (6):\n");
	root = del(root, index);
	mid_walk_tree(root);

	exit(EXIT_SUCCESS);
}
