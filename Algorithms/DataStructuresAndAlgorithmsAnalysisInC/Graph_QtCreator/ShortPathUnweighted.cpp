#include "graph.h"
#include <queue>

#define INFINITY 0x8fffffff

void InitTable(Table table[], int tableSize)
{
	for(int i = 0; i < tableSize; i++)
	{
		table[i].Distance = INFINITY;
		table[i].Known = false;
		table[i].ParentNode = NULL;
	}
}


void ShortPathUnweighted(Table table[], Graph *graph, Node *startNode)
{
	UInt32 currentDistance;
	table[startNode->InternalNumber - 1].Distance = 0;
	for(currentDistance = 0; currentDistance < graph->Size; currentDistance++)
	{
		vector<Cell*>::iterator iter = graph->Cells.begin();
		for(;iter != graph->Cells.end(); iter++)
		{
			if(table[(*iter)->CurrentNode->InternalNumber - 1].Distance == currentDistance &&
					!table[(*iter)->CurrentNode->InternalNumber - 1].Known)
			{
				table[(*iter)->CurrentNode->InternalNumber - 1].Known = true;
				list<Node*>::iterator iterNode = (*iter)->Children.begin();
				for(;iterNode != (*iter)->Children.end(); iterNode++)
				{
					if(table[(*iterNode)->InternalNumber - 1].Distance == INFINITY)
					{
						table[(*iterNode)->InternalNumber - 1].Distance = currentDistance + 1;
						table[(*iterNode)->InternalNumber - 1].ParentNode =(*iter)->CurrentNode;
					}
				}
			}
		}
	}
}

void ShortPathUnweightedV2(Table table[], Graph *graph, Node *startNode)
{
	table[startNode->InternalNumber - 1].Distance = 0;
	table[startNode->InternalNumber - 1].ParentNode = NULL;
	queue<Cell*> q;
	q.push(graph->Cells[startNode->InternalNumber - 1]);

	while(!q.empty())
	{
		Cell *cell = q.front();
		q.pop();

		list<Node*>::iterator nodeIter = cell->Children.begin();
		for(;nodeIter != cell->Children.end(); nodeIter ++)
		{
			if(table[(*nodeIter)->InternalNumber - 1].Distance == INFINITY)
			{
				table[(*nodeIter)->InternalNumber - 1].Distance = table[cell->CurrentNode->InternalNumber - 1].Distance + 1;
				table[(*nodeIter)->InternalNumber - 1].ParentNode = cell->CurrentNode;
				q.push(graph->Cells[(*nodeIter)->InternalNumber - 1]);
			}
		}
	}
}
