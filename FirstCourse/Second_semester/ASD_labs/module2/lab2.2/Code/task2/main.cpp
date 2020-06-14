#include <iostream>
using namespace std;
void Print(int arr[], int size) {
    for(int i = 0; i < size; ++i)
        cout << arr[i] << '\t';
    cout << endl;
}
int Partition(int arr[], int begin, int end, int& check, int& change, int n){
    int p = arr[end];
    int j = begin;
    for (int i = begin; i < end; i++) {
        check++;
        if (arr[i] <= p){
            swap(arr[i], arr[j]); change++;
            j++;
        }
    }
    swap(arr[j], arr[end]); change++;
    Print(arr, n);
    return j;
}
void Sort(int arr[], int begin, int end, int& check, int& change, int n)
{
    if (begin < end){
        int j = Partition(arr, begin, end, check,change, n);
        Sort(arr, begin, j - 1, check, change, n);
        Sort(arr, j + 1, end, check, change, n);
    } }
int main() {
    int size, mode, check = 0, change = 0;
    cout << "Enter array size: ";
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
            for(int i = 0; i < size; ++i) cin >> arr[i];
            break;

            default: break;
    }
    int beg, end;
    beg = 0;
    end = size - 1;
    Sort(arr, beg, end, check, change, size);
    cout << "Result: ";
    Print(arr, size);
    cout << "Number of checks: " << check << endl;
    cout << "Number of replaces: " << change << endl;
    return 0;
}
