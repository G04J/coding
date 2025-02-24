#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m;
    int n;

    // Input size of map
    cout << "Enter number of elements: ";
    cin >> n;

    // Input map elements (key-value pairs)
    cout << "Enter elements (key value pairs): ";
    for (int i = 0; i < n; i++) {
        int key;
        string value;
        cin >> key >> value;
        m[key] = value;  // Inserting key-value pairs into map
    }

    // Print map
    cout << "Map elements (key: value): ";
    for (auto &p : m) {
        cout << p.first << ": " << p.second << " ";
    }
    cout << endl;

    // **Access an element by key**
    int key;
    cout << "Enter key to access: ";
    cin >> key;

    if (m.find(key) != m.end()) {
        cout << "Value at key " << key << ": " << m[key] << endl;
    } else {
        cout << "Key not found" << endl;
    }

    // **Search an element by key** (O(log n) time complexity)
    string searchKey;
    cout << "Enter key to search: ";
    cin >> searchKey;

    auto it = m.find(key);
    if (it != m.end()) {
        cout << "Found: " << it->first << " => " << it->second << endl;
    } else {
        cout << "Not found" << endl;
    }

    // **Insert an element (key-value pair)**
    int newKey;
    string newValue;
    cout << "Enter new key-value pair to insert: ";
    cin >> newKey >> newValue;
    m[newKey] = newValue;

    // Print updated map
    cout << "Map after insertion: ";
    for (auto &p : m) {
        cout << p.first << ": " << p.second << " ";
    }
    cout << endl;

    // **Delete an element by key**
    cout << "Enter key to delete: ";
    cin >> newKey;

    if (m.erase(newKey)) {
        cout << "Element with key " << newKey << " deleted." << endl;
    } else {
        cout << "Element with key " << newKey << " not found." << endl;
    }

    // Print updated map
    cout << "Map after deletion: ";
    for (auto &p : m) {
        cout << p.first << ": " << p.second << " ";
    }
    cout << endl;

    return 0;
}
