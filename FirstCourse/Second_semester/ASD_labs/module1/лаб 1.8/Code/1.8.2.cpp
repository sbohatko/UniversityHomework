#include <iostream>
using namespace std;
template <typename T>
struct List
{
private:
    template <typename V>
    struct Node
    {
    public:
        V data;
        Node *next;
        Node(V data = V(), Node *next = nullptr)
        {
            this->data = data;
            this->next = next;
        };
    };
    int size;
    Node<T> *start;
public:
    List()
    {
        size = 0;
        start = nullptr;
    };
    void push_back(T data)
    {
        if (start == nullptr)
        {
            start = new Node<T>(data);
        }
        else
        {
            Node<T> *curr = this->start;
            while (curr->next != nullptr)
            {
                curr = curr->next;
            }
            curr->next = new Node<T>(data);
        }
        size++;
    }
    int getSize() {return size;}
    T& operator[](const int index)
    {
        int count = 0;
        Node<T> *curr = this->start;
        while (curr != nullptr)
        {
            if (count == index)
            {
                return curr->data;
            }
            curr = curr->next;
            count++;
        }
         void pop_front()
    {
        Node<T> *temp = start;
        start = start->next;
        delete temp;
        size--;
    }
    void clear()
    {
        while(size)
        {
            pop_front();
        }
    }
    void push(T data)
    {
        start = new Node<T> (data, start);
        size++;
    }
    void pop()
    {
        remove(size - 1);
    }
    void insert(T data, int index)
    {
        if (index == 0)
        {
            push(data);
        }
        else
        {
            Node<T> *prev = this->start;
            for (int i  = 0; i < index - 1; i++)
            {
                prev = prev->next;
            }
            Node<T> *newN = new Node<T>(data, prev->next);
            prev->next = newN;
        }
        size++;
    }
    void remove(int index)
    {
        if (index == 0)
        {
            pop_front();
        } else
        {
            Node<T> *prev = this->start;
            for (int i = 0; i < index - 1; i++)
            {
                prev = prev->next;
            }
            Node<T> *toDel = prev->next;
            prev->next = toDel->next;
            delete toDel;
            size--;
        }
    }
    void sort()
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if((*this)[j] > (*this)[j + 1])
                {
                    T buf = (*this)[j];
                    (*this)[j] = (*this)[j + 1];
                    (*this)[j + 1] = buf;
                }
            }
        }
    }
        void push_sort(T data)
    {
        sort();
        push_back(data);
        sort();
    }
    void find(T data)
    {
        int ok = 0;
        for (int i = 0; i < size; i++)
        {
            if ((*this)[i] == data)
            {
                cout << (*this)[i] << "on the" << i << "position";
                ok++;
            }
        }
        if (ok == 0)
        {
            cout << "Element not in list";
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << (*this)[i] << '\t';
        }
        cout << endl;
    }
    ~List()
    {
        clear();
    };
};
int main() {
    int op = 1, el, dx;
    string name;
    cout << "1. Add element\n2. Insert element\n3. Delete element\n"
            "4. Delete element from the end of list\n5. Find element\n"
            "6. Sort list\n7. Insert element in sorted list\n8 Show elements\n0. Exit\n";
    List <int> f;
    while (op != 0)
    {
        cout << "Choose command: ";
        cin >> op;
        switch (op)
        {
            case 1: cout << "Enter element: ";
                cin >> el;
                f.push_back(el);
                break;
            case 2: cout << "Enter element: ";
                cin >> el;
                cout << "Enter the index to insert: ";
                cin >> dx;
                f.insert(el, dx - 1);
                break;
            case 3: cout << "Enter index of element: ";
                cin >> dx;
                f.remove(dx - 1);
                break;
            case 4: f.pop();
                break;
            case 5: cout << "Enter element: ";
                cin >> el;
                f.find(el);
                break;
            case 6: f.sort();
                cout << "Result: " << endl;
                f.print();
                break;
            case 7: cout << "Enter element: ";
                cin >> el;
                f.push_sort(el);
                cout << "Result: " << endl;
                f.print();
                break;
            case 8: f.print();
            default: break;
        }
    }
    return 0;
}
};