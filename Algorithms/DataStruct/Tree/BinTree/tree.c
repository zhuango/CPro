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

void preorder(node *root)
{
	if(root == NULL) return;

	printf("%c", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(node *root)
{
	if(root == NULL) return;
	inorder(root->left);
	printf("%c", root->data);
	inorder(root->right);
}

void postorder(node *root)
{
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%c", root->data);
}

#define MAX 100
node *queue[MAX];
int head = 0, tail = 0;

int levorder(node *root)
{
	int WholeTree = 1, i;
	node *tmp;
	queue[tail] = root;
	tail = (tail++) % (MAX - 1);
	while(head != tail) {
		tmp = queue[head];
		head = (head + 1) % (MAX - 1);
		printf("%c", tmp->data);
		/* left and right child in the queue */
		if(tmp->left != NULL) {
			queue[tail] = tmp->left;
			tail = (tail + 1) % (MAX - 1);
		}
		if(tmp->right != NULL) {
			queue[tail] = tmp->right;
			tail = (tail + 1) % (MAX - 1);
		}
		/* Whole Tree? */	
		if(tmp->right != NULL && tmp->left == NULL) WholeTree = 0;
		if(tmp->right == NULL && tmp->left != NULL) {
			i = head;
			while(i != tail) {
				if(queue[i]->right != NULL || queue[i]->left != NULL)
				       	WholeTree = 0;
				i = (i + 1)  % (MAX - 1);
			}
		}
	}

	return WholeTree;
}

int stack[MAX];
int shead = 0;
int stail = 0;
int longest[MAX];
int longsize = 0;
void Longest(node *root)
{
	int i, j;
	if(root->left == NULL && root->right == NULL){
		
		if(longsize < stail - shead + 1) {
			for(i = shead, j = 0; i < stail; i++, j++){
				longest[j] = stack[i];
			}
			longsize = stail - shead + 1;
			longest[j] = root->data;
		}
		
		/*
		printf("%c: ", root->data);
		for(i = shead, j = 0; i < stail; i++, j++){
			printf("%c", stack[i]);
		}
		printf("%c", root->data);
		printf("\n");
		*/
		return ;
	}
	if(root->left != NULL){
		stack[stail] = root->data;
		stail ++ ;
		Longest(root->left);
		stail --;
	}
	if(root->right != NULL) {
	       	stack[stail] = root->data;
	       	stail ++ ;
		Longest(root->right);
		stail --;
	}
}

int issame(node *root, node *root1)
{
	int ret;
	if(root == NULL && root1 == NULL) {ret = 1; return ret;}
	else if (root != NULL && root1 != NULL){
		ret = issame(root->left, root1->left);
		if(ret == 0) {return 0;}
		ret = issame(root->right, root1->right);
		return ret;
	}else  return 0;
}
int main(void)
{
	node *root, *root2;
	int t;

	root = CreateBinTree('#');
	preorder(root);
	printf("\n");
	
	inorder(root);
	printf("\n");
	
	postorder(root);
	printf("\n");

	t = levorder(root);
	printf("\nroot is Whole Tree? : %d\n", t);

	Longest(root);
	printf("Longest : ");
	for(t = 0; t < longsize; t++)
		printf("%c", longest[t]);
	printf("\n");

	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	while(getchar() != '\n') {}	
	root2 = CreateBinTree('#');
	
	preorder(root2);
	printf("\n");
	
	inorder(root2);
	printf("\n");
	
	postorder(root2);
	printf("\n");

	t = levorder(root2);
	printf("\nroot2 Is Whole Tree? : %d\n", t);
	
	Longest(root2);
	printf("Longest : ");
	for(t = 0; t < longsize; t++)
		printf("%c", longest[t]);
	printf("\n");

	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("root is same as root2? : %d\n", issame(root, root2));
	
	exit(EXIT_SUCCESS);
}

