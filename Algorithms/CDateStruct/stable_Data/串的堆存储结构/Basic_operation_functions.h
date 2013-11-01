void InitString(HString &S)//³õÊ¼»¯×Ö·û´®S
{
	S.ch = NULL;
	S.length = 0;
}

void ClearString(HString &S)//½«SÇå¿Õ
{
	free(S.ch);
	S.ch = NULL;
	S.length = 0;
}

void StrAssign(HString &S,char *chars)//·ÖÅä´®³£Á¿
{
	int i,j;

	if (S.ch)
	{
		free(S.ch);
	}

	i = strlen(chars);
	if (!i)
	{
		InitString(S);
	}
	else
	{
		if (!(S.ch = (char*)malloc(i * sizeof(char))))
		{
			exit (OVERFLOW);
		}
		for (j = 0; j < i; j++)
		{
			S.ch[j] = chars[j];
		}
		S.length = i;
	}
}

void StrCopy(HString &S,HString T)//×Ö·û´®¸´ÖÆ
{
	int i;
	if (S.ch)
	{
		free(S.ch);
	}
	if (!T.ch)
	{
		InitString(S);
	}
	else
	{
		if (!(S.ch = (char*)malloc(T.length * sizeof(char))))
		{
			exit (OVERFLOW);
		}

		for (i = 0; i < T.length; i++)
		{
			S.ch[i] = T.ch[i];
		}
		S.length = T.length;
	}
}

Status StrEmpty(HString S)//×Ö·û´®ÅÐ¿Õ
{
	if (S.ch&&S.length)
	{
		return FALSE ;
	}
	else
	{
		return TRUE;
	}
}

int StrCompare(HString S, HString T)//×Ö·û´®±È½Ï
{
	int i;

	for (i = 0; i < S.length && i < T.length; i++)
	{
		if (S.ch[i] != T.ch[i])
		{
			return S.ch[i] - T.ch[i];
		}
	}
	return S.length - T.length;	
}

int StrLength(HString S)
{
	return S.length;
}

void Concat(HString &S,HString S1,HString S2)//×Ö·û´®Á¬½Ó
{
	int i;
	if (S.ch)
	{
		free(S.ch);
	}
	S.length = S1.length + S2.length;
	if (!(S.ch = (char*)malloc(S.length * sizeof(char))))
	{
		exit(OVERFLOW);
	}
	for (i = 0; i < S1.length; i++)
	{
		S.ch[i] = S1.ch[i];
	}
	for (i = 0; i < S2.length; i++)
	{
		S.ch[S1.length + i] = S2.ch[i];
	}
}

Status SubString(HString &Sub, HString S, int pos, int len)
{
	int i;
	if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1)
	{
		return ERROR;
	}
	if (Sub.ch)
	{
		free(Sub.ch);
	}
	if (!len)
	{
		InitString(Sub);
	}
	else
	{
		if (!(Sub.ch = (char*)malloc(len * sizeof(char))))
		{
			exit(OVERFLOW);
		}
		for (i = 0;i <= len - 1; i++)
		{
			Sub.ch[i] = S.ch[pos - 1 + i];
		}
		Sub.length = len;
	}
	return OK;
}

Status StrInsert(HString &S, int pos, HString T)
{
	int i;
	if (pos < 1 || pos > S.length + 1)
	{
		return ERROR;
	}
	if (!StrEmpty(T))
	{
		if (!(S.ch = (char*)realloc(S.ch,(S.length + T.length)*sizeof(char))))
		{
			exit(OVERFLOW);
		}
		for (i = S.length - 1; i >= pos - 1; --i)
		{
			S.ch[i + T.length] = S.ch[i];
		}
		for (i = 0; i < T.length; i++)
		{
			S.ch[i + pos - 1] = T.ch[i];
		}
		S.length += T.length;
	}
	return OK;
}

Status StrDelete(HString &S, int pos, int len)
{
	int i;
	if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1)
	{
		return ERROR;
	}
	if (len)
	{
		for (i = pos - 1; i < S.length - len; i++)
		{
			S.ch[i] = S.ch[i + len];
		}
		S.length -= len;
		S.ch = (char*)realloc(S.ch,S.length*sizeof(char));
	}
	return OK;
}

int Index1(HString S, HString T,int pos)
{
	int i = pos - 1,j = 0;
	if (pos < 1 || pos > S.length)
	{
		return 0;
	}
	if (!StrEmpty(T))
	{
		while (i < S.length && j < T.length)
		{
			if (S.ch[i] == T.ch[j])
			{
				i++;
				j++;
			}
			else
			{
				i = i - j + 1;
				j = 0;
			}
		}
		if (j >= T.length)
		{
			return i - T.length + 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

Status Replace(HString &S, HString s1, HString s2)
{
	int i = 1;
	Status k;
	if (StrEmpty(s1))
	{
		return ERROR;
	}
	while (i)
	{
		i = Index1(S,s1,i);
		if (i)
		{
			StrDelete(S,i,s1.length);
			StrInsert(S,i,s2);
			i += s2.length;
		}
	}
	return OK;
}

void StrPrint(HString S)
{
	int i;
	for (i = 0; i < S.length; i++)
	{
		printf("%c",S.ch[i]);
	}
	printf("\n");
}