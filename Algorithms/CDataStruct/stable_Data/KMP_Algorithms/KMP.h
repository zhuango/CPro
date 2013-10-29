void get_next(SString T, int next[])
{
	int i = 1,j = 0;
	next[1] = 0;
	while(i < T[0])
	{
		if (0 == j || T[i] == T[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

void get_nextval(SString T, int nextval[])//计算next函数修正值并存入数组nextval
{
	int i = 1,j = 0;
	nextval[1] = 0;
	while(i < T[0])
	{
		if (0 == j || T[i] == T[j])
		{
			i++;
			j++;
			if (T[i] != T[j])
			{
				nextval[i] = j;
			}
			else
			{
				nextval[i] = nextval[j];
			}
		}
		else
		{
			j = nextval[j];
		}
	}
}

int Index_KMP(SString S, SString T, int pos,int next[])
{
	int i = pos,j = 1;

	if (pos >= 1 && pos <= S[0])
	{
		while(i <= S[0] && j <= T[0])
		{
			if (0 == j || S[i] == T[j])
			{
				i++;
				j++;
			}
			else
			{
				j = next[j];
			}
		}

		if (j > T[0])
		{
			return i - T[0];
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