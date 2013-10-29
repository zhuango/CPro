#include "HuffmanTree.h"

int Min(HuffmanTree t,int i)
{
	int j,m;
	unsigned int k = UINT_MAX;
	for (j = 1; j<= i; ++j)
	{
		if (t[j].weight < k && t[j].parent == 0)
		{
			k = t[j].weight;
			m = j;
		}
	}
	t[m].parent = 1;
	return m;
}

void Select(HuffmanTree t, int i, int&s1, int&s2)
{
#ifdef order
	int j ;
#endif
	s1 = Min(t,i);
	s2 = Min(t,i);
#ifdef order
	if (s1 > s2)
	{
		j = s1;
		s1 = s2;
		s2 = j;
	}
#endif
}

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC, int * w, int n)
{
	int m,i,s1,s2;
	unsigned c; 
	HuffmanTree p;
	char *cd;
	if (n <= 1)
	{
		return;
	}
	m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	for (p = HT + 1, i = 1; i <= n;++i,++p,++w)
	{
		(*p).weight = *w;
		(*p).parent = 0;
		(*p).rchild = 0;
		(*p).lchild = 0;
	}
	for(;i <= m;++i,++p)
	{
		(*p).parent = 0;
	}

	for(i = n + 1;i <= m; ++i)
	{
		Select(HT,i - 1,s1,s2);
		HT[s1].parent = HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
/*********************************************************************/
	int start;
	unsigned f;
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));
	cd = (char*)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	for(i = 1;i <= n;++i)
	{
		start = n - 1;
		for(c = i,f = HT[i].parent;f != 0;c = f,f = HT[f].parent)
		{
			if (HT[f].lchild == c)
			{
				cd[--start] = '0';
			}
			else
			{
				cd[--start] = '1';
			}
			HC[i] = (char *)malloc((n - start)*sizeof(char));
			strcpy(HC[i],&cd[start]);
		}
	}
	free(cd);
}