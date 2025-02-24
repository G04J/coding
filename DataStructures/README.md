# Data Structures in C++

What is a Data Structure?

A data structure is a way of organizing and storing data in a computer so that it can be accessed and modified efficiently. Data structures are essential for solving complex problems and implementing efficient algorithms.


# Data Structures in C++ 

| Data Structure      | Description                                     | Header File         | Access | Search | Insertion | Deletion |
|---------------------|-------------------------------------------------|---------------------|--------|--------|-----------|----------|
| **Array**          | Fixed-size sequential collection of elements.   | N/A (Built-in)     | O(1)   | O(n)   | O(n)      | O(n)     |
| **Vector**         | Dynamic array with automatic resizing.         | `<vector>`         | O(1)   | O(n)   | O(n)      | O(n)     |
| **Deque**          | Double-ended queue for fast insertions/removals.| `<deque>`          | O(1)   | O(n)   | O(1) (ends) | O(1) (ends) |
| **List**           | Doubly linked list for fast insertions/removals.| `<list>`           | O(n)   | O(n)   | O(1)      | O(1)     |
| **Stack**          | LIFO structure (last in, first out).            | `<stack>`          | O(n)   | O(n)   | O(1)      | O(1)     |
| **Queue**          | FIFO structure (first in, first out).           | `<queue>`          | O(n)   | O(n)   | O(1)      | O(1)     |
| **Priority Queue** | Heap-based structure for priority retrieval.    | `<queue>`          | O(n)   | O(n)   | O(log n)  | O(log n) |
| **Set**            | Ordered collection of unique elements.          | `<set>`            | O(log n) | O(log n) | O(log n) | O(log n) |
| **Unordered Set**  | Hash-based unique collection.                   | `<unordered_set>`  | O(1) (avg) | O(1) (avg) | O(1) (avg) | O(1) (avg) |
| **Map**            | Sorted key-value pair storage.                  | `<map>`            | O(log n) | O(log n) | O(log n) | O(log n) |
| **Unordered Map**  | Hash-based key-value pairs.                     | `<unordered_map>`  | O(1) (avg) | O(1) (avg) | O(1) (avg) | O(1) (avg) |
| **Bitset**         | Space-efficient fixed-size bit array.           | `<bitset>`         | O(1)   | O(1)   | O(1)      | O(1)     |
| **Trie**          | Tree-like structure for fast string searches.    | N/A (Custom)       | O(n)   | O(n)   | O(n)      | O(n)     |
| **Segment Tree**  | Efficient range queries and updates.             | N/A (Custom)       | O(log n) | O(log n) | O(log n) | O(log n) |
| **Graph**         | Nodes and edges representation (Adjacency List/Matrix). | N/A (Custom)       | O(V+E) | O(V+E) | O(1) (Edge Insert) | O(1) (Edge Remove) |

## Difference between an array, a vector and a list in c++

| Feature              | **Array (`int arr[100]`)** | **Vector (`std::vector<int>`)** | **List (`std::list<int>`)** |
|----------------------|-------------------------|-------------------------------|----------------------------|
| **Memory Layout**    | Contiguous (Fixed size) | Contiguous (Dynamic size)    | Non-contiguous (Doubly Linked List) |
| **Access Time**      | **O(1)** (Direct indexing) | **O(1)** (Direct indexing)   | **O(n)** (Must traverse using iterators) |
| **Insertion at End** | **N/A** (Fixed size)    | **O(1)** (Amortized)         | **O(1)** |
| **Insertion in Middle** | **O(n)** (Shifting required) | **O(n)** (Shifting required) | **O(1)** (Using iterators) |
| **Deletion from Middle** | **O(n)** (Shifting required) | **O(n)** (Shifting required) | **O(1)** (Using iterators) |
| **Dynamic Resizing** | ❌ No (Fixed size)      | ✅ Yes (Automatically resizes) | ✅ Yes (Dynamically allocates memory) |
| **Cache Efficiency** | ✅ High (Contiguous)    | ✅ High (Contiguous)         | ❌ Low (Pointer-based) |
| **Memory Overhead**  | ✅ Minimal              | ❌ Some (Extra capacity for growth) | ❌ High (Extra pointers for links) |
| **Best Use Case**    | Fixed-size data with fast access | Dynamically growing data requiring fast access | Frequent insertions/deletions in the middle |

### Key Takeaways:
- **Use an array** if the size is fixed and you need fast random access.
- **Use a vector** if you need dynamic resizing but still want fast access.
- **Use a list** if you frequently insert or delete elements in the middle and don’t need fast random access.

## Stack and Queue

### Key Takeaways:
- **Use a stack** when you need to maintain the order of elements in a Last-In-First-Out (LIFO) manner.
- **Use a queue** when you need to maintain the order of elements in a First-In-First-Out (FIFO) manner.

# Sets and Maps 

### Key Takeaways:
- **Use a set** if you need a sorted collection of unique elements.
- **Use an unordered set** if you need a hash-based unique collection.
- **Use a map** if you need a sorted key-value pair storage.
- **Use an unordered map** if you need a hash-based key-value pairs.

