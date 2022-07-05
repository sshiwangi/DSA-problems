/*
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST). */

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class NodeValue{
    public:
    int maxNode, minNode, maxSize;
    
    NodeValue(int minNode, int maxNode, int maxSize){
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution{
    NodeValue solve(Node* root){
        // an empty tree is a bst of size 0
        if(!root){
            return NodeValue(INT_MAX,INT_MIN,0);
        }
        // get values from left and right subtree of current tree
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        // if current node is greater than max in left and smaller than min in right it is a bst
        if(left.maxNode< root->data && root->data<right.minNode){
            // it is a bst
            return NodeValue(min(root->data, left.minNode),max(root->data, right.maxNode),left.maxSize + right.maxSize + 1);
            
        }
        // otherwise return [-infinite, infinite] so the parent can't be valid bst
        return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
    }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	return solve(root).maxSize;
    }
};
