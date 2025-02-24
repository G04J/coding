#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // Max heap using default priority_queue (largest element at the top)
    priority_queue<int> maxHeap;

    // Insert elements into the max heap
    cout << "Inserting elements into max heap: ";
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(5);
    maxHeap.push(30);
    maxHeap.push(15);

    // Peek the top element (max element)
    cout << "Top element (max): " << maxHeap.top() << endl;

    // Extract max (remove top element)
    cout << "Extracting max element: " << maxHeap.top() << endl;
    maxHeap.pop();
    cout << "Top element after pop: " << maxHeap.top() << endl;

    // Min heap using priority_queue with comparison (smallest element at the top)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert elements into the min heap
    cout << "Inserting elements into min heap: ";
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);
    minHeap.push(30);
    minHeap.push(15);

    // Peek the top element (min element)
    cout << "Top element (min): " << minHeap.top() << endl;

    // Extract min (remove top element)
    cout << "Extracting min element: " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Top element after pop: " << minHeap.top() << endl;

    return 0;
}
