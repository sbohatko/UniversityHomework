#include <iostream>
using namespace std;

void Print(int arr[], int size) {
for (int i = 0; i < size; ++i)
    cout << arr[i] << '\t';
    cout << endl;
}

void ShellSort(int arr[], int size, int& check,int &change)
{
    for(int step = size / 2; step > 0;step/=2){
    for (int i = step;i<size;i++){
        int temp = arr[i];
        int j;
    for(j = i; j>=step && arr[j-step] >temp;j-=step){
        arr[j]=arr[j-step];
        change++;
    }
    arr[j] = temp;
    check++;
    }
    Print(arr,size);
    }
}

int main() {
int size, mode, check = 0, change = 0; cout << "Enter array size: ";
cin >> size;
int *arr = new int[size];
cout << "0. Random fill\n"
        "1. Manual fill\n"
        "Choose mode: ";
cin >> mode;
switch(mode) {
        case 0: for(int i = 0; i < size; ++i)
            arr[i] = rand()%100;
        cout << "Generated array: ";
        Print(arr, size);
        break;
        case 1: cout << "Enter array: ";
        for(int i = 0; i < size; ++i)
            cin >> arr[i];
        break;

        default: break;
}
    ShellSort(arr, size, check, change);
    cout << "Result: ";
    Print(arr, size);
    cout << "Number of checks: " << check << endl;
    cout << "Number of replaces: " << change << endl;
return 0;
}
