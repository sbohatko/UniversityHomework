#include <iostream>
using namespace std;
void Print(int arr[], int size) {
    for(int i = 0; i < size; ++i)
        cout << arr[i] << '\t';
    cout << endl; }
int main() {
    int size, mode, count = 0, check = 0,
            entry = 0;
    cout << "Enter array size: ";
    cin >> size;
    int *arr = new int[size];
    int *res = new int[size] {0};
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
                cin >>arr[i];
        break;

            default: break;
    }
    for(int i = 0; i < size; ++i) {
        cout << "Step " << i + 1 << ": "; count = 0;
        for(int j = 0; j < size; j++) {
            if (arr[i] > arr[j])
                count++;
            if(arr[i] == arr[j])
            {
                entry = 0;
                for(int k = 0; k < size; k++)
                    if(res[k] == arr[i])
                        ++entry;
            }
        }
        res[count + entry] = arr[i];
        Print(res, size);
    }
    cout << "Result: ";
    Print(res, size);
    return 0;
}

