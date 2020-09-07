#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int path[100][100];
int num;

void allpairsshortest()
{
	for (int k = 0; k < num; k++)
	{
		for (int i = 0; i < num; i++)
		{
			if (i == k)
				continue;
			for (int j = 0; j < num; j++)
			{
				if (j == k || j == i)
					continue;
				if (path[i][k] + path[k][j] < path[i][j])
					path[i][j] = path[i][k] + path[k][j];
			}
		}
	}
}

int main(void)
{
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			scanf("%d", &path[i][j]);
		}
	}

	allpairsshortest();
	
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (path[i][j] >= 99900)
				path[i][j] = 99999;
			printf("%d ", path[i][j]);
		}
		printf("\n");
	}

	return 0;
}