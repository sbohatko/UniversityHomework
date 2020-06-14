#include <iostream>
using namespace std;

void Print(int arr[], int size) {
    for(int i = 0; i < size; ++i) cout << arr[i] << '\t';
}

int main() {
    int size, mode, check = 0, change = 0;
    bool ch = false;
    cout << "Enter array size: ";
    cin >> size;
    int *arr = new int[size];
    cout << "0. Random fill\n"
            "1. Manual fill\n"
            "Choose mode: ";
    cin >> mode;
    switch(mode) {
        case 0:
            for (int i = 0; i < size; ++i)
                arr[i] = rand() % 100;
            cout << "Generated array: ";
            Print(arr, size);
            cout << endl;
            break;
        case 1:
            cout << "Enter array: ";
            for (int i = 0; i < size; ++i)
                cin >> arr[i];
            break;
        default: break;
    }
    for(int i = 1; i < size; ++i) {
        cout<<"Step "<< i <<": ";
        ch = false;
        for(int j = 0; j < size - 1; ++j) {
            check++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j + 1], arr[j]);
                change++;
                ch = true;
            } }
        Print(arr, size); cout << endl;
        if (!ch) break;
    }
    cout << "Result: ";
    Print(arr, size);
    cout << endl <<"Number of iterations: "<< check << endl;
    cout << "Number of replaces: " << change << endl;
    return 0; }
