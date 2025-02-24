#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    int n;

    // Input size of stack
    cout << "Enter number of elements: ";
    cin >> n;

    // Input stack elements
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        st.push(element); // Push elements onto stack
    }

    // Print stack (copying to preserve original stack)
    cout << "Stack elements (top to bottom): ";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // **Access top element**
    if (!st.empty()) {
        cout << "Top element: " << st.top() << endl;
    } else {
        cout << "Stack is empty!" << endl;
    }

    // **Search an element** (O(n) complexity)
    int key;
    cout << "Enter element to search: ";
    cin >> key;

    temp = st;
    bool found = false;
    int pos = 0;
    while (!temp.empty()) {
        if (temp.top() == key) {
            cout << "Found at position " << pos << " from the top" << endl;
            found = true;
            break;
        }
        temp.pop();
        pos++;
    }
    if (!found) cout << "Not found" << endl;

    // **Insert an element (push)**
    int newElement;
    cout << "Enter element to push onto stack: ";
    cin >> newElement;
    st.push(newElement);

    // Print updated stack
    cout << "Stack after insertion: ";
    temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // **Delete an element (pop)**
    if (!st.empty()) {
        cout << "Popping top element: " << st.top() << endl;
        st.pop();
    } else {
        cout << "Stack is empty, cannot pop!" << endl;
    }

    // Print updated stack
    cout << "Stack after deletion: ";
    temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}
