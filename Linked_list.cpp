#include <iostream>
#include <string>

using namespace std;


class Some_object
{
public:
    int field_1 = 69;
    char field_2 = 'j';

    void AddValues()
    {
        cout << "field_1 <int>: ";
        cin >> field_1;
        cout << "field_2 <char>: ";
        cin >> field_2;
    }
    void ShowValues()
    {
        cout << "field_1: " << field_1 << endl;
        cout << "field_2: " << field_2 << endl;
    }
    int GetField_1() const { return field_1; }
    char GetField_2() const { return field_2; }

};

template<typename Type>
class Linked_list
{
public:
    class Element
    {
    public:
        int id;
        Element* next = nullptr;
        Element* prev = nullptr;

        Type date;
    };

    Element* head = nullptr;
    Element* tail = nullptr;
    int index = 0;

    void AddToBack(Element* object)
    {
        if (head == nullptr)
        {
            object->id = index;
            head = object;
            tail = object;
        }
        else
        {
            tail->next = object;
            tail->next->prev = tail;
            tail->next->id = index;
            tail = tail->next;
        }
        index++;
        cout << "Dodano element!" << endl;
    }

    void AddToFront(Element* object)
    {
        if (head == nullptr)
        {
            object->id = index;
            head = object;
            tail = object;
        }
        else
        {
            head->prev = object;
            head->prev->next = head;
            head->prev->id = index;
            head = head->prev;
        }
        index++;
        cout << "Dodano element!" << endl;
    }

    void ShowList()
    {
        Element* start = head;
        if (start == nullptr)
        {
            cout << "Lista jest pusta!" << endl;
            return;
        }
        while (start != nullptr)
        {
            cout << "ID: " << start->id << endl;
            start->date.ShowValues();
            cout << endl;
            start = start->next;
        }
    }

    void EraseList()
    {
        if (head == nullptr) return;
        Element* start = tail;
        while (start->prev != nullptr)
        {
            start = start->prev;

            delete start->next;

        }
        head = nullptr;
        tail = nullptr;
        index = 0;
        cout << "Usunieto elementy!" << endl;
    }

    void EraseFirst()
    {
        if (head == nullptr) return;
        Element* start = head;
        if (start->next)
        {
            head = start->next;
            start->next->prev = nullptr;
        }
        else
        {
            head = nullptr;
            tail = nullptr;
            index = 0;
        }
        delete start;
        cout << "Usunieto pierwszy element!" << endl;
    }

    void EraseLast()
    {
        if (tail == nullptr) return;
        Element* start = tail;
        if (start->prev)
        {
            tail = start->prev;
            start->prev->next = nullptr;
        }
        else
        {
            head = nullptr;
            tail = nullptr;
            index = 0;
        }
        delete start;
        cout << "Usunieto ostatni element!" << endl;
    }

    Element* GetByID(int id)
    {
        Element* start = head;
        if (start == nullptr) return nullptr;
        while (start != nullptr)
        {
            if (id == start->id)
            {
                return start;
            }
            start = start->next;
        }
        return nullptr;
    }

    bool EraseByID(int id)
    {
        Element* start = head;
        if (start == nullptr) return false;
        while (start != nullptr)
        {
            if (id == start->id)
            {
                if (start->next == nullptr && start->prev == nullptr)
                {
                    delete start;
                    head = nullptr;
                    tail = nullptr;
                    index = 0;
                }
                else if (start->next == nullptr)
                {
                    start->prev->next = nullptr;
                    tail = start->prev;
                    delete start;
                }
                else if (start->prev == nullptr)
                {
                    start->next->prev = nullptr;
                    head = start->next;
                    delete start;
                }
                else if (start->next && start->prev)
                {
                    start->prev->next = start->next;
                    start->next->prev = start->prev;
                    delete start;
                }
                return true;
            }
            start = start->next;
        }
        return false;
    }

    Element* GetByValues(Element* object)
    {
        Element* start = head;
        if (start == nullptr) return nullptr;
        while (start != nullptr)
        {
            if (object->date.GetField_1() == start->date.GetField_1() && object->date.GetField_2() == start->date.GetField_2())
            {
                return start;
            }
            start = start->next;
        }
        return nullptr;
    }

    void Edit(int id)
    {
        Element* start = head;
        if (start == nullptr) return;
        while (start != nullptr)
        {
            if (id == start->id)
            {
                start->date.AddValues();
            }
            start = start->next;
        }
    }
};

void ShowMenu()
{
    cout << endl << "#########################" << endl;
    cout << "1.  Add element to front" << endl;
    cout << "2.  Add element to back" << endl;
    cout << "3.  Show list" << endl;
    cout << "4.  Erase all elements" << endl;
    cout << "5.  Erase first element" << endl;
    cout << "6.  Erase last element" << endl;
    cout << "7.  Erase element by ID" << endl;
    cout << "8.  Get element by ID" << endl;
    cout << "9.  Get element by values" << endl;
    cout << "10. Edit element by ID" << endl;
    cout << endl << "0. Quit" << endl;
    cout << "#########################" << endl;
}

int main()
{
    Linked_list<Some_object>* List = new Linked_list<Some_object>;
    int select;

    while (true)
    {
        ShowMenu();

        cout << "->";
        cin >> select;
        switch (select)
        {
        case 1:
        {
            Linked_list<Some_object>::Element* Object = new Linked_list<Some_object>::Element;
            Object->date.AddValues();
            List->AddToFront(Object);
            break;
        }
        case 2:
        {
            Linked_list<Some_object>::Element* Object = new Linked_list<Some_object>::Element;
            Object->date.AddValues();
            List->AddToBack(Object);
            break;
        }
        case 3:
        {
            List->ShowList();
            break;
        }
        case 4:
        {
            List->EraseList();
            break;
        }
        case 5:
        {
            List->EraseFirst();
            break;
        }
        case 6:
        {
            List->EraseLast();
            break;
        }
        case 7:
        {
            int id;
            List->ShowList();
            cout << "Jakie id: ";
            cin >> id;
            if (List->EraseByID(id))
                cout << "Udalo sie usunac element!" << endl;
            else
                cout << "Nie udalo sie usunac elementu!" << endl;
            break;

        }
        case 8:
        {
            int id;
            List->ShowList();
            cout << "Jakie id: ";
            cin >> id;
            Linked_list<Some_object>::Element* Object = List->GetByID(id);
            if (Object)
                Object->date.ShowValues();
            else
                cout << "Element nie istnieje!" << endl;
            break;
        }
        case 9:
        {
            List->ShowList();
            Linked_list<Some_object>::Element* Object = new Linked_list<Some_object>::Element;
            Object->date.AddValues();
            Linked_list<Some_object>::Element* Result = List->GetByValues(Object);
            if (Result)
                Result->date.ShowValues();
            else
                cout << "Element nie istnieje!" << endl;
            delete Object;
            break;
        }
        case 10:
        {
            int id;
            List->ShowList();
            cout << "Jakie id: ";
            cin >> id;
            List->Edit(id);
            break;
        }
        case 0:
        {
            List->EraseList();
            delete List;
            return 0;
        }
        default:
        {
            cout << "Nie ma takiej opcji!" << endl;
            break;
        }
        }
    }

    return 0;
}
