#include <iostream>
#include <cstdlib>

using namespace std;
void Print(int arr[], int size) {
    for(int i = 0; i < size; ++i) cout << arr[i] << '\t';
}
int main() {
    int size, key, check = 0, change = 0, mode;
    cout << "Enter array size: ";
    cin >> size;
    int *arr = new int[size];
    cout << "0. Random fill\n"
            "1. Manual fill\n"
            "Choose mode: ";
    cin >> mode;
    switch(mode) {
        case 0: for(int i = 0; i < size; ++i) arr[i] = rand()%100;
            cout << "Generated array: "; Print(arr, size);
            cout << endl;
            break;

        case 1: cout << "Enter array: "; for(int i = 0; i < size; ++i)
        cin >> arr[i]; break;

        default: break; }
    for(int i = 1; i < size; ++i) {
        cout << "Step " << i << ": "; int j;
        key = arr[i];
        j = i - 1;
        check++;
        while(j >= 0 && arr[j] > key) {
            check++;
            change++;
            arr[j + 1] = arr[j]; j -= 1;
        }
        change++;
        arr[j + 1] = key; Print(arr, size); cout << endl;
    }
    cout << "Result: ";
    Print(arr, size);
    cout << endl << "Number of checks: " <<
         check << endl;
    cout << "Number of replaces: " <<
         change << endl; return 0;
}