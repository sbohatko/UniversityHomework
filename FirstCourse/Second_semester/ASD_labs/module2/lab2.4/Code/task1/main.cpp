#include<iostream>
#include <vector>
using namespace std;

void Print(vector<int>& arr) {
    for(int i : arr)
        cout<<i<<" ";
}
void Merge(vector<int>& b, vector<int>& c, vector<int>& arr, int& check)
{
    int i = 0, j = 0, k = 0;
    check++;
    while (i != b.size() && j != c.size()) {
        check++;
        if (b[i] < c[j]) arr[k] = b[i++]; else arr[k] = c[j++];
        k++;
    }
    check++;
    if (i != b.size())
        while (i < b.size()) {
            check++;
            arr[k++] = b[i++]; }
    else
        while (j < c.size()) {
            check++;
            arr[k++] = c[j++]; }
    cout << "After merging: "; Print(arr);
    cout << endl;
}
void MergeSort(vector<int>& arr, int& check)
{
    vector<int> b, c;
    int tmp = -100;
    do
    {
        int count = 0;
        for (int & i : arr) {
            if (tmp > i) count++;
            if (count % 2 == 0) b.push_back(i);
            else if (count % 2 == 1) c.push_back(i);
            tmp = i; }
        if (c.empty() || b.empty())
            return;
            cout <<"First stripe: ";
        Print(b);
        cout << endl;
        cout << "Second stripe: ";
        Print(c);
        cout << endl;
        Merge(b, c, arr, check);
        b.clear();
        c.clear();
    } while (true);
}
int main() {
    int size, r, mode, check = 0;
    cout << "Enter the number of elements: ";
    cin >> size;
    vector<int> arr; //create an array with given number of elements
    cout << "1. Random fill\n 2. Manual fill\nChoose mode: ";
    cin >> mode; switch(mode) {
        case 1: for(int i = 0; i < size; ++i)
                arr.push_back(rand()%100); cout << "Generatedarray: ";
            Print(arr);
            cout << endl; break;
        case 2: cout << "Enter array: ";
            for(int i = 0; i < size; ++i)
            {
                cin >> r;
                arr.push_back(r); }

            break; default: break;
    }
    cout << "Array before Sorting: "; Print(arr);
    cout << endl; MergeSort(arr,check);
    cout << "Array after Sorting: "; Print(arr);
    cout << endl;
    cout << "Comparisons: " << check;
    return 0; }
