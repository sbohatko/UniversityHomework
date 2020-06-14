#include <iostream>
#include <iterator>
#include <memory>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
template<typename T>
void MergeSort(T a[], size_t l)
{
    int checks = 0;
    int merge = 0;

    size_t BlockSizeIterator;
    size_t BlockIterator;
    size_t LeftBlockIterator;
    size_t RightBlockIterator;
    size_t MergeIterator;

    size_t LeftBorder;
    size_t MidBorder;
    size_t RightBorder;
    for (BlockSizeIterator = 1; BlockSizeIterator < l; BlockSizeIterator *= 2)
    {
        for (BlockIterator = 0; BlockIterator < l - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator)
        {
            merge++;
            LeftBlockIterator = 0;
            RightBlockIterator = 0;
            LeftBorder = BlockIterator;
            MidBorder = BlockIterator + BlockSizeIterator;
            RightBorder = BlockIterator + 2 * BlockSizeIterator;
            RightBorder = (RightBorder < l) ? RightBorder : l;
            int* SortedBlock = new int[RightBorder - LeftBorder];

            while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
            {
                if (a[LeftBorder + LeftBlockIterator] < a[MidBorder + RightBlockIterator])
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = a[LeftBorder + LeftBlockIterator];
                    LeftBlockIterator += 1;
                }
                else
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = a[MidBorder + RightBlockIterator];
                    RightBlockIterator += 1;
                }
            }
            while (LeftBorder + LeftBlockIterator < MidBorder)
            {
                SortedBlock[LeftBlockIterator + RightBlockIterator] = a[LeftBorder + LeftBlockIterator];
                LeftBlockIterator += 1;
            }
            while (MidBorder + RightBlockIterator < RightBorder)
            {
                SortedBlock[LeftBlockIterator + RightBlockIterator] = a[MidBorder + RightBlockIterator];
                RightBlockIterator += 1;
            }

            for (MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
            {
                a[LeftBorder + MergeIterator] = SortedBlock[MergeIterator];
            }
            delete SortedBlock;
        }
        cout<<"\nIteration ["<<checks<< "]: ";
        printArray(a,l);
        checks++;
    }
    cout<<"\nNumber of merges: "<< merge;
}
int main() {
    int n;
    char mode;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "1.Random fill\n"
            "2.Manual fill\n"
            "Choose mode: ";
    cin >> mode;
    switch (mode) {

        case '1':
            for (int i = 0; i < n; ++i) arr[i] = rand() % 100;
            cout << "Generated array: ";
            printArray(arr, n);
            break;

        case '2':
            for (int i = 0; i < n; i++) {
                cout << "\nEnter element: ";    //показать итерации
                cin >> arr[i];
            }

        default:
            break;
    }
    MergeSort(arr, n); //сортировка
    cout << "\nSorted array is ";
    printArray(arr, n);
    cout << endl;
}