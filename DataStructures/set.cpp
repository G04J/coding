#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    int n;

    // Input size of set
    cout << "Enter number of elements: ";
    cin >> n;

    // Input set elements
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        s.insert(element);  // Inserting elements into set (duplicate elements will be ignored)
    }

    // Print set
    cout << "Set elements (sorted): ";
    for (int val : s) {
        cout << val << " ";
    }
    cout << endl;

    // **Access (Set does not support direct access, but we can iterate)**
    cout << "Set elements (iteration): ";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // **Search an element** (O(log n) complexity)
    int key;
    cout << "Enter element to search: ";
    cin >> key;

    auto it = s.find(key);
    if (it != s.end()) {
        cout << "Found: " << *it << endl;
    } else {
        cout << "Not found" << endl;
    }

    // **Insert an element**
    int newElement;
    cout << "Enter element to insert: ";
    cin >> newElement;
    s.insert(newElement);

    // Print updated set
    cout << "Set after insertion: ";
    for (int val : s) {
        cout << val << " ";
    }
    cout << endl;

    // **Delete an element**
    cout << "Enter element to delete: ";
    cin >> newElement;

    if (s.erase(newElement)) {
        cout << "Element " << newElement << " deleted." << endl;
    } else {
        cout << "Element not found to delete!" << endl;
    }

    // Print updated set
    cout << "Set after deletion: ";
    for (int val : s) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
