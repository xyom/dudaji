#include <cstdio>
#include <malloc.h>

using namespace std;

class DisJointSet
{
private:
	int size = 100;
	int* arr;
	void allocate()
	{
		arr = (int*)malloc(sizeof(int) * size);
		for (int i = 0; i < size; i++)
			arr[i] = i;
	}
public:
	DisJointSet()
	{
		allocate();
	}
	DisJointSet(int s)
	{
		size = s;
		allocate();
	}

	int getParent(int x)
	{
		if (arr[x] == x)
			return x;
		else
			return arr[x] = getParent(arr[x]);
	}

	void unify(int x, int y)
	{
		int parentx = getParent(x);
		int parenty = getParent(y);

		if (parentx != parenty)
			arr[parentx] = parenty;
	}
};


void main()
{
	DisJointSet ds;



	printf("before unify : \n");
	for (int i = 1; i <= 10; i++)
		printf("%d ", ds.getParent(i));
	printf("\n\n");

	printf("1, 2 unify to 3  and 4 5 unify to 6: \n");

	ds.unify(2, 3);
	ds.unify(1, 3);
	ds.unify(4, 6);
	ds.unify(5, 6);

	for (int i = 1; i <= 10; i++)
		printf("%d ", ds.getParent(i));
	printf("\n\n");


	printf("3 unify to 6: \n");
	ds.unify(3, 6);

	for (int i = 1; i <= 10; i++)
		printf("%d ", ds.getParent(i));
	printf("\n\n");
}