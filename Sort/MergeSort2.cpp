#include<cstdio>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

vector<int> arr;

void Merge(int left,int right)
{
	vector<int> result;
	int mid = (left + right) / 2;
	int arr1_index = left;
	int arr2_index = mid+1;

	while (arr1_index < mid+1 && arr2_index < right + 1)
	{
		if (arr[arr1_index] < arr[arr2_index])
		{
			result.push_back(arr[arr1_index]);
			arr1_index++;
		}
		else
		{
			result.push_back(arr[arr2_index]);
			arr2_index++;
		}
	}

	while (arr1_index < mid+1)
	{
		result.push_back(arr[arr1_index]);
		arr1_index++;
	}
	while (arr2_index < right + 1)
	{
		result.push_back(arr[arr2_index]);
		arr2_index++;
	}

	for (int i = 0; i < result.size(); i++)
	{
		arr[i + left] = result[i];
	}

}

void MergeSort(vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(left, right);
	}
	
}
void main()
{
	srand((unsigned int)time(NULL));

	
	printf("before sort: ");
	for (int i = 0; i < 10; i++)
	{
		arr.push_back(rand() % 100);
		printf("%d ", arr[i]);
	}

	MergeSort(arr, 0, arr.size() - 1);

	printf("\n\nafter sort: ");
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
}