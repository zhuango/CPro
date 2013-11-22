#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *father, *left, *right;
}node;

node *CreateBinTree(char tostop)
{
	char ch;
	node *t;

	scanf("%c", &ch);
	if(ch == tostop) {t = NULL; return t;}
	else { t = malloc(sizeof(node)); t->data = ch;}

	t->left = CreateBinTree(tostop);
	if(t->left != NULL) {t->left->father = t;}

	t->right = CreateBinTree(tostop);
	if(t->right != NULL) {t->right->father = t;}

	return t;

}

void PreOrder(node *root)
{
	if(root == NULL) return ;
	printf("%c ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

int edge = 0;
void EdgeCount(node *root)
{
	if(root == NULL) return ;
	else edge = edge + 1;
	EdgeCount(root->left);
	EdgeCount(root->right);
}

node *Find(node *root, char item)
{
	node *tmp;
	/* Empty tree */
	if(root == NULL) return NULL;
	/* Find it */
	if(root->data == item) return root;
	/* Not find , then goto children */
	if( (tmp = Find(root->left, item)) != NULL) return tmp;
	return Find(root->right, item);
}
node *father(node *root, node *n)
{
	node *tmp;
	/* Root node has no father */
	if(root == NULL) return NULL;
	/* left child Or right child */
	if(root->left == n || root->right == n) return root;
	/* goto the children */
	if( (tmp = father(root->left, n)) != NULL) return tmp;
	return father(root->right, n);
}

void Del(node *dnode)
{
	if(dnode == NULL) return ;
	Del(dnode->left) ;
	Del(dnode->right) ;
	free(dnode);
}
node *DelSubTree(node *root, node *dnode)
{
	node *papa;
	/* Empty tree, no deleting */
	if(dnode == NULL) return root;
	/* Delete root */
	if(dnode == root) {
		Del(root);
		return NULL;
	}
	/* not the root node, then must have father */
	papa = father(root, dnode);
	/* Reset father's info */
	if(papa->left == dnode) papa->left = NULL;
	else  papa->right = NULL;
	/* Delete */
	Del(dnode);
	return root;
}
int main(void)
{
	node *root;
	node *tmp;
	root = CreateBinTree('#');

	printf("PreOrder: ");
	PreOrder(root);
	printf("\n");
	
	EdgeCount(root);
	printf("Edge : %d\n", edge);

	if( (tmp = father(root, root)) == NULL)
		printf("\"%c\" is root, have no father\n", root->data);
	else
		printf("\"%c\"'s father is \"%c\"\n", tmp->data, tmp->data);

	node *b = Find(root, 'B');
	if( (tmp = father(root, b)) == NULL)
		printf("\"%c\" is root, have no father\n", root->data);
	else
		printf("\"%c\"'s father is \"%c\"\n", b->data, tmp->data);

	root = DelSubTree(root, b);
	printf("PreOrder: ");
	PreOrder(root);
	printf("\n");

	edge = 0;
	EdgeCount(root);
	printf("Edge : %d\n", edge);
}
