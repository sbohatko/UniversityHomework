#include<iostream>
#include <vector>
using namespace std;

void Print(vector<int>& arr) {
    for(int i : arr)
        cout << i <<" ";
}
void Merge(vector<int>& b, vector<int>& c, vector<int>& d, vector<int>& arr, int& check)
{
    vector<int> buf;
    int i = 0, j = 0, k = 0;
    check++;
    while (i != b.size() && j != c.size()) {
        check++;
        if (b[i] < c[j])
            buf.push_back(b[i++]);
        else buf.push_back(c[j++]);
        k++;
    }
    if (i != b.size())
        while (i < b.size())
        {
            check++;
            buf.push_back(b[i++]);
        }
    else
        while (j < c.size()) {
            check++;
            buf.push_back(c[j++]); }
    cout << "Merging first two stripes: ";
    Print(buf);
    cout << endl;
    i = 0, j = 0, k = 0;
    check++;
    while (i != buf.size() && j != d.size()) {
        check++;
        if (buf[i] < d[j])
            arr[k] = buf[i++];
        else arr[k] = d[j++];
        k++;
    }
    if (i != buf.size())
        while (i < buf.size()) {
            check++;
            arr[k++] = buf[i++]; }
    else
        while (j < d.size()) {
            check++;
            arr[k++] = d[j++]; }
    cout << "After merging: ";
        Print(arr);
    cout << endl;
}
void MergeSort(vector<int>& arr, int& check) {
    vector<int> b, c, d;
    int tmp = -100;
    do
    {
        int count = 0;
        for (int & i : arr) {
            if (tmp > i) count++;
            if (count % 3 == 0) b.push_back(i);
            else if (count % 3 == 1) c.push_back(i);
            else if (count % 3 == 2) d.push_back(i);
            tmp = i;
        }
        if (c.empty() && b.empty() || c.empty() && b.empty() || b.empty() && d.empty())
            return;
        cout <<"First stripe: ";
        Print(b);
        cout << endl;
        cout << "Second stripe: ";
        Print(c);
        cout << endl;
        cout << "Third stripe: "; Print(d);
        cout << endl;
        Merge(b, c, d, arr, check);
        b.clear();
        c.clear();
        d.clear();
    } while (true); }
int main() {
    int size, r, mode, check = 0; cout << "Enter the number of elements: ";
    cin >> size;
    vector<int> arr;
    cout << "1. Random fill\n"
            "2. Manual fill\n"
            "Choose mode: ";
    cin >> mode;
    switch(mode) {
        case 1: for(int i = 0;i< size; ++i) arr.push_back(rand()%100);
            cout << "Generated array: "; Print(arr);
            cout << endl;
            break;
        case 2: cout << "Enter array: ";
        for(int i = 0; i < size; ++i) {
        cin >> r;
        arr.push_back(r); }
            break; default: break;
    }
    cout << "Array before Sorting: ";
    Print(arr);
    cout << endl;
    MergeSort(arr, check);
    cout << "Array after Sorting: ";
    Print(arr);
    cout << endl;
    cout << "Comparisons: " << check;
    return 0; }
