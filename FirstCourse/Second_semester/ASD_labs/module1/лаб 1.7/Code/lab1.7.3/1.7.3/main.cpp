//
//  main.cpp
//  1.7.3
//
//  Created by Aleksandr Bogatko on 31.03.2020.
//  Copyright © 2020 Aleksandr Bogatko. All rights reserved.
//
#include <iostream>
#include <new>
using namespace std;

template <typename T>
class Queue
{
private:
    T* p;
    int count;

public:
    Queue()
    {
        count = 0;
    }

    Queue(const Queue& obj)
    {
        count = obj.count;

        try {
            p = new T[count];
            for (int i = 0; i < count; i++)
                p[i] = obj.p[i];
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;
            count = 0;
        }
    }

    void Push(T item)
    {
        T* p2;
        p2 = p;

        try {
            p = new T[count + 1];
            for (int i = 0; i < count; i++)
                p[i] = p2[i];
            p[count] = item;
            count++;
            if (count > 1)
                delete[] p2;
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;
            p = p2;
        }
    }
    T Pop()
    {
        if (count == 0)
            return 0;
        T item;
        item = p[0];
        try {
            T* p2;
            p2 = new T[count - 1];
            count--;
            for (int i = 0; i < count; i++)
                p2[i] = p[i + 1];
            if (count > 0)
                delete[] p;
            p = p2;
            return item;
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;
            return 0;
        }
    }
    Queue& operator=(const Queue& obj)
    {
        T* p2;
        try {
            p2 = new T[obj.count];
            if (count > 0)
                delete[] p;
            p = p2;
            count = obj.count;
            for (int i = 0; i < count; i++)
                p[i] = obj.p[i];
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;
        }
        return *this;
    }
    ~Queue()
    {
        if (count > 0)
            delete[] p;
    }
    bool IsEmpty()
    {
        return count == 0;
    }
    bool IsFull(int x)
    {   if (x == count)
        return true;
    else return false;
    }
};
int main()
{ int s, n, ch;
    Queue<int> q;
    cout<<"1.Push\n2.Pop\n3.IsEmpty\n4.IsFull\n";
    cout<<"Enter size: ";
    cin>>s;
    while(true){
    cout<<"\nChoose command:";
    cin>>ch;
    switch (ch){
        case 1: cout<<"Enter element to push: ";
            cin>>n;
            q.Push(n);
            break;
        case 2:cout<<q.Pop();
            break;
        case 3:cout<<q.IsEmpty();
            break;
        case 4: cout<<q.IsFull(s)<<"\n";
            break;
        }
    }
}
