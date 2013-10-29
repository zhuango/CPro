#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN 256
typedef struct Tnode {
	int have_value;
	int v;
	struct Tnode *left, *right;
}Node;

Node *root;
int failed;
char s[MAXN + 10];
void addnode(int v, char *s);
Node *newnode();

int read_input()
{
	failed = 0;
	root = newnode();
	for(;;) {
		if(scanf("%s", s) != 1) return 0;
		if(!strcmp(s, "()")) break;

		int v;
		sscanf(&s[1], "%d", &v);
		addnode(v, strchr(s, ',') + 1);
	}

	return 1;
}

Node *newnode()
{
	Node * u = (Node*)malloc(sizeof(Node));
	
	if(u != NULL) {
		u->have_value = 0;
		u->left = NULL;
		u->right = NULL;
	}
	return u;
}

void addnode(int v, char *s)
{
	int n = strlen(s);
	Node *u = root;
	int i;
	
	for(i = 0; i < n; i++)
		if(s[i] == 'L') {
			if(u->left == NULL) u->left = newnode();
			u = u->left;
		}else if(s[i] == 'R') {
			if(u->right == NULL) u->right = newnode();
			u = u->right;
		}

	if(u->have_value) failed = 1;
	u->v = v;
	u->have_value = 1;
}

int n = 0, ans[MAXN];
int bfs()
{
	int front = 0, rear = 1;
	Node *q[MAXN];

	q[0] = root;

	while(front < rear) {
		Node *u = q[front++];
		if(!u->have_value) return 0;

		ans[n++] = u->v;
		if(u->left != NULL) q[rear++] = u->left;
		if(u->right != NULL) q[rear++] = u->right;
	}
	return 1;
}

int main()
{
	int i;
	while(1) {
		if(read_input() == 0) {continue;}
		if(bfs() == 1) {
			for(i = 0; i < n; i++) 
				printf("%d ", ans[i]);
			printf("\n");
		}else
			printf("-1\n");
	}
	exit(EXIT_SUCCESS);
}
