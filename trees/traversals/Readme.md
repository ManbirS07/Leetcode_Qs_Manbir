Depth-First Search (DFS) explores a binary tree by going as deeply as possible along each branch before backtracking.

It starts from the root and explores as deeply as possible along each branch, visiting nodes until it reaches a leaf node. It then backtracks to the most recent unexplored node and continues until all nodes are visited.


Preorder Traversal is the type of Depth First Traversal where nodes are visited in the order: Root, Left then Right.


Algorithm:

Step 1: Initialise an empty vector ans to store the preorder traversal result. Create a stack to store the nodes during traversal and push the root node onto the stack.Check if the root is null, return an empty traversal result if true.

Step 2: Push the root of the binary tree into the stack.

Step 3:

While the stack is not empty:

Get the current node from the top of the stack.
Remove the node from the stack.
Add the node’s value to the ans traversal result.

First, push the right child onto the stack if it exists.

//As it's a stack,since the left child is pushed after right child
//It will always be added to the ans vector first!


Secondly, push the left child onto the stack if it exists.

Step 4: Return the ans traversal result.





Inorder Traversal is the type of Depth First Traversal where nodes are visited in the order: Left, Root, Right.

Algorithm:


Step 1: Initialise an empty vector ans to store the inorder traversal result and a variable current to store the root node. Create a stack to store the nodes during traversal and push the root node onto the stack.Check if the root is null, return an empty traversal result if true.

Step 2: 
Since we have to get the leftmost node first,run a while loop
with the condition that either current is not null or the stack is not empty
(if current is null,we dont want to search for it's left child as in this loop,we want to go back to the parent) and go on traversing root's left child till (current=current->left) the leftmost child is found and keep on adding these nodes in the stack

Step 3:
Now, we have the topmost element in stack as the leftmost child in the tree
Pop this node and add it's value to the ans[].Now check for it's right child.If the right child is present,value of current=current->right and again the traversal would begin with loop in step 2

but if current=nullptr,due to 1st condition of the loop,it would not run and we would go back to the parent element in the stacke

Step 4:
Return the ans traversal result




Postorder Traversal is the type of Depth First Traversal where nodes are visited in the order: Left, Right then Root.

It's named "postorder" because the "Visit" step occurs after traversing the left and right child nodes

//Iterative solution using a stack is similar to preOrder traversal
//But the ans vector is reversed at the end



Level order Traversal
Algorithm:

Step 1: initialise an empty queue data structure to store the nodes during traversal. Create a 2D array or a vector of a vector to store the level order traversal. If the tree is empty, return this empty 2D vector.

Step 2: Enqueue the root node ie. Add the root node of the binary tree to the queue.

Step 3:Iterate until the queue is empty:

Get the current size of the queue. This size indicates the number of nodes at the current level.
Create a vector ‘level’ to store the nodes at the current level.
//This size is of the parents
Iterate through ‘size’ number of nodes at the current level:
Pop the front node from the queue.
Store the node’s value in the level vector.
Enqueue the left and right child nodes of the current node (if they exist) into the queue.
After processing all the nodes at the current level, add the ‘level’ vector to the ‘ans’ 2D vector, representing the current level.

Step 4: Once the traversal loop completes ie. all levels have been processed, return the ‘ans’ 2D vector containing the level-order traversal.