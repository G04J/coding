#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int n;

    // Input size of queue
    cout << "Enter number of elements: ";
    cin >> n;

    // Input queue elements
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        q.push(element); // Enqueue elements
    }

    // Print queue elements (copying to preserve original queue)
    cout << "Queue elements: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // **Access front and back elements**
    if (!q.empty()) {
        cout << "Front element: " << q.front() << endl;
        cout << "Back element: " << q.back() << endl;
    } else {
        cout << "Queue is empty!" << endl;
    }

    // **Search an element** (O(n) complexity)
    int key;
    cout << "Enter element to search: ";
    cin >> key;

    temp = q;
    bool found = false;
    int pos = 0;
    while (!temp.empty()) {
        if (temp.front() == key) {
            cout << "Found at position " << pos << endl;
            found = true;
            break;
        }
        temp.pop();
        pos++;
    }
    if (!found) cout << "Not found" << endl;

    // **Insert an element (enqueue)**
    int newElement;
    cout << "Enter element to enqueue: ";
    cin >> newElement;
    q.push(newElement);

    // Print updated queue
    cout << "Queue after insertion: ";
    temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // **Delete an element (dequeue)**
    if (!q.empty()) {
        cout << "Dequeuing front element: " << q.front() << endl;
        q.pop();
    } else {
        cout << "Queue is empty, cannot dequeue!" << endl;
    }

    // Print updated queue
    cout << "Queue after deletion: ";
    temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}
