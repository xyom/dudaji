#include<cstdio>
#include<stdlib.h>
#define INF -987654321
using namespace std;

//��ȯ�ϴ� arrayť
class Queue
{
private:
	int max_size = 11;
	int *arr;
	int front = 0;
	int rear = 0;

	void allocate()
	{
		arr = (int *)malloc(sizeof(int) * max_size);
	}

public:
	Queue()
	{
		allocate();
	}
	Queue(int size)
	{
		max_size = size + 1; // ť�� ����ť�� ������ �� ����Ʈ�� ����� ���� ���¸� �����ϱ� ���ؼ� ����� 1��ŭ ������� ���ϹǷ� +1�� ���� �ִ������� ���ش�.
		allocate();
	}

	bool isEmpty()
	{
		return front == rear ? true : false;
	}

	bool isFull()
	{
		return front == (rear + 1) % max_size ? true : false;
	}

	void push(int a)
	{
		if (!isFull())
		{
			arr[rear] = a;
			rear = (rear + 1) % max_size;
		}
		else
		{
			printf("Queue is Fulled\n");
		}
	}
	int pop()
	{
		if (!isEmpty())
		{
			int item = arr[front];
			front = (front + 1) % max_size;
			return item;
		}
		else
		{
			return -INF;
		}
	}
};


void main()
{
	Queue q1;

	int push[20] = { 12, 13, 15, 16, 201, 356, 23, 76, 45, 34, 23, 23, 35, 23, 35, 46, 78, 89, 90, 21 };

	int index = 0;

	while (index != 20)
	{
		while (!q1.isFull())
		{
			q1.push(push[index]);
			index++;
		}
		while (!q1.isEmpty())
		{
			printf("%d ", q1.pop());
		}
	}
	
}