//
//  main.cpp
//  lab1.7.2
//
//  Created by Aleksandr Bogatko on 02.04.2020.
//  Copyright © 2020 Aleksandr Bogatko. All rights reserved.
//

#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
    Node* pNext;
    T data;

    Node(T data = T(), Node* pNext = nullptr)
    {
        this->data = data;
        this->pNext = pNext;
    }
};
template<typename T>
class List
{
public:
    List();
    ~List();
    void pop_front();

    void push_back(T data);

    void clear();

    int GetSize() { return Size; }

    T& operator[](const int index);

    void push_front(T data);

    void insert(T data, int index);

    void removeAt(int index);

    void pop_back();
private:
    Node<T> *head;
    int Size;
};
template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}


template<typename T>
List<T>::~List()
{
    clear();
}


template<typename T>
void List<T>::pop_front()
{
    Node<T>* temp = head;

    head = head->pNext;

    delete temp;

    Size--;

}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;

        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);

    }

    Size++;
}

template<typename T>
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}


template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;

    Node<T>* current = this->head;

    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

template<typename T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data, head);
    Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{

    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node<T>* previous = this->head;

        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node<T>* newNode = new Node<T>(data, previous->pNext);

        previous->pNext = newNode;

        Size++;
    }
}
template<typename T>
void List<T>::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        Node<T>* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }
}
template<typename T>
void List<T>::pop_back()
{
    removeAt(Size - 1);
}
int main()
{
    int SizeLimit = 10;
    int opperation,element, opperation2;
    List<int> lst;
    while (true)
    {
        cout << "Tip: Stack limit 10 elements" << endl;
        cout << "1.Add Element" << endl;
        cout << "2.Show Queue" << endl;
        cout << "3.Delete Element" << endl;
        cin >> opperation;
        switch(opperation){
            case 1:
            if (lst.GetSize() == SizeLimit)
            {
                cout << "Stack is full" << endl;
            }
            else
            {
                cout << "Enter element:";
                cin >> element;
                lst.push_front(element);
            }
            cout << "Do you wish to continie? 1=continie 2=exit:";
            cin >> opperation2;
            if (opperation2 == 1)
            {
                continue;
            }
            if (opperation2 == 2)
            {
                break;
            }
            else
            {
                cout << "Enter existed operation" << endl;
            }
                break;
            case 2:
        
            if (lst.GetSize() == 0)
            {
                    cout << "Stack empty" << endl;
            }
            else
            {
                for (int i = 0; i < lst.GetSize(); i++)
                {
                    cout << lst[i] << " ";
                }
            }
            cout << endl;
            cout << "Do you wish to continie? 1=continie 2=exit:";
            cin >> opperation2;
            if (opperation2 == 1)
            {
                continue;
            }
            if (opperation2 == 2)
            {
                break;
            }
            else
            {
                cout << "Enter existed operation" << endl;
            }
                break;
            case 3:
        
            if (lst.GetSize() == 0)
            {
                    cout << "Stack empty" << endl;
            }
            else
                lst.pop_back();
            cout << "Do you wish to continie? 1=continie 2=exit:";
            cin >> opperation2;
            if (opperation2 == 1)
            {
                continue;
            }
            if (opperation2 == 2)
            {
                break;
            }
            else
            {
                cout << "Enter existed operation" << endl;
            }

        
                break;
        }
    }
    return 0;
}
