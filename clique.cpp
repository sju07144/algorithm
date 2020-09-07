#include <iostream>
using namespace std;

int arr[11][11];
int n;
int count2 = 0;
int check;
int max;

int main(void)
{
	int n, k, count = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)
			{
				count++;
			}
		}
		if (count < k - 1)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = 0;
				arr[j][i] = 0;
			}
		}
		count = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)
				count++;
		}
		if (count == k - 1)
		{
			check = 1;
			break;
		}
		count = 0;
	}*/
	return 0;
}