#include <cstdio>
#include <stdlib.h>
#define INF -987654321

using namespace std;


typedef struct Node
{
	Node* prev;
	Node* next;
	int value;

	Node(int v)
	{
		value = v;
	}
}node;

class LinkedList
{
private:
	Node* head;
	Node* tail;
	int size = 0;
public:

	LinkedList()
	{

	}
	int getSize()
	{
		return size;
	}

	void pushFront(int value)
	{
		Node* target = (Node*)malloc(sizeof(Node));
		target->prev = NULL;
		target->next = NULL;
		target->value = value;

		if (head == NULL)
		{
			head = target;
			tail = target;
		}
		else
		{
			head->prev = target;
			target->next = head;
			head = target;
		}
		size++;
	}

	void pushBack(int value)
	{
		Node* target = (Node*)malloc(sizeof(Node));
		target->value = value;

		target->prev = NULL;
		target->next = NULL;

		if (tail == NULL)
		{
			head = target;
			tail = target;
		}
		else
		{
			tail->next = target;
			target->prev = tail;
			tail = target;
		}
		size++;
	}

	void insertAt(int index, int value)
	{
		Node* offset = head;
		bool exist = true;
		while (index--)
		{
			if (offset->next != NULL)
				offset = offset->next;
			else
				exist = false;
		}

		if (exist)
		{
			Node* target = (Node*)malloc(sizeof(Node));
			
			target->prev = offset->prev;
			target->next = offset;
			target->value = value;

			if (offset->prev->next != NULL)
				offset->prev->next = target;
			offset->prev = target;

			size++;
		}
		else
		{
			printf("That Node Not Exist!\n");
		}
	}

	int popFront()
	{
		if (head == NULL)
		{
			return INF;
		}
		else
		{
			size--;
			int value = head->value;
			head = head->next;
			return value;
		}
	}

	int popBack()
	{
		if (tail == NULL)
		{
			return INF;
		}
		else
		{
			size--;
			int value = tail->value;
			tail = tail->prev;

			return value;
		}
	}

	

};

void main()
{
	LinkedList l1;

	for (int i = 0; i < 10; i++)
		l1.pushBack(i);

	while (l1.getSize() != 0)
	{
		if (l1.getSize() % 2 == 0)
			printf("%d ", l1.popBack());
		else
			printf("%d ", l1.popFront());
	}

}