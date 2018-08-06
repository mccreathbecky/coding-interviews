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

Balanced Search Trees
- there are some different definitions to what this means - branches being different lengths / whether sub trees are more/less 1 different in maximum height


### Red-Black Trees
- node either red/black
- root and leaves are black
- if node is red, children are black
- all paths from node to NIL descendants contain same number of nil nodes
- nodes require one storage bit to keep track of colour
- longest path is no more than twice the length of the shortest path
    - shortest path: all black nodes
    - longer path: alternating red and black
- 3 main operations: search, insert, remove. Time complexity O(logn), space complexity O(n)
- insert + remove require **rotation**

#### Rotation
- Alter structure of tree by rearranging subtrees
- goal to decrease height of tree
- do not affect order of elements
- left and right-rotate

### AVL
- "AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees cannot be more than one for all nodes"<https://www.geeksforgeeks.org/avl-tree-set-1-insertion/>
- 


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

## Heaps
- Always go in next empty element from top to bottom, left to right
- Can insert element and bubble it up until it's in the right spot, swapping with parent items
- if the parent is removed, move the last added element to the root so there's not an empty spot and then swap down
- Can implement with an array where left is index * 1 + 1, right is index * 2 + 2, parent is (index - 2)/2


