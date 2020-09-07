#include <iostream>
#include <cstdio>
using namespace std;
#define INF 2000000;

int c[100001];
int n;
int k = 0;
char s[100];
int d[11];
char* tok;

int dpCoinChange(void)
{
	c[0] = 0;
	for (int i = 1; i <= n; i++)
		c[i] = INF;
	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i <= k; i++)
		{
			if ((d[i] <= j) && (c[j - d[i]] + 1 < c[j]))
				c[j] = c[j - d[i]] + 1;
		}
	}
	return c[n];
}

int main(void)
{
	scanf("%[^\n]s", s);
	scanf("%d", &n);
	tok = strtok(s, ",");

	while (tok != NULL)
	{
		k++;
		d[k] = atoi(tok);
		tok = strtok(NULL, ",");
	}
	cout << dpCoinChange() << endl;
	return 0;
}