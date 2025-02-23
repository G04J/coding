/*
Tarjan’s Algorithm is more efficient because it finds SCCs in a single DFS pass using a stack and some additional bookkeeping:

DFS Traversal: During the DFS, maintain an index for each node and the smallest index (low-link value) that can be reached from the node.
Stack: Keep track of nodes currently in the recursion stack (part of the current SCC being explored).
Identifying SCCs: When a node’s low-link value equals its index, it means we have found an SCC. Pop all nodes from the stack until we reach the current node.
Here’s a simplified outline of Tarjan’s Algorithm:

Initialize index to 0.
For each unvisited node, perform DFS.
Set the node’s index and low-link value.
Push the node onto the stack.
For each adjacent node, either perform DFS if it’s not visited or update the low-link value if it’s in the stack.
If the node’s low-link value equals its index, pop nodes from the stack to form an SCC
*/