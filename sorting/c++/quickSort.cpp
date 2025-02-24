#include <iostream>
#include <vector>
#include <cstdlib> // For rand()

using namespace std;

/* Lomuto Partition Scheme */
int lomutoPartition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1; // Pointer for the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // If current element is smaller than pivot
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot at correct position
    return i + 1;
}

void quickSortLomuto(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = lomutoPartition(arr, low, high);
        quickSortLomuto(arr, low, pivotIndex - 1);
        quickSortLomuto(arr, pivotIndex + 1, high);
    }
}

/* Hoare Partition Scheme */
int hoarePartition(vector<int>& arr, int low, int high) {
    int pivot = arr[low]; // Choose the first element as pivot
    int i = low - 1, j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot); // Move right until finding an element ≥ pivot

        do {
            j--;
        } while (arr[j] > pivot); // Move left until finding an element ≤ pivot

        if (i >= j) return j; // If pointers cross, return partition index

        swap(arr[i], arr[j]); // Swap elements
    }
}

void quickSortHoare(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = hoarePartition(arr, low, high);
        quickSortHoare(arr, low, pivotIndex);
        quickSortHoare(arr, pivotIndex + 1, high);
    }
}

/* Randomized Quick Sort */
int randomizedPartition(vector<int>& arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1); // Pick a random pivot
    swap(arr[randomIndex], arr[high]); // Move pivot to the end
    return lomutoPartition(arr, low, high);
}

void quickSortRandomized(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = randomizedPartition(arr, low, high);
        quickSortRandomized(arr, low, pivotIndex - 1);
        quickSortRandomized(arr, pivotIndex + 1, high);
    }
}

/* Utility function to print the array */
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> arrLomuto = arr, arrHoare = arr, arrRandomized = arr;

    cout << "\nOriginal array:\n";
    printArray(arr);

    // Lomuto QuickSort
    quickSortLomuto(arrLomuto, 0, n - 1);
    cout << "\nSorted using Lomuto Partition:\n";
    printArray(arrLomuto);

    // Hoare QuickSort
    quickSortHoare(arrHoare, 0, n - 1);
    cout << "\nSorted using Hoare Partition:\n";
    printArray(arrHoare);

    // Randomized QuickSort
    quickSortRandomized(arrRandomized, 0, n - 1);
    cout << "\nSorted using Randomized Quick Sort:\n";
    printArray(arrRandomized);

    return 0;
}
