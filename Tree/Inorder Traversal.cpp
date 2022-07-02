/*
Given a Binary Tree, find the In-Order Traversal of it.

Example 1:

Input:
       1
     /  \
    3    2
Output: 3 1 2

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N). */

// code
class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    void Inorder(Node* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        Inorder(root->left,ans);
        ans.push_back(root->data);
        Inorder(root->right,ans);
    }
    vector<int> inOrder(Node* root) {
        
        // Your code here
        vector<int> ans;
        Inorder(root,ans);
        return ans;
         
    }
};
