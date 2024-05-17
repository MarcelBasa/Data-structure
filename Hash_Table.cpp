#include <iostream>
#include <list>
#include <string>

using namespace std;

template<typename K, typename V>
class HashTable
{
	list<V> arr[10];

public:
	void add(K key, V value)
	{
		arr[hashing(key)].push_back(value);
	}
	bool erase(K key, V value)
	{
		for (V n : arr[hashing(key)])
		{
			if (n == value)
			{
				arr[hashing(key)].remove(n);
				return true;
			}
		}
		return false;
	}
	void eraseTable()
	{
		for (int i = 0; i < 10; i++)
		{
			arr[i].clear();
		}
	}
	bool find(K key, V value)
	{
		for (V n : arr[hashing(key)])
		{
			if (n == value)
				return true;
		}
		return false;
	}
	void show()
	{
		for (int i = 0; i < 10; i++)
		{
			cout << "index " << i << ": ";
			for (V n : arr[i])
			{
				cout << n << " ";
			}
			cout << endl;
		}
	}
	int hashing(K key)
	{
		return (int)key % 10;
	}
};

int main()
{
	HashTable<int, string> Table;
	Table.add(100, "Maciek");
	Table.add(100, "Darek");
	Table.add(123, "Jan");
	Table.show();
	if (Table.find(100, "Darek"))
		cout << "Jest\n";
	else
		cout << "Nie ma\n";

	Table.erase(100, "Darek");

	if (Table.find(100, "Darek"))
		cout << "Jest\n";
	else
		cout << "Nie ma\n";
}
