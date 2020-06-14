#include <iostream>
using namespace std;
void Print(int arr[], int size) {
    for(int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;}
int Max(int arr[], int size) {
    int max = arr[0];
    for(int i = 1; i < size; ++i)
        if(arr[i] > max)
            max = arr[i];
    return max;
}
void CSort(int arr[], int size, int div) {
    int *output = new int[size];
    int count[10] = {0};
    for(int i = 0; i < size; ++i)
        count[(arr[i] / div) % 10]++;
    for(int i = 1; i < 10; ++i)
        count[i] += count[i - 1];
        for(int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / div) % 10] - 1] = arr[i];
        count[(arr[i] / div) % 10]--; }
    for(int i = 0; i < size; i++)
        arr[i] = output[i]; }
void Radix(int arr[], int size) {
    int m = Max(arr, size);
    int s= 0;
    for(int div = 1; m / div > 0; div *= 10) {
        cout << "Step " << s + 1 << ": ";
        s++;
        CSort(arr, size, div);
        Print(arr, size);}
}
int main() {
    int size, mode;
    cout << "Enter array size: ";
    cin >> size;
    int *arr = new int[size];
    cout << "0. Random fill\n"
            "1. Manual fill\n"
            "Choose mode: ";
    cin >> mode;
    switch(mode) {
        case 0:
            for(int i = 0; i < size; ++i)
                arr[i] = rand()%1000;
            cout << "Generated array: ";
            Print(arr, size);
            break;
        case 1: cout << "Enter array: ";
            for(int i = 0; i < size; ++i)
                cin >> arr[i];
            break;
        default: break; }
    Radix(arr, size);
    cout << "Result: ";
    Print(arr, size);
    return 0;
}
