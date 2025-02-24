#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> um;
    int n;

    // Input size of unordered_map
    cout << "Enter number of elements: ";
    cin >> n;

    // Input unordered_map elements (key-value pairs)
    cout << "Enter elements (key value pairs): ";
    for (int i = 0; i < n; i++) {
        int key;
        string value;
        cin >> key >> value;
        um[key] = value;  // Inserting key-value pairs into unordered_map
    }

    // Print unordered_map
    cout << "Unordered Map elements (key: value): ";
    for (auto &p : um) {
        cout << p.first << ": " << p.second << " ";
    }
    cout << endl;

    // **Access an element by key**
    int key;
    cout << "Enter key to access: ";
    cin >> key;

    if (um.find(key) != um.end()) {
        cout << "Value at key " << key << ": " << um[key] << endl;
    } else {
        cout << "Key not found" << endl;
    }

    // **Search an element by key** (O(1) average time complexity)
    cout << "Enter key to search: ";
    cin >> key;

    auto it = um.find(key);
    if (it != um.end()) {
        cout << "Found: " << it->first << " => " << it->second << endl;
    } else {
        cout << "Not found" << endl;
    }

    // **Insert an element (key-value pair)**
    int newKey;
    string newValue;
    cout << "Enter new key-value pair to insert: ";
    cin >> newKey >> newValue;
    um[newKey] = newValue;

    // Print updated unordered_map
    cout << "Unordered Map after insertion: ";
    for (auto &p : um) {
        cout << p.first << ": " << p.second << " ";
    }
    cout << endl;

    // **Delete an element by key**
    cout << "Enter key to delete: ";
    cin >> newKey;

    if (um.erase(newKey)) {
        cout << "Element with key " << newKey << " deleted." << endl;
    } else {
        cout << "Element with key " << newKey << " not found." << endl;
    }

    // Print updated unordered_map
    cout << "Unordered Map after deletion: ";
    for (auto &p : um) {
        cout << p.first << ": " << p.second << " ";
    }
    cout << endl;

    return 0;
}
