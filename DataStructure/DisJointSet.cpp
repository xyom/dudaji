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
		arr = (int*) malloc( sizeof(int) * size );
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
			return x = getParent(arr[x]);
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

	ds.unify(2, 3);
	ds.unify(1, 3);

	printf("%d ", ds.getParent(2));
	printf("%d ", ds.getParent(1));
}