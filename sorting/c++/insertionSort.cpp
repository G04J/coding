#include <iostream>
#include <vector>

using namespace std;

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    int temp, j;

    // Iterate over the array starting from index 1
    for (int i = 1; i < n; i++) {
        temp = arr[i];  // Store the current element
        j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than temp
        while (j >= 0 && arr[j] > temp) { 
            arr[j + 1] = arr[j];  // Move element one position ahead
            j = j - 1;
        }
        arr[j + 1] = temp;  // Insert temp at its correct position
    }
}

int main() {
    int n;

    // Input: Size of the array
    cout << "Enter length of array: "; 
    cin >> n;

    int items[n];

    // Input: Array elements
    cout << "Enter values: "; 
    for (int i = 0; i < n; i++) {
        cin >> items[i];
    }

    // Display the array before sorting
    cout << "Before sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << items[i] << " ";
    }
    cout << "\n";

    // Call insertionSort function
    insertionSort(items, n);

    // Display the array after sorting
    cout << "After sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << items[i] << " ";
    }
    cout << "\n";

    return 0;
}
