#include <iostream>

using namespace std;

template<typename T>
class RBTree
{
	class Element
	{
	public:
		T data;
		Element* right = nullptr;
		Element* left = nullptr;
		Element* parent = nullptr;
		//true = red | false = black
		bool color;
		Element(T d, bool c = false, Element* p = nullptr, Element* r = nullptr, Element* l = nullptr)
		{
			data = d;
			color = c;
			parent = p;
			right = r;
			left = l;
		}
	};
	Element* root = nullptr;
	int size = 0;

	void Insert(Element* value)
	{
		value->color = true;
		while (value != root && value->parent->color == true)
		{
			if (value->parent == nullptr || value->parent->parent == nullptr) break;
			if (value->parent == value->parent->parent->left)
			{
				Element* stryjek = value->parent->parent->right;
				if (stryjek && stryjek->color == true)
				{
					value->parent->color = false;
					stryjek->color = false;
					value->parent->parent->color = true;
					value = value->parent->parent;
				}
				else
				{
					if (value == value->parent->right)
					{
						leftRotate(value);
						value = value->parent;
					}
					value->parent->color = false;
					value->parent->parent->color = true;
					rightRotate(value->parent);
				}
			}
			else
			{
				Element* stryjek = value->parent->parent->left;
				if (stryjek && stryjek->color == true)
				{
					value->parent->color = false;
					stryjek->color = false;
					value->parent->parent->color = true;
					value = value->parent->parent;
				}
				else
				{
					if (value == value->parent->left)
					{
						rightRotate(value);
						value = value->parent;
					}
					value->parent->color = false;
					value->parent->parent->color = true;
					leftRotate(value->parent);
				}
			}

		}
		root->color = false;
	}

	void leftRotate(Element* x)
	{
		Element* y = x->right;
		x->right = y->left;
		if (x->right != nullptr)
			x->right->parent = x;
		y->parent = x->parent;
		if (x->parent == nullptr)
			root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	}
	void rightRotate(Element* y)
	{
		Element* x = y->left;
		y->left = x->right;
		if (x->right != nullptr)
			x->right->parent = y;
		x->parent = y->parent;
		if (x->parent == nullptr)
			root = x;
		else if (y == y->parent->left)
			y->parent->left = x;
		else y->parent->right = x;
		x->right = y;
		y->parent = x;
	}

public:
	void Add(T value)
	{
		size++;
		if (root == nullptr)
		{
			root = new Element(value);
			Insert(root);
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
			prev->right->parent = prev;
			cout << prev->right->data << " -> ojciec: " << prev->right->parent->data << endl;
			Insert(prev->right);
		}
		else
		{
			prev->left = newElement;
			prev->left->parent = prev;
			cout << prev->left->data << " -> ojciec: " << prev->left->parent->data << endl;
			Insert(prev->left);
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
	int sizeTree()
	{
		return size;
	}
};

int main()
{
	RBTree<int> Tree;

	Tree.Add(11);
	Tree.Add(28);
	Tree.Add(29);
	Tree.Add(49);
	Tree.Add(52);
	Tree.Add(4);

	if (Tree.Search(49))
		cout << "Jest\n";
	else
		cout << "Nie ma\n";

	Tree.Erase();

	if (Tree.Search(49))
		cout << "Jest\n";
	else
		cout << "Nie ma\n";

	return 0;
}