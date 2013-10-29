#include "Status.h"
#include "Struct_LinkQueue.h"
#include "Basic_called_functions.h"

int main()
{
	Status i;
	LinkQueue Q;
	QElemType e,e0;

	InitQueue(Q);
	printf("成功的构造了空队列！\n");
	printf("是否空队列？%d(1:空 0：否)\n",IsQueueEmpty(Q));
	printf("队列的长度为%d\n",QueueLength(Q));
	EnQueue(Q,-5);
	EnQueue(Q,5);
	EnQueue(Q,10);
	printf("插入三个元素（-5,5,10）后，队列的长度为%d\n",QueueLength(Q));
	printf("是否空队列？%d(1:空 0：否)\n",IsQueueEmpty(Q));
    printf("队列的元素依次为：");
	QueueTraverse(Q,print);

	i = GetHead(Q,e);
	if (i == OK)
	{
		printf("队头元素是%d\n",e);
	}

	DelQueue(Q,e);
	printf("删除了队头元素%d\n",e);

	i = GetHead(Q,e);
	if (i == OK)
	{
		printf("新的队头元素是%d\n",e);
	}

	ClearQueue(Q);
	printf("清空队列后，Q.front=%u,Q.rear=%u,Q.front->next=%u\n",Q.front,Q.rear,Q.front->next);
	printf("是否空队列？%d(1:空 0：否)\n",IsQueueEmpty(Q));

	DestroyQueue(Q);
	printf("销毁队列后，Q.front=%u,Q.rear=%u\n",Q.front,Q.rear);

	return 0;
}

/*在VC++6.0中的输出结果为：
------------------------------------------------------------------------------------
成功的构造了空队列！
是否空队列？1(1:空 0：否)
队列的长度为0
插入三个元素（-5,5,10）后，队列的长度为3
是否空队列？0(1:空 0：否)
队列的元素依次为：-5  5  10
队头元素是-5
删除了队头元素-5
新的队头元素是5
清空队列后，Q.front=4986016,Q.rear=4986016,Q.front->next=0
是否空队列？1(1:空 0：否)
销毁队列后，Q.front=0,Q.rear=0
请按任意键继续. . .
------------------------------------------------------------------------------------
我的程序员之路：路漫漫其修远兮，吾将上下而求索！
*/
