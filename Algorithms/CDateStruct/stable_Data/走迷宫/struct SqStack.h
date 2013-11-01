#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 2

struct SqStack
{
	SElemType *base;
	SElemType *top;
	int stacksize;
};