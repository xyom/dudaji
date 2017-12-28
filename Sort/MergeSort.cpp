#include<cstdio>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

vector<int> Merge(vector<int> arr1, vector<int> arr2)
{
	vector<int> result;
	int arr1_index = 0;
	int arr2_index = 0;

	while (arr1_index < arr1.size() && arr2_index < arr2.size())
	{
		if (arr1[arr1_index] < arr2[arr2_index])
		{
			result.push_back(arr1[arr1_index]);
			arr1_index++;
		}
		else
		{
			result.push_back(arr2[arr2_index]);
			arr2_index++;
		}
	}

	while (arr1_index < arr1.size())
	{
		result.push_back(arr1[arr1_index]);
		arr1_index++;
	}
	while (arr2_index < arr2.size())
	{
		result.push_back(arr2[arr2_index]);
		arr2_index++;
	}

	return result;

}

vector<int> MergeSort(vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		vector<int> arr1 = MergeSort(arr, left, mid);
		vector<int> arr2 = MergeSort(arr, mid + 1, right);
		return Merge(arr1, arr2);
	}
	else
	{
		vector<int> temp;
		temp.push_back(arr[left]);
		return temp;
	}
}
void main()
{
	srand((unsigned int)time(NULL));

	vector<int> arr;
	for (int i = 0; i < 10; i++)
		arr.push_back(rand() % 100);

	vector<int> result = MergeSort(arr, 0, arr.size() - 1);

	for (int i = 0; i < 10; i++)
		printf("%d ", result[i]);
}