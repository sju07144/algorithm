/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Position
{
public:
	long long x, y, index;
};

class Distance
{
public:
	long long distance, index2;
};

int n, k;
long long tempX, tempY;
Position input;
Position x1[10001];
Position c[10];
Distance temp[10];
vector<Position> cluster[10];
vector<Distance> di;

bool compare(const Position& a, const Position& b) { return a.index < b.index; }


void clustering()
{
	int count = 0;
	c[0] = x1[0];
	count++;
	while (count != k)
	{
		for (int i = 0; i < n; i++)
		{
			for (int l = 0; l < count; l++)
			{
				if (x1[i].x != c[l].x || x1[i].y != c[l].y)
				{
					tempX = x1[i].x - c[l].x;
					tempY = x1[i].y - c[l].y;
					temp[l].distance = tempX * tempX + tempY * tempY;
					temp[l].index2 = i;
				}
			}
			Distance min = temp[0];
			for (int l = 1; l < count; l++)
			{
				if (min.distance > temp[l].distance)
				{
					min.distance = temp[l].distance;
					min.index2 = temp[1].index2;
				}
			}
			di.push_back(min);
		}
		Distance max = di[0];
		for (int i = 1; i != di.size(); i++)
		{
			if (max.distance < di[i].distance)
			{
				max.distance = di[i].distance;
				max.index2 = di[i].index2;
			}
		}
		c[count] = x1[max.index2];
		di.clear();
		count++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int l = 0; l < k; l++)
		{
			if (x1[i].x != c[l].x || x1[i].y != c[l].y)
			{
				tempX = x1[i].x - c[l].x;
				tempY = x1[i].y - c[l].y;
				temp[l] = tempX * tempX + tempY * tempY;
			}
		}
		distance = min<long long>(temp, k);
		for (int l = 0; l < k; l++)
		{
			if (distance == temp[l])
				cluster[l].push_back(x1[i]);
		}
	}
	
}

int main(void)
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> x1[i].x >> x1[i].y;
		x1[i].index = i;
	}
	clustering();
	sort(c, c + k, compare);
	for (int i = 0; i < k; i++)
		cout << c[i].x << ' ' << c[i].y << endl;
	return 0;
}*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Position
{
public:
	int x, y, index;
};

class Distance
{
public:
	double distance;
	int index2;
};

int n, k;
int tempX, tempY;
double temp2;
Position input;
Position x1[10001];
Position c[10];
vector<Distance> temp;
vector<Distance> di;

bool compare(const Position& a, const Position& b) { return a.index < b.index; }

void clustering(void)
{
	Distance min, max, temp3;
	int count = 0;
	c[count++] = x1[0];
	while (count != k)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < count; j++)
			{
				if (x1[i].x != c[j].x || x1[i].y != c[j].y)
				{
					tempX = x1[i].x - c[j].x;
					tempY = x1[i].y - c[j].y;
					temp2 = (double)(tempX * tempX + tempY * tempY);
					temp3.distance = sqrt(temp2);
					temp3.index2 = x1[i].index;
					temp.push_back(temp3);
				}
			}
			min = *temp.begin();
			for (auto m = temp.begin(); m != temp.end(); m++)
			{
				if (min.distance >= (*m).distance)
				{
					min.distance = (*m).distance;
					min.index2 = (*m).index2;
				}
			}
			di.push_back(min);
			temp.clear();
		}
		max = di[0];
		for (auto i = di.begin(); i != di.end(); i++)
		{
			if (max.distance <= (*i).distance)
			{
				max.distance = (*i).distance;
				max.index2 = (*i).index2;
			}
		}
		c[count++] = x1[max.index2];
		di.clear();
	}

}

int main(void)
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> x1[i].x >> x1[i].y;
	}
	for (int i = 0; i < n; i++)
		x1[i].index = i;
	clustering();
	sort(c, c + k, compare);
	for (int i = 0; i < k; i++)
		cout << c[i].x << ' ' << c[i].y << endl;
	return 0;
}