#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}



void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
void heapSort(int arr[], int n)
{   int reps = 0; int checks = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        cout<<"\nInteration ["<<reps<<"]: ";
        printArray(arr, n);
        reps++;
    }
cout<<"\nNumber of replaces: "<< reps<<"\n";
}

int main()
{
    int n;
    char mode;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    cout<<"1.Random fill\n"
          "2.Manual fill\n"
          "Choose mode: ";
    cin>>mode;
    switch(mode){

        case'1':
            for(int i = 0; i < n; ++i) arr[i] = rand()%100;
            cout << "Generated array: ";
            printArray(arr, n);
            heapSort(arr,n);
            cout << "\nSorted array is ";
            printArray(arr, n);
            cout << endl;
            break;

        case'2':
            for(int i = 0;i<n;i++) {
                cout << "\nEnter element: ";    //показать итерации
                cin >> arr[i];
            }
            heapSort(arr,n);
            cout << "Sorted array is: \n";
            printArray(arr, n);
            cout<<endl;
            break;

        default:break;
    }


}
