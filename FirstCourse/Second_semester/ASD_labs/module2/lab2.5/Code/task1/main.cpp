#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Print(vector<int> arr) {
    for(int i = 0; i < arr.size(); ++i) cout << arr[i] << '\t';
    cout << endl;
}
int Linear(vector<int> arr, int el, int& ch)
{
    for(int i = 0; i < arr.size(); ++i) {
        ch++;
        if(arr[i] == el) return i; }
    return -1; }
int main() {
    int size, mode, ch = 0, el;
    cout << "Enter size of array: "; cin >> size;
    vector<int>
    arr(size);
    cout << "0. Random fill\n"
            "1. Manualfill\n"
            "Choose mode: "; cin >> mode;
    switch(mode) {
        case 0: for(int i = 0 ;i < size; ++i) arr[i] = rand()%100;
            cout << "Generated array: ";
            sort(begin(arr), end(arr));
            Print(arr);
            break;
        case 1: cout << "Enter array: ";
            for(int i = 0; i < size; ++i)
                cin >> arr[i];
            break;
        default: break; }
    cout << "Enter item to search: ";
    cin >> el;
    int ind = Linear(arr, el, ch);
    cout << "Key: " << ind << endl;
    cout << "Comparison: " << ch;
    return 0;
}
