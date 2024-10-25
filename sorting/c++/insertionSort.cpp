#include <iostream>
#include <vector>

using namespace std;

void insertionSort(int arr[], int n)
{
    int temp,j;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        { 
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}


int main() {
    int n;

    cout << "Enter length of array: "; 
    cin >> n;

    int items[n];

    cout << "Enter values: "; 
    for(int i = 0; i < n; i++) {
        cin >> items[i];
    }

    cout << "Before sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << items[i] << " ";
    }
    cout << "\n";

    insertionSort(items, n);

    cout << "After sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << items[i] << " ";
    }
    cout << "\n";

    return 0;
}
