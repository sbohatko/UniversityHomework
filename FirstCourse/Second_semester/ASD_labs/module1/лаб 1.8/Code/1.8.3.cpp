#include <iostream>
#include <iomanip>
using namespace std;
template<typename V>
struct Node
{
public:
    Node(V data = V(), Node<V>* next = nullptr) : Data(data), Next(next) {};

    Node<V>* Next;
    V Data;
};
template <typename T>
class List
{
private:
    Node<T>* start;
    Node<T>* last;
    int count{};



public:
    List()
    {
        count = 0;
        start = nullptr;
        last = nullptr;
    };
    Node<T>* operator[](int index) __const
    {
        Node<T>* element = start;
        for(int i = 0; i < index; i++)
            element = element -> Next;
        return element;
    };
    List(const List<T>& list) : List()
    {
        for(int i = 0; i < list.Count(); i++)
            push_back((list[i]) -> Data);
    };

    bool push_back(T element)
    {
        Node<T>* newElement = new Node<T>(element, nullptr);
        if(count == 0)
        {
            last = newElement;
            start = last;
        }
        else
        {
            last->Next = newElement;
            last = newElement;
        }
        ++count;
        return true;
    };

    void sort()
    {
        for(int i = 0; i < count; i++)
            for(int j = 0; j < count - 1; j++)
                if( ((*this)[j]) -> Data > ((*this)[j + 1]) -> Data )
                {
                    T element = ((*this)[j]) -> Data;
                    ((*this)[j]) -> Data = ((*this)[j + 1]) -> Data;
                    ((*this)[j + 1]) -> Data = element;
                }
    };

    int Count() __const
    {
        return count;
    };
    void Print()
    {
        for(int i = 0; i < count; i++)
        {
            cout << setw(4) << ((*this)[i]) -> Data;
            if (i % 20 == 19)
            {
                cout << endl;
            }
        }
    };
};

int main()
{
    srand(0);
    List<int> list{};
    for(int i = 0; i < 100; i++)
        list.push_back(rand() % 100);
    List<int> copy(list);
    list.sort();
    cout << "Original list: " << endl;
    copy.Print();
    cout << endl << "Sorted list: " << endl;
    list.Print();
    return 0;
}