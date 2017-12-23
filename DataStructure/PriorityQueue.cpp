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
		arr = (int*)malloc( sizeof(int)  * max_size );
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
	PriorityQueue pq;

	pq.push(324);
	pq.push(532);
	pq.push(3);
	pq.push(1023);
	pq.push(84);
	pq.push(23);
	pq.push(5);


	while (!pq.isEmpty())
	{
		printf("%d ", pq.pop());
	}
}