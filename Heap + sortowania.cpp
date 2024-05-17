//ALGO2 IS1 222B LAB07
//Marcel Basa 
//bm50926@zut.edu.pl

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template<typename T>
class Array
{
private:
    int maxCapacity;
    int capacity;
    int capacityRate;
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
        capacityRate = 2;
        container = new T[maxCapacity];
    }

    void addElement(T element)
    {
        if (capacity >= maxCapacity)
        {
            maxCapacity *= capacityRate;
            rebuildArray(maxCapacity);
            container[capacity] = element;
            capacity++;
        }
        else
        {
            container[capacity] = element;
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
        return capacity - 1;
    }

    void sort()
    {
        for (int i = 0; i < capacity; i++)
        {
            for (int j = 1; j < capacity - i; j++)
            {
                if (container[j-1] > container[j])
                    swap(container[j-1], container[j]);
            }
        }
    }

    ~Array()
    {
        delete[]container;
    }

    void decrementCapacity()
    {
        capacity--;
    }

    void setCapacity(int x)
    {
        capacity = x;
    }
};
template<typename T>
class Styrta
{
    Array<T> arr;

public:
    void add(T value)
    {
        arr.addElement(value);
        int parent_index = (arr.size() - 1) / 2;
        int last_index = arr.size();
        while (*arr.at(parent_index) < value)
        {
            swap(*arr.at(last_index), *arr.at(parent_index));
            last_index = parent_index;
            parent_index = (parent_index - 1) / 2;
        }
    }
    void heapSort()
    {
        int size = arr.size();
        for (int i = 0; i < size; i++)
        {
            swap(*arr.at(0), *arr.at(arr.size()));
            arr.decrementCapacity();
            int leftChild = 1;
            int rightChild = 2;
            int current = 0;

            while (arr.at(leftChild) && *arr.at(leftChild) > *arr.at(current) || (arr.at(rightChild) && *arr.at(rightChild) > *arr.at(current)))
            {
                if ((arr.at(leftChild) && !arr.at(rightChild)) || *arr.at(leftChild) > *arr.at(rightChild))
                {
                    swap(*arr.at(current), *arr.at(leftChild));
                    current = leftChild;
                    leftChild = 2 * current + 1;
                    rightChild = 2 * current + 2;
                }
                else
                {
                    swap(*arr.at(current), *arr.at(rightChild));
                    current = rightChild;
                    leftChild = 2 * current + 1;
                    rightChild = 2 * current + 2;
                }
            }
        }
        arr.setCapacity(size+1);
    }
    void show()
    {
        for (int i = 0; i <= arr.size(); i++)
        {
            cout << *arr.at(i) << " ";
        }
    }
    void erase()
    {
        arr.erase();
    }
    ~Styrta()
    {
        erase();
    }
};
template<typename T>
void sortowaniePrzezZliczanie(T* arr, int arrSize, int wielkoscZbioru)
{
    T* countArray = new T[wielkoscZbioru];

    for (int i = 0; i < wielkoscZbioru; i++)
        countArray[i] = 0;

    for (int i = 0; i < arrSize; i++)
        countArray[arr[i]]++;

    for (int i = 0; i < wielkoscZbioru; i++)
    {
        while (countArray[i] != 0)
        {
            cout << i << " "; 
            countArray[i]--;
        }
    }
    delete[] countArray;
}
template<typename T>
void sortowaniePrzezKubelkowanie(T* arr, int arrSize)
{
    Array<T> charArray[10];
    for (int i = 0; i < arrSize; i++)
    {
        string number = to_string(arr[i]);
        number = number[2];
        int fistDigit = stoi(number);

        charArray[fistDigit].addElement(arr[i]);
    }
    
    for (int i = 0; i < arrSize; i++)
    {
        charArray[i].sort();
        for (int j = 0; j <= charArray[i].size(); j++)
            cout << *charArray[i].at(j) << " ";
    }
}

int main()
{
    srand(time(0));

    // HEAP SORT
    /*Styrta<int> styrta;
    for (int i = 0; i < 10; i++)
        styrta.add(0 + (rand() % 100));
    cout << "Before: ";
    styrta.show();
    styrta.heapSort();
    cout << endl << "After: ";
    styrta.show();*/

    //Sortowanie przez zliczanie
    /*int const size = 10;
    int numbers = 100;
    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i]=(0 + (rand() % numbers));
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    sortowaniePrzezZliczanie<int>(arr, size, numbers);*/

    //Sortowanie przez kubelkowanie
    int const size = 10;
    float arr[size];
    for (int i = 0; i < size; i++)
        arr[i]= float(rand()) / float(RAND_MAX);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    sortowaniePrzezKubelkowanie<float>(arr, size);
}