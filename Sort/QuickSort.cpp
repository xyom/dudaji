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

int pivot(vector<int>& arr, int left, int right)
{
	int p_value = arr[left];
	int p_index = left;

	for (int i = left + 1; i <= right; i++)
	{
		if (arr[i] < p_value)
		{
			p_index++;
			swap(arr, i, p_index);
		}
	}
	swap(arr, left, p_index);

	return p_index;

}


void quickSort(vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		int mid = pivot(arr, left, right);
		quickSort(arr, left, mid - 1);
		quickSort(arr, mid + 1, right);
	}
}


void main()
{
	srand((unsigned int)time(NULL));

	vector<int> arr;

	printf("before sort: ");
	for (int i = 0; i < 10; i++)
	{
		arr.push_back(rand() % 100);
		printf("%d ", arr[i]);
	}

	quickSort(arr, 0, 9);

	printf("\n\nafter sort: ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
}