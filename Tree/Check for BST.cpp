/*
Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

Input:
   2
 /    \
1      3
Output: 1 
Explanation: 
The left subtree of root node contains node
with key lesser than the root nodes key and 
the right subtree of root node contains node 
with key greater than the root nodes key.
Hence, the tree is a BST.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST). */

// code
class Solution
{
    public:
    bool checkForBST(Node* root, long minval, long maxval){
        if(root == NULL) return true;
        if(root->data <= minval || root->data >= maxval) return false;
        
        return checkForBST(root->left,minval,root->data) && checkForBST(root->right,root->data,maxval);
    }
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        return checkForBST(root,INT_MIN,INT_MAX);
    }
};
