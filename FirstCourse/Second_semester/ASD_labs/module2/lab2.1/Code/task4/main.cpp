#include <iostream>;
using namespace std;

void Print(int arr[], int size) {
    for(int i = 0; i < size; ++i)
        cout << arr[i] << '\t';
}
int main() {
    int size, end, begin = 0, mode, check = 0, change = 0;
    bool ch = true;
    cout << "Enter array size: ";
    cin >> size;
    end = size - 1;
    int *arr = new int[size];
    cout << "0. Random fill\n"
            "1. Manual fill\n"
            "Choose mode: ";
    cin >> mode;
    switch(mode)
    {
        case 0:
            for(int i = 0; i < size; ++i) arr[i] = rand()%100;
            cout<< "Generated array: ";
            Print(arr, size);
            cout << endl;
        break;

        case 1: cout << "Enter array: ";
        for(int i = 0; i < size; ++i)
        cin >> arr[i];
        break;

        default: break;
    }
    int s = 1;
    while(begin < size && ch) {
        cout << "Step " << s << ": "; s++;
        Print(arr, size);
        ch = false;
        for (int i = 0; i < end; ++i) {
            check++;
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                change++;
                ch = true;
            }
        }
                end--;
                for (int i = end;i>begin;i--){
                    check++;
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                change++;
                ch = true;
            }
                }
        begin++;
        cout << endl;
    }
    cout << "Result: ";
    Print(arr, size);
    cout << endl << "Number of checks: " << check << endl;
    cout << "Number of replaces: " << change << endl;
    return 0;
}
