#include <iostream>
#include <algorithm>
#define SIZE 20000
using namespace std;

class graph
{
public:
	int start, end, weight;
};

int g[201], vertex, edge;
graph gph[SIZE], temp[SIZE];

inline void union_find(int a, int b)
{
	if (a < b) 
		g[b] = a;
	else
		g[a] = b;
}

inline int get(int x)
{
	if (x == g[x])
		return x;
	return g[x] = get(g[x]);
}

inline bool compare(const graph& a, const graph& b) { return a.weight < b.weight; }

/*void merge(int left, int right, int mid)
{
	int i = left, j = mid + 1, k = right;
	while (i <= mid && j <= right)
	{
		if (compare(gph[i], gph[j]))
			temp[k++] = gph[i++];
		else
			temp[k++] = gph[j++];
		while (i <= mid)
			temp[k++] = gph[i++];
		while (j <= right)
			temp[k++] = gph[j++];
		for (int l = left; l <= right; l++)
			gph[l] = temp[l];
	}
}

void divide(int left, int right)
{
	if (left >= right) return;
	int mid = (left + right) / 2;
	divide(left, mid);
	divide(mid + 1, right);
	merge(left, right, mid);
}*/

int kruskal(void)
{
	int sum = 0, cnt = 0;
	for (int i = 0; i < edge; i++)
	{
		int a = get(gph[i].start), b = get(gph[i].end);
		if (a == b) 
			continue;
		sum += gph[i].weight;
		if (++cnt == vertex - 1)
			break;
		union_find(a, b);
	}
	return sum;
}

int main(void)
{
	cin >> vertex >> edge;
	for (int i = 1; i <= vertex; i++)
		g[i] = i;
	for (int j = 0; j < edge; j++)
		cin >> gph[j].start >> gph[j].end >> gph[j].weight;
	sort(gph, gph + edge, compare);
	cout << kruskal() << endl;
	return 0;
}