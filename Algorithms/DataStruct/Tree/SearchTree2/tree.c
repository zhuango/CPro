#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *father, *left, *right;
	int Rpthread, Lpthread;
}node ;

/* the leftest node is the first node of tree */
node *FIO(node *t)
{
	node *q;
	q = t;

	while(q->Lpthread == 0) q = q->left;
	return q;
}
/* The rightest node is the last node of tree */
node *LIO(node *t)
{
	node *q;
	q = t;

	while(q->Rpthread == 0) q = q->right;
	return q;
}

void InsertR(node *p, node *s)
{
	node *tmp;

	p->right = s->right;
	p->Rpthread = s->Rpthread;
	p->left = s, p->Lpthread = 1;

	if(s->Rpthread == 1) {/* Right child tree is NULL */
		s->right = p;
		s->Rpthread = 0;
		return;
	} else if(s->Rpthread == 0)/* Right child tree is not NULL */
		tmp = FIO(s->right);/* p is the prenode of the first of s's right child tree */
	tmp->left = p;
	s->right = p;
	return ;
}

void InsertL(node *p, node *s)
{
	node *tmp;

	p->left = s->left;
	p->Lpthread = s->Lpthread;
	p->right = s;
	p->Rpthread = 1;

	if(s->Lpthread == 1) {/* Left child tree is NULL */
		s->left = p;
		s->Lpthread = 0;
		return ;
	}else if(s->Lpthread == 0)/* Right child tree is not NULL */
		tmp = LIO(s->left);/* pis the prenode of the first of s's right child tree */
	tmp->right = p;
	s->left = p;
	return ;
}

void DeleteR(node *t)
{
	node *tmp, *tmp1;
	node *p = t->right;

	if(p == NULL) return;
	if(p->Lpthread == 1 && p->Rpthread == 1) {/* Has no child */
		t->right = p->right;
		t->Rpthread = 1;
		return ;
	}
	if(p->Lpthread == 1 && p->Rpthread == 0) {/* Has right child */
		t->right = p->right;
		tmp = FIO(p->right);
		tmp->left = t;
		return ;
	}
	if(p->Lpthread == 0 && p->Rpthread == 1) {/* Has left child */
		t->right = p->left;
		tmp = LIO(p->left);
		tmp->right = t;
		return ;
	}
	if(p->Lpthread == 0 && p->Rpthread == 0) {/* Has both left and right */
		tmp = LIO(p->left);
		tmp1 = FIO(p->right);

		tmp->right = p->right;
		tmp->Rpthread = 0;
		t->right = p->left;
		tmp1->left = tmp;
		return;
	}
}

void DeleteL(node *t)
{
	node *tmp, *tmp1;
	node *p = t->left;

	if(p == NULL) return;

	if(p->Lpthread == 1 && p->Rpthread == 1) {/* Has no child */
		t->left = p->left;
		t->Lpthread = 1;
		return ;
	}
	if(p->Lpthread == 1 && p->Rpthread == 0) {/* Has right child */
		t->left = p->right;
		tmp = FIO(p->right);
		tmp->left = t;
		return ;
	}
	if(p->Lpthread == 0 && p->Rpthread == 1) {/* Has left child */
		t->left = p->left;
		tmp = LIO(p->left);
		tmp->right = t;
		return ;
	}
	if(p->Lpthread == 0 && p->Rpthread == 0) {/* Has both left and right */
		tmp = LIO(p->left);
		tmp1 = FIO(p->right);
		tmp->right = p->right;
		tmp->Rpthread = 0;
		t->left = p->left;
		tmp1->left = tmp;
		return ;
	}
}
node *PIO(node *t, node *p)
{
	node *first;
	first = FIO(t);

	if(first == p) return NULL;
	if(p->Lpthread == 1) return p->left;/* Has no left node */
	else if(p->Lpthread == 0) return LIO(p->left);/* Last node of left tree */
}

node *NIO(node *t, node *p)
{
	node *last;
	last = LIO(t);

	if(last == p) return NULL;
	if(p->Rpthread == 1) return p->right;/* Has no right node */
	else if(p->Rpthread == 0) return FIO(p->right);/* First node of right tree */
}

void Inorder(node *t)
{
	node *first;
	first = FIO(t);
	while(first != NULL) {
		printf("%d ", first->data);
		first = NIO(t, first);
	}
}

void Ininode(node *root)
{
	root->data = 0;
	root->Lpthread = 1;
	root->Rpthread = 1;
	root->left = NULL;
	root->father = NULL;
	root->right = NULL;
}
int main()
{
	int i;
	node *tmp;
	node *root = malloc(sizeof(node));
	Ininode(root);
	for(i = 0; i < 3; i++) {
		tmp = malloc(sizeof(node));
		tmp->data = i;
		InsertR(tmp, root);
		tmp = malloc(sizeof(node));
		tmp->data = i + 1;
		InsertL(tmp, root->right);
	}
	Inorder(root);/* Middle root go through */
	printf("\n");

	DeleteR(root);/* Delete root's right node */
	Inorder(root);
	printf("\n");

	DeleteL(root->right->right);/* Delete ......you know */
	Inorder(root);
	printf("\n");

	DeleteR(root->right->right);
	Inorder(root);
	printf("\n");

	for(i = 3; i < 6; i++) {
		tmp = malloc(sizeof(node));
		tmp->data = i ;
		InsertL(tmp, root);
		tmp = malloc(sizeof(node));
		tmp->data = i + 1;
		InsertR(tmp, root->left);
	}
	Inorder(root);/* Middle root go through */
	printf("\n");
	
	DeleteL(root);/* delete root's right */
	Inorder(root);
	printf("\n");

	DeleteR(root->left->left);/* Delete ......you know */
	Inorder(root); 
	printf("\n");

	DeleteL(root->left->left);
	Inorder(root);
	printf("\n");

	DeleteR(root->left->right);
	Inorder(root);
	printf("\n");
	
	exit(EXIT_SUCCESS);
}
