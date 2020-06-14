#include <iostream>
using namespace std;

void Print(int arr[], int size) {
    for(int i = 0; i < size; ++i) cout << arr[i] << '\t';
}
int main() {
    int size, mini, mode, check = 0, change = 0;
    bool ch = false;
    cout << "Enter array size: ";
    cin >> size;
    int *arr = new int[size];
    cout << "0. Random fill\n"
            "1. Manual fill\n"
            "Choose mode: ";
    cin >> mode;
    switch (mode) {
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
        default:
            break;
    }
    for (int i = 0; i < size - 1; ++i) {
        cout << "Step " << i + 1 << ": ";
        mini = i;
        for (int j = i + 1; j < size; ++j) {
            check++;
            if (arr[j] < arr[mini]) {
                mini = j;
                ch = true;
            }
        }
        if (ch) {
            swap(arr[i], arr[mini]);
            change++;
        }
        Print(arr, size);
        cout << endl;
    }
    cout << "Result: ";
    Print(arr, size);
    cout << endl << "Number of iterations: " << check << endl;
    cout << endl << "Number of replaces: " << change << endl;
    return 0;
}
