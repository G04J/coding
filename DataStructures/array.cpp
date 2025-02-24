#include <iostream>
using namespace std;

int main() {
    int arr[100];   
    int n;
    
    // Input size of array
    cout << "Enter number of elements: ";
    cin >> n;

    // Input array elements
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Print array 
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // **Access an element at a specific index**
    int index;
    cout << "Enter index to access: ";
    cin >> index;
    if (index >= 0 && index < n)
        cout << "Element at index " << index << " is " << arr[index] << endl;
    else
        cout << "Invalid index!" << endl;

    // **Search an element**
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Found at index " << i << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Not found" << endl;

    // **Insert an element at a given position**
    if (n < 100) { // Ensure array size limit isn't exceeded
        int newElement, pos;
        cout << "Enter element to insert and position (0-based index): ";
        cin >> newElement >> pos;

        if (pos < 0 || pos > n) {
            cout << "Invalid position!" << endl;
        } else {
            // Shift elements to the right
            for (int i = n; i > pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = newElement;
            n++;

            // Print updated array
            cout << "Array after insertion: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Array is full, cannot insert more elements." << endl;
    }

    // **Delete an element at a given position**
    cout << "Enter position to delete element from: ";
    cin >> pos;

    if (pos < 0 || pos >= n) {
        cout << "Invalid position!" << endl;
    } else {
        // Shift elements to the left
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;

        // Print updated array
        cout << "Array after deletion: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
