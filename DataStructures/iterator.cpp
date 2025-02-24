#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

int main() {
    // Using iterator with vector
    vector<int> v = {1, 2, 3, 4, 5};

    cout << "Using iterator with vector:" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Using iterator with list
    list<string> l = {"apple", "banana", "cherry", "date"};

    cout << "Using iterator with list:" << endl;
    for (list<string>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Using iterator with map (key-value pairs)
    map<int, string> m = {{1, "one"}, {2, "two"}, {3, "three"}};

    cout << "Using iterator with map (key-value pairs):" << endl;
    for (map<int, string>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << it->first << ": " << it->second << " ";
    }
    cout << endl;

    // Using reverse iterator with vector
    cout << "Using reverse iterator with vector:" << endl;
    for (vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    // Using constant iterator with vector
    cout << "Using constant iterator with vector:" << endl;
    for (vector<int>::const_iterator cit = v.cbegin(); cit != v.cend(); ++cit) {
        cout << *cit << " ";
    }
    cout << endl;

    return 0;
}
