#include <iostream>
#include <vector>

using namespace std;

bool gt(int a, int b);
void swap(vector<int>& items, int i, int j);
void bubbleSort(vector<int>& items, int lo, int hi);

bool gt(int a, int b) {
    return a > b;
}

void swap(vector<int>& items, int i, int j) {
    int temp = items[i];
    items[i] = items[j];
    items[j] = temp;
}

void bubbleSort(vector<int>& items, int lo, int hi) {
    for (int i = hi; i > lo; i--) {
        bool swapped = false;
        for (int j = lo; j < i; j++) {
            if (gt(items[j], items[j + 1])) {
                swap(items, j, j + 1);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    int n;

    cout << "Enter length of array: "; 
    cin >> n;

    vector<int> items(n);

    cout << "Enter values: "; 
    for(int i = 0; i < n; i++) {
        cin >> items[i];
    }

    cout << "Before sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << items[i] << " ";
    }
    cout << "\n";

    bubbleSort(items, 0, n - 1);

    cout << "After sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << items[i] << " ";
    }
    cout << "\n";

    return 0;
}
