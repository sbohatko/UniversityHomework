#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void Print(vector<int> arr)
{
for(int i : arr)
    cout << i << " ";
cout << endl;
}
int Binary(vector<int>& arr, int beg, int end, int el, int& ch) {
    ch++;
    if (end < beg) return -1;
    int med = floor(beg + (end - beg) / 2);
    if(el == arr[med])
        return med;
    else if(el < arr[med])
        Binary(arr, beg, med - 1, el,ch);
    else if(el > arr[med])
        Binary(arr, med + 1, end, el,ch);
}
int main() {
int size, mode, ch = 0, el;
cout << "Enter size of array: "; cin >> size;
vector<int> arr(size);
cout << "1. Random fill\n"
        "2. Manual fill\n"
        "Choose mode: ";
cin >> mode;
switch(mode) {
    case 1: for(int i = 0;i<size; ++i) arr[i] = rand()%100;
    cout << "Generated array: ";
    sort(begin(arr), end(arr));
    Print(arr);
    break;
    case 2: cout << "Enter array: ";
        for(int i = 0; i < size; ++i) cin >> arr[i];
                break; default: break;
}
    cout << "Enter item to search: ";
    cin >> el;
    int ind = Binary(arr, 0, arr.size()-1, el, ch);
    cout << "Key: " << ind << endl;
    cout << "Compares: " << ch;
    return 0;
}

