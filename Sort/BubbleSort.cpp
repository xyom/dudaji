#include<cstdio>
#include<cstdlib>
#include<ctime>


void BubbleSort(int* arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


void main()
{
	srand((unsigned int)time(NULL));

	int arr[10];
	printf("before sort: ");
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 1000;
		printf("%d ", arr[i]);
	}
	printf("\n\nafter sort: ");
	BubbleSort(arr, 10);

	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
}