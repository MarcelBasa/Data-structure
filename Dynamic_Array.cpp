#include <iostream>

using namespace std;

class some_object
{
    int v1 = 666;
public:
    void setValue(int value) { v1 = value; }
    int getValue() const { return v1; }

    bool operator< (some_object const& q) const { return v1 < q.v1; }
    bool operator< (int const& q) const { return v1 < q; };
};

template<typename T>
class Array
{
    int maxCapacity;
    int capacity;
    float capacityRate;
    T* container;
    void rebuildArray(int newSize)
    {
        T* helpContainer = new T[capacity];
        for (int i = 0; i < capacity; i++)
        {
            helpContainer[i] = container[i];
        }
        delete[] container;
        container = new T[newSize];
        for (int i = 0; i < capacity; i++)
        {
            container[i] = helpContainer[i];
        }
        delete[]helpContainer;
    }

public:
    Array()
    {
        maxCapacity = 1;
        capacity = 0;
        capacityRate = 2.f;
        container = new T[maxCapacity];
    }

    void addElement(T element)
    {
        if (capacity >= maxCapacity)
        {
            maxCapacity = maxCapacity * capacityRate;
            rebuildArray(maxCapacity);
            container[capacity] = element;
            capacity++;
        }
        else
        {
            container[capacity]= element;
            capacity++;
        }
    }

    T* at(int index)
    {
        if (index >= capacity)
            return nullptr;
        return &container[index];
    }

    bool edit(int index, T newElement)
    {
        if (index >= capacity) 
            return false;
        container[index] = newElement;
        return true;
    }

    void erase()
    {
        maxCapacity = 1;
        capacity = 0;
        delete[]container;
        container = new T[maxCapacity];
    }

    int size()
    {
        return capacity;
    }

    void sort()
    {
        for (int i = 0; i < capacity; i++)
        {
            for (int j = 0; j < capacity; j++)
            {
                if (container[i] < container[j])
                    swap(container[i], container[j]);
            }
        }
    }

    ~Array()
    {
        delete[]container;
    }
};

int main()
{
    Array<some_object> arr;
    int wybor;

    while (true)
    {
        cout << "#######################" << endl;
        cout << "1. Add Element         " << endl;
        cout << "2. Get element by id   " << endl;
        cout << "3. Edit" << endl;
        cout << "4. Erase" << endl;
        cout << "5. Size" << endl;
        cout << "6. Sort" << endl;
        cout << "9. End program         " << endl;
        cout << "#######################" << endl;
        cout << "->";
        cin >> wybor;
        
        switch (wybor)
        {
            case 1:
            {
                some_object object;
                int value;
                
                cout << "Jaka wartosc: ";
                cin >> value;
                object.setValue(value);
                arr.addElement(object);
                break;
            }
            case 2:
            {
                int index;
                
                cout << "Jakie id: ";
                cin >> index;
                some_object* object = arr.at(index);
                if (object)
                    cout << object->getValue() << endl;
                else
                    cout << "Nie udalo sie"<<endl;
                break;
            }
            case 3:
            {
                int index;
                int value;
                some_object object;

                cout << "Jakie id: ";
                cin >> index;
                cout << "Jaka wartosc: ";
                cin >> value;
                object.setValue(value);
                if (arr.edit(index, object))
                {
                    cout << "Powiodlo sie!"<<endl;
                }
                else
                {
                    cout << "Nie powiodlo sie!" << endl;
                }
                break;
            }
            case 4:
            {
                arr.erase();
                break;
            }
            case 5:
            {
                cout<<arr.size()<<endl;
                break;
            }
            case 6:
            {
                for (int i = 0; i < arr.size(); i++)
                {
                    cout << arr.at(i)->getValue() << endl;
                }
                arr.sort();
                cout << endl;
                for (int i = 0; i < arr.size(); i++)
                {
                    cout << arr.at(i)->getValue() << endl;
                }
            }
            case 9:
                return 0;
            default:
                break;
        }
    }
    return 0;
}
