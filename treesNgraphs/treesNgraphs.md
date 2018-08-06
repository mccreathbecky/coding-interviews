# Trees And Graphs: Notes

## Data Structures: Trees
<https://www.youtube.com/watch?v=oSWTXtMglKE>
- Trees
- Balanced Trees

Traversing Order
- Preorder: root, then left, then right
- Postorder: left, then right, then root
- In Order: left then root then right

Tree Methods
- Insert operates recursively, inserting new nodes when left/right is null, otherwise calling Insert again

## Graphs

- A collection of nodes, where each may point to other
- Directed/undirected


Depth First Search 
- typically recursive
- use isVisited so there's no infinite loop
- Go deep into a node before asking children
- Downside: could've been a close connection but not from children

Breadth First Search
- Go out level by level
- use a queue to keep adding children to queue, not recursively


## Binary Search
- e.g. imagine trying to find 'Zach Peters' in a stack of 300 names - you'd start about halfway and then move forward/backwards, and repeat that process
- Must have a sorted array
- n, n/2, n/4, ... 1 element
- how many times can we divide by 2 until we get to 1, O(log2n)
- can be implemented recursively or iteratively

## Stacks and Queues
- Linear data structures
- Flexible Size

Stack: Last In First Out [LIFO]
Queue: First In First Out [FIFO]