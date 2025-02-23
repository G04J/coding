/*
Kosaraju’s Algorithm involves two main phases:

Performing Depth-First Search (DFS) on the Original Graph:
We first do a DFS on the original graph and record the finish times of nodes (i.e., the time at which the DFS finishes exploring a node completely).
Performing DFS on the Transposed Graph:
We then reverse the direction of all edges in the graph to create the transposed graph.
Next, we perform a DFS on the transposed graph, considering nodes in decreasing order of their finish times recorded in the first phase.
Each DFS traversal in this phase will give us one SCC.
Here’s a simplified version of Kosaraju’s Algorithm:

DFS on Original Graph: Record finish times.
Transpose the Graph: Reverse all edges.
DFS on Transposed Graph: Process nodes in order of decreasing finish times to find SCCs.
*/