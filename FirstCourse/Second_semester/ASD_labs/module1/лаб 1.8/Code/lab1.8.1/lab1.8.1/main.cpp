//
//  main.cpp
//  lab1.8.1
//
//  Created by Aleksandr Bogatko on 24.03.2020.
//  Copyright © 2020 Aleksandr Bogatko. All rights reserved.
//

#include <iostream>
using namespace std;
struct List
{
private:
    int *list = nullptr;
    int size, num;
public:
    List(int s)
    {
        list = new int(s);
        size = s;
        num = 0;
    }
    void Push(int el)
    {
        if(num < size)
        {
            list[num] = el;
            num++;
            cout<<"Element pushed";
        }else
        {
            cout<<"No space in list";
        }
    }
    void Insert(int el,int dx)
    {
        if(num <= size - 1){
            for(int i = num;i>(dx-1);i--)
            {
                list[i] = list[i-1];
                
            }
                list[dx-1] = el;
                num++;
            }
        }
    void Print()
    {
        for(int i = 0; i<num; i++)
        {
            cout<<list[i]<<"\t";
            
        }
        cout<<endl;
    }
    void Pop()
    {
        if(num>0)
        {
            list[num] = 0;
            num--;
        }
    }
    void Delete(int el)
    {
        if(num>0)
        {
            int pos = 0, ok = 0;
            for(int i=0; i<num; i++)
            {
                if(el == list[i])
                {
                    pos = i;
                    ok++;
                }
            }
            if(ok == 0)
            {
                cout<<"This element not in list";
            }
            for(int i = pos;i<num;i++)
            {
                list[i] = list[i+1];
            }
            list[num] = 0;
            num--;
        }
    }
    void Find(int el)
    {
        int ok = 0;
        for (int i = 0; i<num;i++)
        {
            if(el == list[i])
            {
                cout<<el<<"on the"<<i+1<<"position"<<endl;
                ok++;
            }
        }
        if(ok == 0)
        {
            cout<<"This element not in list";
        }
    }
    void Sort()
    {
        int k = 1, buf;
        while(k != 0)
        {
            k = 0;
            for(int i = 1;i < num; i++)
            {
                if(list[i] < list[i-1])
                {
                    buf = list[i-1];
                    list[i-1] = list[i];
                    list[i] = buf;
                    k++;
                }
            }
        }
    }
    void PushSort(int el)
    {
        Sort();
        Push(el);
        Sort();
    }
};
int main() {
    int op = 1, el = 0, dx = 0, size;
    string name;
    cout<<"1. Add element\n2. Insert element\n3. Delete element\n4. Delete end element\n"
    "5. Find element\n6. Sort list\n7. Insert element in sorted list\n8. Show list\n0. Exit\n";
    cout<<"Enter size: ";
    cin>>size;
    List lst = List(size);
    while(op!=0)
    {
        cout<<"\nChoose action: ";
        cin>>op;
        switch(op)
        {
            case 1: cout<<"Enter element:";
                cin>>el;
                lst.Push(el);
                break;
            case 2:cout<<"Enter element: ";
                cin>>el;
                cout<<"Enter position: ";
                cin>>dx;
                lst.Insert(el, dx);
                break;
            case 3:cout<<"Enter element:";
                cin>>el;
                lst.Delete(el);
                break;
            case 4: lst.Pop();
                break;
            case 5:cout<<"Enter element: ";
                lst.Find(el);
                break;
            case 6:lst.Sort();
                cout<<"Result: \n";
                lst.Print();
                break;
            case 7:cout<<"Enter element:";
                cin>>el;
                lst.PushSort(el);
                cout<<"Result:\n";
                lst.Print();
                break;
            case 8: lst.Print();
                break;
            default: cout<<"Choose command from 1 to 8.";break;
        }
    }
    return 0;
}
