#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec;
    int n;

    // Input size of vector
    cout << "Enter number of elements: ";
    cin >> n;

    // Input vector elements
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        vec.push_back(element);  // Adding elements to vector
    }

    // Print vector
    cout << "Vector elements: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    // **Access an element at a specific index**
    int index;
    cout << "Enter index to access: ";
    cin >> index;
    if (index >= 0 && index < vec.size())
        cout << "Element at index " << index << " is " << vec[index] << endl;
    else
        cout << "Invalid index!" << endl;

    // **Search an element**
    int key;
    cout << "Enter element to search: ";
    cin >> key;

    bool found = false;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == key) {
            cout << "Found at index " << i << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Not found" << endl;

    // **Insert an element at a given position**
    int newElement, pos;
    cout << "Enter element to insert and position (0-based index): ";
    cin >> newElement >> pos;

    if (pos < 0 || pos > vec.size()) {
        cout << "Invalid position!" << endl;
    } else {
        vec.insert(vec.begin() + pos, newElement);

        // Print updated vector
        cout << "Vector after insertion: ";
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    // **Delete an element at a given position**
    cout << "Enter position to delete element from: ";
    cin >> pos;

    if (pos < 0 || pos >= vec.size()) {
        cout << "Invalid position!" << endl;
    } else {
        vec.erase(vec.begin() + pos);

        // Print updated vector
        cout << "Vector after deletion: ";
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
