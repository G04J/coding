#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> us;
    int n;

    // Input size of unordered_set
    cout << "Enter number of elements: ";
    cin >> n;

    // Input unordered_set elements
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        us.insert(element);  // Inserting elements into unordered_set
    }

    // Print unordered_set
    cout << "Unordered Set elements: ";
    for (int val : us) {
        cout << val << " ";
    }
    cout << endl;

    // **Search an element** (O(1) average time complexity)
    int key;
    cout << "Enter element to search: ";
    cin >> key;

    if (us.find(key) != us.end()) {
        cout << "Found: " << key << endl;
    } else {
        cout << "Not found" << endl;
    }

    // **Insert an element**
    int newElement;
    cout << "Enter element to insert: ";
    cin >> newElement;
    us.insert(newElement);

    // Print updated unordered_set
    cout << "Unordered Set after insertion: ";
    for (int val : us) {
        cout << val << " ";
    }
    cout << endl;

    // **Delete an element**
    cout << "Enter element to delete: ";
    cin >> newElement;

    if (us.erase(newElement)) {
        cout << "Element " << newElement << " deleted." << endl;
    } else {
        cout << "Element not found to delete!" << endl;
    }

    // Print updated unordered_set
    cout << "Unordered Set after deletion: ";
    for (int val : us) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
