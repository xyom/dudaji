#include <cstdio>
#include <stdlib.h>

using namespace std;

class Stack
{
private:
	int top = -1;
	int max_size;
	int *arr;
	void allocate()
	{
		arr = (int*)malloc(sizeof(int) * max_size);
	}
public:
	Stack()
	{
		max_size = 10;
		allocate();
	};
	Stack(int size)
	{
		max_size = size;
		allocate();
	};

	bool isFull()
	{
		return top == max_size ? true : false;
	}
	bool isEmpty()
	{
		return top == -1 ? true : false;
	}

	void push(int a)
	{
		top++;
		arr[top] = a;
	}

	int pop()
	{
		return arr[top--];
	}

};


void main()
{
	Stack s1;

	for (int i = 0; i < 10; i++)
	{
		s1.push(i);
	}

	while (!s1.isEmpty())
	{
		printf("%d ", s1.pop());
	}
}