#include<cstdio>
#include<iostream>

#include<queue>
using namespace std;

int main()
{
	queue<int> q;
	int n, i;

	std::cin >> n;

	for(i = 0; i < n; i++)
		q.push(i + 1);

	printf("%d\n", q.front());
	while(!q.empty()) {
		printf("%d ", q.front());
		q.pop();
		q.push(q.front());
		q.pop();
	}
	return 0;
}
