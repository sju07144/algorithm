/*#include <iostream>
#include <cstdio>
#include <set>
#include <array>
#include <algorithm>
using namespace std;

set<int> s[31];
int arr[31];
bool a[31];
int b[31];
int num;
bool u[32];
int cnt = 0;

bool empty()
{
	int check = 0;
	for (int i = 1; i <= num; i++)
		if (u[i] == true)
			check++;
	if (check == num)
		return true;
	return false;
}

void setCover()
{
	while (!empty())
	{
		for (int i = 0; i < num; i++)
		{
			if (a[i] == true)
				continue;
			for (auto j = s[i].begin(); j != s[i].end(); j++)
			{
				for (int k = 1; k <= num; k++)
				{
					if (u[k] == true)
						continue;
					if (*j == k)
						b[i]++;
				}
			}
		}
		int max = 0;
		int maxnum = 0;
		for (int i = 0; i < num; i++)
		{
			if (a[i] == true)
				continue;
			if (b[i] > max)
			{
				max = b[i];
				maxnum = i;
			}
		}
		a[maxnum] = true;
		for (auto j = s[maxnum].begin(); j != s[maxnum].end(); j++)
			u[*j] = true;
		arr[cnt] = maxnum + 1;
		cnt++;
	}
}

bool compare(const int& a, const int& b) { return a < b; }

int main(void)
{
	int n;
	scanf("%d", &num);
	u[0] = true;
	for (int i = 1; i <= num; i++)
	{
		u[i] = false;
		a[i - 1] = false;
		b[i - 1] = 0;
	}
	int k = 0;
	char c;
	while (k < num)
	{
		while (true)
		{
			scanf("%d", &n);
			s[k].insert(n);
			c = getchar();
			if (c == '\n')
				break;
		}
		k++;
		c = 0;
	}
	setCover();
	sort(arr, arr + cnt, compare);
	for (int i = 0; i < cnt; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}*/

/*#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int s[31][11];
int arr[31];
bool a[31];
int b[31];
int crr[31];
bool u[32];
int cnt = 0;

bool empty(int num)
{
	int check = 0;
	for (int i = 1; i <= num; i++)
		if (u[i] == true)
			check++;
	if (check == num)
		return true;
	return false;
}

void setCover(int num)
{
	while (!empty(num))
	{
		for (int i = 0; i < num; i++)
		{
			if (a[i] == true)
				continue;
			for (int j = 0; j < crr[i]; j++)
			{
				for (int k = 1; k <= num; k++)
				{
					if (u[k] == true)
						continue;
					if (s[i][j] == k)
						b[i]++;
				}
			}
		}
		int max = 0;
		int maxnum = 0;
		for (int i = 0; i < num; i++)
		{
			if (a[i] == true)
				continue;
			if (b[i] > max)
			{
				max = b[i];
				maxnum = i;
			}
		}
		a[maxnum] = true;
		for (auto j = 0; j < crr[maxnum]; j++)
			u[s[maxnum][j]] = true;
		arr[cnt] = maxnum + 1;
		cnt++;
	}
}

bool compare(const int& a, const int& b) { return a < b; }

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	u[0] = true;
	for (int i = 1; i <= num; i++)
	{
		u[i] = false;
		a[i - 1] = false;
		b[i - 1] = 0;
		crr[i - 1] = 0;
	}
	int k = 0;
	int j = 0;
	char c;
	while (k < num)
	{
		scanf("%d", &s[k][j]);
		(crr[k])++;
		c = getchar();
		j++;
		if (c == '\n')
		{
			k++;
			j = 0;
		}
	}
	setCover(num);
	sort(arr, arr + cnt, compare);
	for (int i = 0; i < cnt; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

set<int> s[1000];
int arr[1000];
bool a[1000];
int b[1000];
int num;
bool u[1001];
short cnt = 0;

bool empty(void)
{
	int check = 0;
	for (int i = 1; i <= num; i++)
		if (u[i] == true)
			check++;
	if (check == num)
		return true;
	return false;
}

void setcover(void)
{
	while (!empty())
	{
		for (int i = 0; i < num; i++)
		{
			if (a[i] == true)
				continue;
			for (auto j = s[i].begin(); j != s[i].end(); j++)
			{
				for (int k = 1; k <= num; k++)
				{
					if (u[k] == true)
						continue;
					if ((*j) == k)
						b[i]++;
				}
			}
		}
		int max = 0;
		int maxnum = 0;
		for (int i = 0; i < num; i++)
		{
			if (a[i] == true)
				continue;
			if (b[i] > max)
			{
				max = b[i];
				maxnum = i;
			}
		}
		a[maxnum] = true;
		for (auto j = s[maxnum].begin(); j != s[maxnum].end(); j++)
			u[(*j)] = true;
		arr[cnt] = maxnum + 1;
		cnt++;
		for (int i = 0; i < num; i++)
			b[i] = 0;
	}
}

bool compare(const int& a, const int& b) { return a < b; }

int main(void)
{
	int n;
	char str[1024];
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		u[i] = false;
		a[i - 1] = false;
		b[i - 1] = 0;
	}
	int k = 0;
	char* c;
	int d;
	while (getchar() != '\n');
	while (k < num)
	{
		
		fgets(str, 1024, stdin);
		str[strlen(str) - 1] = '\0';
		c = strtok(str, " ");
		while (c != NULL)
		{
			n = atoi(c);
			s[k].insert(n);
			c = strtok(NULL, " ");
		}
		k++;
	}
	setcover();
	sort(arr, arr + cnt, compare);
	for (int i = 0; i < cnt; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}

/*#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int s[31][11];
int arr[31];
bool a[31];
int b[31];
int crr[31];
bool u[32];
int cnt = 0;

bool empty(int num)
{
	int check = 0;
	for (int i = 1; i <= num; i++)
		if (u[i] == true)
			check++;
	if (check == num)
		return true;
	return false;
}

void setCover(int num)
{
	while (!empty(num))
	{
		for (int i = 0; i < num; i++)
		{
			if (a[i] == true)
				continue;
			for (int j = 0; j < crr[i]; j++)
			{
				for (int k = 1; k <= num; k++)
				{
					if (u[k] == true)
						continue;
					if (s[i][j] == k)
						b[i]++;
				}
			}
		}
		int max = 0;
		int maxnum = 0;
		for (int i = 0; i < num; i++)
		{
			if (a[i] == true)
				continue;
			if (b[i] > max)
			{
				max = b[i];
				maxnum = i;
			}
		}
		a[maxnum] = true;
		for (auto j = 0; j < crr[maxnum]; j++)
			u[s[maxnum][j]] = true;
		arr[cnt] = maxnum + 1;
		cnt++;
	}
}

bool compare(const int& a, const int& b) { return a < b; }

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	u[0] = true;
	for (int i = 1; i <= num; i++)
	{
		u[i] = false;
		a[i - 1] = false;
		b[i - 1] = 0;
		crr[i - 1] = 0;
	}
	int k = 0;
	int j = 0;
	char c;
	while (k < num)
	{
		scanf("%d", &s[k][j]);
		(crr[k])++;
		c = getchar();
		j++;
		if (c == '\n')
		{
			k++;
			j = 0;
		}
	}
	setCover(num);
	sort(arr, arr + cnt, compare);
	for (int i = 0; i < cnt; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}*/