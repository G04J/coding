#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(vector<float>& arr) {
    int n = arr.size();
    vector<vector<float>> buckets(n);

    // 1. Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];  // Map the element to a bucket
        buckets[index].push_back(arr[i]);
    }

    // 2. Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // 3. Concatenate all buckets into arr[]
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (float num : buckets[i]) {
            arr[idx++] = num;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<float> arr(n);
    cout << "Enter " << n << " floating-point numbers (0 to 1): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Before sorting:\n";
    for (float num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    bucketSort(arr);

    cout << "After sorting:\n";
    for (float num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
