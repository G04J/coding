#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    int n;

    // Input size of deque
    cout << "Enter number of elements: ";
    cin >> n;

    // Input deque elements
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        dq.push_back(element); // Adding elements to deque
    }

    // Print deque
    cout << "Deque elements: ";
    for (int val : dq) {
        cout << val << " ";
    }
    cout << endl;

    // **Access an element at a specific index**
    int index;
    cout << "Enter index to access: ";
    cin >> index;

    if (index < 0 || index >= dq.size()) {
        cout << "Invalid index!" << endl;
    } else {
        cout << "Element at index " << index << " is " << dq[index] << endl;
    }

    // **Search an element**
    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int pos = 0;
    bool found = false;
    for (int i = 0; i < dq.size(); i++) {
        if (dq[i] == key) {
            cout << "Found at index " << i << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Not found" << endl;

    // **Insert an element at a given position**
    int newElement, insertPos;
    cout << "Enter element to insert and position (0-based index): ";
    cin >> newElement >> insertPos;

    if (insertPos < 0 || insertPos > dq.size()) {
        cout << "Invalid position!" << endl;
    } else {
        dq.insert(dq.begin() + insertPos, newElement);

        // Print updated deque
        cout << "Deque after insertion: ";
        for (int val : dq) {
            cout << val << " ";
        }
        cout << endl;
    }

    // **Delete an element at a given position**
    cout << "Enter position to delete element from: ";
    cin >> insertPos;

    if (insertPos < 0 || insertPos >= dq.size()) {
        cout << "Invalid position!" << endl;
    } else {
        dq.erase(dq.begin() + insertPos);

        // Print updated deque
        cout << "Deque after deletion: ";
        for (int val : dq) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
