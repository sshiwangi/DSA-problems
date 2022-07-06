/*
Given a BST, and a reference to a Node x in the BST. Find the Inorder Successor of the given node in the BST.
 

Example 1:

Input:
      2
    /   \
   1     3
K(data of x) = 2
Output: 3 
Explanation: 
Inorder traversal : 1 2 3 
Hence, inorder successor of 2 is 3.

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(1). */

// code

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node *temp = root, *ans;
        // if temp exists
        while(temp != NULL) {
            // and the node's data is greater than or equal to the root's data, go in the right direction
            if(temp->data <= x->data) {
               temp = temp->right;
            }
            // otherwise store the prev temp in the answer and go to the left node
            else {
                ans = temp;
                temp = temp->left;
            }
        }
        // return the result
        return ans;
    }
};
