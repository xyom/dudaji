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

void InsertSort(vector<int>& arr)
{
	for (int i = 1; i < arr.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j])
			{
				int temp = arr[i];
				memcpy(&arr[j+1], &arr[j], sizeof(int*) *(i - j));
				arr[j] = temp;
			}
		}
	}
}
void main()
{
	srand((unsigned int)time(NULL));

	vector<int> arr;
	for (int i = 0; i < 10; i++)
		arr.push_back(rand() % 100);

	InsertSort(arr);

	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
}