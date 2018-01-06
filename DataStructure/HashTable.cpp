#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct
{
	string key;
	string value;
}Data;

class HashTable
{
private:
	vector<vector<Data>> table; // 체인을 이용하여 충돌의 문제를 완화한다.
	int getHash(string s)
	{
		int sum = 0;
		int base = 1;
		for (int i = 0; i < s.length(); i++)
		{
			sum += s[i] * base;
			base *= 2;
		}
		return sum % table.size();
	}
public:
	HashTable()
	{
		for (int i = 0; i < 1000; i++)
		{
			vector<Data> chain;
			table.push_back(chain);
		}
	}
	void setValue(string key, string value)
	{
		int index = getHash(key);
		for (int i = 0; i < table[index].size(); i++)
		{
			if (table[index][i].key.compare(key) == 0)
			{
				table[index][i] = Data{ key, value };
				return;
			}
		}
		table[index].push_back(Data{ key, value });
	}
	string getValue(string key)
	{
		int index = getHash(key);

		for (int i = 0; i < table[index].size(); i++)
		{
			if (table[index][i].key.compare(key) == 0)
				return table[index][i].value;
		}
		return "Not Exist";
	}
};


void main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	HashTable ht;

	ht.setValue("Value", "flow");
	ht.setValue("Value", "gold");
	ht.setValue("key", "value");
	ht.setValue("yek", "volume");

	cout << ht.getValue("Value") << endl;
	cout << ht.getValue("key") << endl;
	cout << ht.getValue("yek") << endl;
	cout << ht.getValue("kye") << endl;
}