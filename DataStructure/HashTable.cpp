#include <iostream>
#include <vector>
#include <string>

using namespace std;


class HashTable
{
private:
	vector<vector<string>> table; // 체인을 이용하여 충돌의 문제를 완화한다.
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
			vector<string> chain;
			table.push_back(chain);
		}
	}
	void setValue(string key,string value)
	{
		int index = getHash(key);
	
		table[index].push_back(value);
	}
	vector<string> getValue(string key)
	{
		int index = getHash(key);

		vector<string> result;
		for (int i = 0; i < table[index].size(); i++)
		{
			result.push_back(table[index][i]);
		}
		return result;
	}
};



void main()
{
	ios::sync_with_stdio(false);cin.tie(0);

	HashTable ht;

	ht.setValue("Value", "flow");
	ht.setValue("Value", "flower");
	ht.setValue("Value", "falut");
	ht.setValue("value", "Areo");
	ht.setValue("value", "Bucket");

	vector<string> result = ht.getValue("Value");
	vector<string> result2 = ht.getValue("value");

	for (int i = 0; i < result.size(); i++)
		cout << result[i]<<endl;
	for (int i = 0; i < result2.size(); i++)
		cout << result2[i] << endl;
}