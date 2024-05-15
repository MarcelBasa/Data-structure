#include <iostream>

using namespace std;

template<typename T>
class BST
{
	class Element
	{
	public:
		T data;
		Element* right = nullptr;
		Element* left = nullptr;
		Element(T d, Element* r = nullptr, Element* l = nullptr)
		{
			data = d;
			right = r;
			left = l;
		}
	};
	Element* root = nullptr;
	int size = 0;
public:
	void Add(T value)
	{
		size++;
		if (root == nullptr)
		{
			root = new Element(value);
			return;
		}
		Element* prev = nullptr;
		Element* current = root;
		while (current)
		{
			if (current->data == value) return;

			prev = current;
			if (current->data < value)
			{
				current = current->right;
			}
			else
			{
				current = current->left;
			}
		}
		Element* newElement = new Element(value);
		if (prev->data < value)
		{
			prev->right = newElement;
		}
		else
		{
			prev->left = newElement;
		}
	}
	T* Search(T value)
	{
		if (root == nullptr) return nullptr;

		Element* current = root;
		while (current)
		{
			if (current->data == value) return &current->data;

			if (current->data < value)
			{
				current = current->right;
			}
			else
			{
				current = current->left;
			}
		}
		return nullptr;
	}
	void Erase()
	{
		Element* current = root;
		Element* prev = root;
		string stan;

		while (root)
		{
			if (current->left)
			{
				stan = "lewo";
				prev = current;
				current = current->left;

			}
			else if (current->right)
			{
				stan = "prawo";
				prev = current;
				current = current->right;

			}
			else if (current->left == nullptr && current->right == nullptr)
			{
				cout << "elo\n";
				delete current;
				if (stan == "prawo")
					prev->right = nullptr;
				else if (stan == "lewo")
					prev->left = nullptr;
				else
					break;
				stan = "";
				prev = root;
				current = root;
			}
		}
		root = nullptr;
		size = 0;
	}
	void TreeSize(T arg)
	{
		if (root == nullptr)
			return;

		T right = size(arg->right);
		T left = size(arg->left);

		if (right < left)
			return (size + 1);
		else
			return (size + 1);
	}
};

int main()
{
	BST<int> bst;

	bst.Add(2);
	bst.Add(3);
	bst.Add(1);
	bst.Add(8);
	bst.Add(7);
	if (bst.Search(2))
		cout << "jest\n";
	else
		cout << "nie ma\n";

	bst.Erase();

	if (bst.Search(2))
		cout << "jest\n";
	else
		cout << "nie ma\n";
	return 0;
}