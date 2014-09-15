#include "PriorityQueue/BinaryHeap.h"
#include "graph.h"
#include <stack>
#include <queue>
#include "DisjSet/DisjSet.h"

void InintTable(Index start, Graph *g, TableInstance t, int sizeOfTable)
{
	for(int i = 0; i < sizeOfTable; i++)
	{
		t[i].Known = false;
		t[i].Distance = Infinity;
		if(i > 0 && i <= g->Cells.size())
		{
			t[i].CurrentNode = g->Cells[i - 1]->CurrentNode;
		}
        t[i].ParentNode = NULL;
	}
	t[start].Distance = 0;
}

void PrintPath(Index destNode, TableInstance t)
{
	stack<Node*> pathStack;
	Table *tableEntry = &t[destNode];

	while(tableEntry->ParentNode->InternalNumber != NotAVertex)
	{
		pathStack.push(tableEntry->ParentNode);
		tableEntry = &t[tableEntry->ParentNode->InternalNumber];
	}
}

void InitializeVertextQueue(PriorityQueue priorityQueue, TableInstance t, UInt32 tableNumber)
{
    for(UInt32 i = 1; i < tableNumber; i++)
	{
		Insert(t[i], priorityQueue);
	}
}
void Dijkstra(Graph *g, Index start, TableInstance t)
{
	Node *v;

	PriorityQueue priorityQueue = Initialize(g->Size * 3);
    InitializeVertextQueue(priorityQueue, t, g->Cells.size());
	for(;;)
	{
		do{
			v = DeleteMin(priorityQueue).CurrentNode;
			if(v->InternalNumber == NotAVertex)
				break;
		}while(t[v->InternalNumber].Known);

		if(v->InternalNumber == NotAVertex || t[v->InternalNumber].Known)
			break;
		t[v->InternalNumber].Known = true;
		list<Node*>::iterator iter = g->Cells[v->InternalNumber - 1]->Children.begin();
		for(;iter != g->Cells[v->InternalNumber - 1]->Children.end(); iter ++)
		{
			if(!t[(*iter)->InternalNumber].Known)
			{
				if(t[(*iter)->InternalNumber].Distance > (*iter)->weight + t[v->InternalNumber].Distance)
				{
					t[(*iter)->InternalNumber].Distance = (*iter)->weight + t[v->InternalNumber].Distance;
					t[(*iter)->InternalNumber].ParentNode = v;
					Insert(t[(*iter)->InternalNumber], priorityQueue);
				}
			}
		}
	}
}

void WeightedNegative(Graph *g, TableInstance t, Index start)
{
	queue<Node *> queue;
	queue.push(g->Cells[start - 1]->CurrentNode);
	while(!queue.empty())
	{
		Node* currentNode = queue.front();
		queue.pop();
		list<Node*>::iterator iter = g->Cells[currentNode->InternalNumber - 1]->Children.begin();
		for(; iter != g->Cells[currentNode->InternalNumber - 1]->Children.end(); iter ++)
		{
				if(t[(*iter)->InternalNumber].Distance > (*iter)->weight + t[currentNode->InternalNumber].Distance)
				{
					t[(*iter)->InternalNumber].Distance = (*iter)->weight + t[currentNode->InternalNumber].Distance;
					t[(*iter)->InternalNumber].ParentNode = currentNode;
					queue.push(*iter);
				}
		}
	}
}


void Prim(Graph *g, TableInstance t, Index start)
{
    Node *v;

    PriorityQueue priorityQueue = Initialize(g->Size * 3);
    InitializeVertextQueue(priorityQueue, t, g->Cells.size());
    for(;;)
    {
        do{
            v = DeleteMin(priorityQueue).CurrentNode;
            if(v->InternalNumber == NotAVertex)
                break;
        }while(t[v->InternalNumber].Known);

        if(v->InternalNumber == NotAVertex)
            break;
        t[v->InternalNumber].Known = true;
        list<Node*>::iterator iter = g->Cells[v->InternalNumber - 1]->Children.begin();
        for(;iter != g->Cells[v->InternalNumber - 1]->Children.end(); iter ++)
        {
            if(!t[(*iter)->InternalNumber].Known)
            {
                if(t[(*iter)->InternalNumber].Distance > (*iter)->weight)
                {
                    t[(*iter)->InternalNumber].Distance = (*iter)->weight;
                    t[(*iter)->InternalNumber].ParentNode = v;
                    Insert(t[(*iter)->InternalNumber], priorityQueue);
                }
            }
        }
    }
    delete[] priorityQueue->Elements;
}

void InitializeTableForKruskal(Graph *g, TableInstance t)
{
    int counter = 1;
    vector<Cell*>::iterator iter = g->Cells.begin();
    for(;iter != g->Cells.end(); iter++)
    {
        list<Node *>::iterator iterNode = (*iter)->Children.begin();
        for(;iterNode != (*iter)->Children.end(); iterNode ++)
        {
            t[counter].ParentNode = (*iter)->CurrentNode;
            t[counter].CurrentNode = (*iterNode);
            t[counter].Distance = (*iterNode)->weight;
            counter ++;
        }
    }
}

void Kruskal(Graph *g, TableInstance t, list<Edge> &edgeList)
{
    Node *v;
    int edgeAccepted = 0;
    DisjSet disjSet = new SetType[g->Cells.size()];

    InitializeDisjSet(disjSet, g->Cells.size());
    PriorityQueue priorityQueue = Initialize(g->Size * 3);
    InitializeVertextQueue(priorityQueue, t, g->EdgeNumber);
    while(edgeAccepted < g->Cells.size() - 1)
    {
        Table edge = DeleteMin(priorityQueue);
        SetType set1 = FindInDisjSet(edge.CurrentNode->InternalNumber, disjSet);
        SetType set2 = FindInDisjSet(edge.ParentNode->InternalNumber, disjSet);
        if(set1 != set2)
        {
            SetUnion(disjSet, set1, set2);
            edgeList.push_back(Edge{edge.CurrentNode->RealName, edge.ParentNode->RealName, edge.Distance});
            edgeAccepted ++;
        }
    }
    delete[] disjSet;
}
