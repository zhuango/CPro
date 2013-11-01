#include <stdio.h>
#include <malloc.h>
#include "Status.h"
typedef struct
{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
} HTNode, *HuffmanTree;
typedef char **HuffmanCode;
void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC, int * w, int n);

