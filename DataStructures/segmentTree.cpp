#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    // Build the segment tree
    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node, start, mid);        // Left child
            build(arr, 2*node+1, mid+1, end);     // Right child
            tree[node] = tree[2*node] + tree[2*node+1]; // Sum of both children
        }
    }

    // Range query (sum)
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) { // No overlap
            return 0;
        }
        if (l <= start && end <= r) { // Total overlap
            return tree[node];
        }
        // Partial overlap
        int mid = (start + end) / 2;
        int leftSum = query(2*node, start, mid, l, r);
        int rightSum = query(2*node+1, mid+1, end, l, r);
        return leftSum + rightSum;
    }

    // Range update
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2*node, start, mid, idx, val);
            } else {
                update(2*node+1, mid+1, end, idx, val);
            }
            tree[node] = tree[2*node] + tree[2*node+1]; // Update the parent node
        }
    }

public:
    // Constructor: builds the segment tree
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n-1);
    }

    // Range sum query (l to r)
    int rangeQuerySum(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    // Update an element (index, value)
    void rangeUpdate(int idx, int val) {
        update(1, 0, n-1, idx, val);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(arr);

    // Query the sum of range [1, 3]
    cout << "Sum of range [1, 3]: " << segTree.rangeQuerySum(1, 3) << endl;

    // Update element at index 2 to 6
    segTree.rangeUpdate(2, 6);
    cout << "After update, sum of range [1, 3]: " << segTree.rangeQuerySum(1, 3) << endl;

    // Query the sum of range [0, 5]
    cout << "Sum of range [0, 5]: " << segTree.rangeQuerySum(0, 5) << endl;

    return 0;
}
