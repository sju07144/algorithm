#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int num;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second < b.second;
}

int taskScheduling(void)
{
	int max = 0;
	int finish = 0;
	for (int i = 0; i < num; i++)
	{
		if (v[i].first > finish)
		{
			finish = v[i].second;
			max++;
		}
	}
	return max;
}

int main(void)
{
	cin >> num;
	pair<int, int> input;
	for (int i = 0; i < num; i++)
	{
		cin >> input.first >> input.second;
		v.push_back(input);
	}
	sort(v.begin(), v.end(), compare);
	cout << taskScheduling() << endl;
	return 0;
}