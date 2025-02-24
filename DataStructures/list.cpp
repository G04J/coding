#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> lst;
    int n;

    // Input size of list
    cout << "Enter number of elements: ";
    cin >> n;

    // Input list elements
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        lst.push_back(element);  // Adding elements to list
    }

    // Print list
    cout << "List elements: ";
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;

    // **Access an element at a specific index**
    int index;
    cout << "Enter index to access: ";
    cin >> index;

    if (index < 0 || index >= lst.size()) {
        cout << "Invalid index!" << endl;
    } else {
        auto it = lst.begin();
        advance(it, index); // Move iterator to the index
        cout << "Element at index " << index << " is " << *it << endl;
    }

    // **Search an element**
    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int pos = 0;
    bool found = false;
    for (auto it = lst.begin(); it != lst.end(); ++it, ++pos) {
        if (*it == key) {
            cout << "Found at index " << pos << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Not found" << endl;

    // **Insert an element at a given position**
    int newElement, insertPos;
    cout << "Enter element to insert and position (0-based index): ";
    cin >> newElement >> insertPos;

    if (insertPos < 0 || insertPos > lst.size()) {
        cout << "Invalid position!" << endl;
    } else {
        auto it = lst.begin();
        advance(it, insertPos);
        lst.insert(it, newElement);

        // Print updated list
        cout << "List after insertion: ";
        for (int val : lst) {
            cout << val << " ";
        }
        cout << endl;
    }

    // **Delete an element at a given position**
    cout << "Enter position to delete element from: ";
    cin >> insertPos;

    if (insertPos < 0 || insertPos >= lst.size()) {
        cout << "Invalid position!" << endl;
    } else {
        auto it = lst.begin();
        advance(it, insertPos);
        lst.erase(it);

        // Print updated list
        cout << "List after deletion: ";
        for (int val : lst) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
