#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node *left, *right;
	char info;
	int weight;
}node;

node *huffman(node **H, int m)
{
	node *p, *p1, *p2, *t;
	int i, j;

	for(i = 1; i < m + 1; i++) {
		H[i]->left = NULL;
		H[i]->right= NULL;
	}

	for(i = 1; i < m; i++) {
		t = malloc(sizeof(node));
		p1 = H[i];
		p2 = H[i + 1];

		t->weight = p1->weight + p2->weight;
		t->left = p1;
		t->right = p2;
		p = t;

		j = i + 2;
		while(H[j]->weight < p->weight && j <= m) {
			H[j - 1] = H[j];
			j++;
		}

		H[j - 1] = p;
	}

	return t;
}

void tran(node *root)
{
	char ch;
	node *tmp = root;

	while( (ch = getchar()) != '\n') {
		if(ch == '1')
			tmp = tmp->right;
		else
			tmp = tmp->left;

		if(tmp->left == NULL && tmp->right == NULL) {
			printf("%c", tmp->info);
			tmp = root;
		}
	}
}

int stack[5];
int head = 0;
int tail = 0;
void printnode(node *root)
{
	int i;
	if(root->left == NULL && root->right == NULL){
		printf("%c: ", root->info);
		for(i = head; i < tail; i++)
			printf("%d", stack[i]);
		printf("\n");
		return ;
	}
	if(root->left != NULL){
		stack[tail] = 0;
		tail ++ ;
		printnode(root->left);
		tail --;
	}
	if(root->right != NULL) {
	       	stack[tail] = 1;
	       	tail ++ ;
		printnode(root->right);
		tail --;
	}
}
void ininode(node *t, char info, int weight)
{
	t->info = info;
	t->weight = weight;
}
int main()
{
	node *H[6];
	node *root, *tmp;
	int i;
//	for(i = 1; i < 6; i++) {
		tmp = malloc(sizeof(node));
		H[1] = tmp;
		ininode(H[1], 'a', 1);
		tmp = malloc(sizeof(node));
		H[2] = tmp;
		ininode(H[2], 'd', 2);
		tmp = malloc(sizeof(node));
		H[3] = tmp;
		ininode(H[3], 'b', 3);
		tmp = malloc(sizeof(node));
		H[4] = tmp;
		ininode(H[4], 'e', 4);
		tmp = malloc(sizeof(node));
		H[5] = tmp;
		ininode(H[5], 'c', 5);
//	}

	root = huffman(H, 5);
	printnode(root);
	tran(root);

	exit(EXIT_SUCCESS);
}
