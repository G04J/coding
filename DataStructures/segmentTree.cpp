#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class SegmentTree {
private:
    std::vector<int> sumTree, minTree, maxTree, lazyAdd;
    std::vector<bool> strictlyIncreasing, strictlyDecreasing;
    int n;

    void buildTree(const std::vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            sumTree[node] = minTree[node] = maxTree[node] = arr[start];
            strictlyIncreasing[node] = true;
            strictlyDecreasing[node] = true;
        } else {
            int mid = (start + end) / 2;
            buildTree(arr, 2 * node + 1, start, mid);
            buildTree(arr, 2 * node + 2, mid + 1, end);

            // Merge values for sum, min, and max
            sumTree[node] = sumTree[2 * node + 1] + sumTree[2 * node + 2];
            minTree[node] = std::min(minTree[2 * node + 1], minTree[2 * node + 2]);
            maxTree[node] = std::max(maxTree[2 * node + 1], maxTree[2 * node + 2]);

            // Check strictly increasing/decreasing properties
            strictlyIncreasing[node] = strictlyIncreasing[2 * node + 1] && strictlyIncreasing[2 * node + 2] &&
                                       (maxTree[2 * node + 1] < minTree[2 * node + 2]);
            strictlyDecreasing[node] = strictlyDecreasing[2 * node + 1] && strictlyDecreasing[2 * node + 2] &&
                                       (minTree[2 * node + 1] > maxTree[2 * node + 2]);
        }
    }

    // Lazy propagation to handle range updates efficiently
    void applyLazy(int node, int start, int end) {
        if (lazyAdd[node] != 0) {
            sumTree[node] += (end - start + 1) * lazyAdd[node];
            minTree[node] += lazyAdd[node];
            maxTree[node] += lazyAdd[node];
            if (start != end) {
                lazyAdd[2 * node + 1] += lazyAdd[node];
                lazyAdd[2 * node + 2] += lazyAdd[node];
            }
            lazyAdd[node] = 0;
        }
    }

    int rangeSumQuery(int node, int start, int end, int L, int R) {
        applyLazy(node, start, end);
        if (R < start || end < L) return 0;
        if (L <= start && end <= R) return sumTree[node];
        int mid = (start + end) / 2;
        return rangeSumQuery(2 * node + 1, start, mid, L, R) +
               rangeSumQuery(2 * node + 2, mid + 1, end, L, R);
    }

    int rangeMinQuery(int node, int start, int end, int L, int R) {
        applyLazy(node, start, end);
        if (R < start || end < L) return INT_MAX;
        if (L <= start && end <= R) return minTree[node];
        int mid = (start + end) / 2;
        return std::min(rangeMinQuery(2 * node + 1, start, mid, L, R),
                        rangeMinQuery(2 * node + 2, mid + 1, end, L, R));
    }

    int rangeMaxQuery(int node, int start, int end, int L, int R) {
        applyLazy(node, start, end);
        if (R < start || end < L) return INT_MIN;
        if (L <= start && end <= R) return maxTree[node];
        int mid = (start + end) / 2;
        return std::max(rangeMaxQuery(2 * node + 1, start, mid, L, R),
                        rangeMaxQuery(2 * node + 2, mid + 1, end, L, R));
    }

    bool isStrictlyIncreasing(int node, int start, int end, int L, int R) {
        applyLazy(node, start, end);
        if (R < start || end < L) return true;
        if (L <= start && end <= R) return strictlyIncreasing[node];
        int mid = (start + end) / 2;
        return isStrictlyIncreasing(2 * node + 1, start, mid, L, R) &&
               isStrictlyIncreasing(2 * node + 2, mid + 1, end, L, R) &&
               (rangeMaxQuery(2 * node + 1, start, mid, L, mid) < rangeMinQuery(2 * node + 2, mid + 1, end, mid + 1, R));
    }

    bool isStrictlyDecreasing(int node, int start, int end, int L, int R) {
        applyLazy(node, start, end);
        if (R < start || end < L) return true;
        if (L <= start && end <= R) return strictlyDecreasing[node];
        int mid = (start + end) / 2;
        return isStrictlyDecreasing(2 * node + 1, start, mid, L, R) &&
               isStrictlyDecreasing(2 * node + 2, mid + 1, end, L, R) &&
               (rangeMinQuery(2 * node + 1, start, mid, L, mid) > rangeMaxQuery(2 * node + 2, mid + 1, end, mid + 1, R));
    }

    void updateTree(int node, int start, int end, int idx, int val) {
        applyLazy(node, start, end);
        if (start == end) {
            sumTree[node] = minTree[node] = maxTree[node] = val;
            strictlyIncreasing[node] = strictlyDecreasing[node] = true;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                updateTree(2 * node + 1, start, mid, idx, val);
            } else {
                updateTree(2 * node + 2, mid + 1, end, idx, val);
            }
            sumTree[node] = sumTree[2 * node + 1] + sumTree[2 * node + 2];
            minTree[node] = std::min(minTree[2 * node + 1], minTree[2 * node + 2]);
            maxTree[node] = std::max(maxTree[2 * node + 1], maxTree[2 * node + 2]);
            strictlyIncreasing[node] = strictlyIncreasing[2 * node + 1] && strictlyIncreasing[2 * node + 2] &&
                                       (maxTree[2 * node + 1] < minTree[2 * node + 2]);
            strictlyDecreasing[node] = strictlyDecreasing[2 * node + 1] && strictlyDecreasing[2 * node + 2] &&
                                       (minTree[2 * node + 1] > maxTree[2 * node + 2]);
        }
    }

    void rangeUpdate(int node, int start, int end, int L, int R, int val) {
        applyLazy(node, start, end);
        if (R < start || end < L) return;
        if (L <= start && end <= R) {
            lazyAdd[node] += val;
            applyLazy(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        rangeUpdate(2 * node + 1, start, mid, L, R, val);
        rangeUpdate(2 * node + 2, mid + 1, end, L, R, val);
        sumTree[node] = sumTree[2 * node + 1] + sumTree[2 * node + 2];
        minTree[node] = std::min(minTree[2 * node + 1], minTree[2 * node + 2]);
        maxTree[node] = std::max(maxTree[2 * node + 1], maxTree[2 * node + 2]);
        strictlyIncreasing[node] = strictlyIncreasing[2 * node + 1] && strictlyIncreasing[2 * node + 2] &&
                                   (maxTree[2 * node + 1] < minTree[2 * node + 2]);
        strictlyDecreasing[node] = strictlyDecreasing[2 * node + 1] && strictlyDecreasing[2 * node + 2] &&
                                   (minTree[2 * node + 1] > maxTree[2 * node + 2]);
    }

public:
    SegmentTree(const std::vector<int>& arr) {
        n = arr.size();
        sumTree.resize(4 * n);
        minTree.resize(4 * n);
        maxTree.resize(4 * n);
        lazyAdd.resize(4 * n, 0);
        strictlyIncreasing.resize(4 * n, true);
        strictlyDecreasing.resize(4 * n, true);
        buildTree(arr, 0, 0, n - 1);
    }

    int rangeSum(int L, int R) {
        return rangeSumQuery(0, 0, n - 1, L, R);
    }

    int rangeMin(int L, int R) {
        return rangeMinQuery(0, 0, n - 1, L, R);
    }

    int rangeMax(int L, int R) {
        return rangeMaxQuery(0, 0, n - 1, L, R);
    }

    bool isIncreasing(int L, int R) {
        return isStrictlyIncreasing(0, 0, n - 1, L, R);
    }

    bool isDecreasing(int L, int R) {
        return isStrictlyDecreasing(0, 0, n - 1, L, R);
    }

    void update(int idx, int val) {
        updateTree(0, 0, n - 1, idx, val);
    }

    void rangeUpdate(int L, int R, int val) {
        rangeUpdate(0, 0, n - 1, L, R, val);
    }
};

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(arr);

    std::cout << "Initial range sum [1, 4]: " << segTree.rangeSum(1, 4) << "\n";
    std::cout << "Initial range min [1, 4]: " << segTree.rangeMin(1, 4) << "\n";
    std::cout << "Initial range max [1, 4]: " << segTree.rangeMax(1, 4) << "\n";

    segTree.update(3, 6);
    std::cout << "After update, range sum [1, 4]: " << segTree.rangeSum(1, 4) << "\n";

    segTree.rangeUpdate(2, 5, 3);
    std::cout << "After range update, range sum [1, 4]: " << segTree.rangeSum(1, 4) << "\n";
    std::cout << "After range update, range min [1, 4]: " << segTree.rangeMin(1, 4) << "\n";
    std::cout << "After range update, range max [1, 4]: " << segTree.rangeMax(1, 4) << "\n";

    return 0;
}
