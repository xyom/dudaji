#include<cstdio>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

void swap(vector<int>& arr, int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void selectionSort(vector<int>& arr)
{
	int m_index;
	for (int i = 0; i < arr.size() - 1; i++)
	{
		m_index = i;
		for (int j = i; j < arr.size(); j++)
		{
			if (arr[j] < arr[m_index])
				m_index = j;
		}
		swap(arr, i, m_index);
	}
}

void main()
{
	srand((unsigned int)time(NULL));

	vector<int> arr;
	for (int i = 0; i < 10; i++)
		arr.push_back(rand() % 100);

	selectionSort(arr);

	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
}