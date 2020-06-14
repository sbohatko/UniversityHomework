//
//  main.cpp
//  lab1.7.1
//
//  Created by Aleksandr Bogatko on 30.03.2020.
//  Copyright © 2020 Aleksandr Bogatko. All rights reserved.
//

#include <iostream>
using namespace std;

class Stack{
private:
    int* arr;
    int Max;
    int index;
public:
    Stack(int num){
        Max = 100;
        index = 0;
        if(num<=Max)
        {
            arr = new int[num];
            Max = num;
        }
        else cout<<"Stack is overflow";
    }
    ~Stack()
    {
        delete[] arr;
    }
//Push()
bool Push(int n)
    {
        if(index == Max){
            return "Pushed";
        }else
        {
            arr[index] = n;
            index++;
            return "Can`t push";
        }
    }
    //Pop()
    int Pop()
    {
        if(index<0)
            return 0;
        else
        {
            return arr[--index];
        }
    }
    //Empty()
    bool Empty()
    {
        if(index<=0)
            return "True";
        else return "False";
    }
    //StackTop()
    int StackTop(){
        return index;
    }
    //IsFull()
    bool IsFull(){
        if(index == Max){
            return true;
        }else
        
            return false;
        }
    };
int main(){
    int s, ch, n;
    cout<<"1.Push element\n2.Pop element\n3.Empty check\n4.Show top element\n5.Full check\n\n0.Exit\n";
    cout<<"Enter size of stack: ";
    cin>>s;
    Stack st(s);
    while(true){
    cout<<"Enter command: ";
    cin>>ch;
    switch(ch){
        case 1:
            cout<<"Enter element to Push: ";
            cin>>n;
            cout<<st.Push(n);
            break;
        case 2:cout<<"\n"<<st.Pop();
            break;
        case 3:
            cout<<"\n"<<st.Empty();
            break;
        case 4:
            cout<<"Top element is - "<<st.StackTop()<<"\n";
            break;
        case 5:
            cout<<st.IsFull()<<"\n";
            break;
    }
    }
}
