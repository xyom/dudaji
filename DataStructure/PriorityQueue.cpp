#include <cstdio>
#include <stdlib.h>

using namespace std;


class PriorityQueue
{
private:

	int max_size = 10;
	int size = 0;
	void allocate()
	{
		arr = (int*)malloc(sizeof(int)  * max_size);
	}
public:
	int* arr;
	PriorityQueue()
	{
		allocate();
	}
	PriorityQueue(int size)
	{
		max_size = size;
		allocate();
	}

	int getLeft(int n)
	{
		if (2 * n + 1 < size)
			return 2 * n + 1;
		else
			return -1;
	}
	int getRight(int n)
	{
		if (2 * n + 2 < size)
			return 2 * n + 2;
		else
			return -1;
	}

	int getParent(int n)
	{
		return (n - 1) / 2;
	}

	bool isFull()
	{
		return size == max_size;
	}
	bool isEmpty()
	{
		return size == 0;
	}

	void push(int a)
	{
		if (!isFull())
		{
			int current = size;
			int parent = getParent(current);

			arr[current] = a;
			while (arr[current] > arr[parent])
			{
				int temp = arr[current];
				arr[current] = arr[parent];
				arr[parent] = temp;

				current = parent;
				parent = getParent(current);
			}
			size++;
		}
	}
	int pop()
	{
		int target = arr[0];
		arr[0] = arr[--size];
		int current = 0;

		while (true)
		{
			int left_child = getLeft(current);
			int right_child = getRight(current);

			if (left_child != -1 && right_child != -1)
			{
				if (arr[current] < arr[left_child] || arr[current] < arr[right_child])
				{
					if (arr[left_child] < arr[right_child])
					{
						int temp = arr[current];
						arr[current] = arr[right_child];
						arr[right_child] = temp;
						current = right_child;
					}
					else
					{
						int temp = arr[current];
						arr[current] = arr[left_child];
						arr[left_child] = temp;
						current = left_child;
					}
				}
				else
					break;
			}
			else if (left_child != -1)
			{
				if (arr[current] < arr[left_child])
				{
					int temp = arr[current];
					arr[current] = arr[left_child];
					arr[left_child] = temp;
					current = left_child;
				}
				else
					break;
			}
			else
			{
				break;
			}
		}

		return target;
	}
};

void main()
{
	int test[3][11] = { { 324, 532, 3, 1023, 84, 23, 5 }
		, { 954, 15, 457, 12, 456, 785, 159, 123, 478 }
	, { 159, 789, 642, 148, 46, 2, 7, 98, 152, 346, 159 } };
	int size[3] = { 7, 9, 11 };
	PriorityQueue pq;

	for (int t = 0; t < 3; t++)
	{
		printf("insert number: ");
		for (int i = 0; i < size[t]; i++)
		{
			printf("%d ", test[t][i]);
			pq.push(test[t][i]);
		}
		printf("\n\nAll pop: ");
		while (!pq.isEmpty())
		{
			printf("%d ", pq.pop());
		}
		printf("\n\n---------------------------------------------\n\n");
	}


}