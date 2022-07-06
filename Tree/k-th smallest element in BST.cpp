/*
Given a BST and an integer K. Find the Kth Smallest element in the BST. 

Example 1:

Input:
      2
    /   \
   1     3
K = 2
Output: 2 */

class Solution {
  public:
    void inOrder(Node* root,vector<int>&v){
       if(!root){
           return;
       }
       inOrder(root->left,v);
       v.push_back(root->data);
       inOrder(root->right,v);
   }
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        vector<int>v;
        inOrder(root,v);
        if(K>v.size()){
          return -1;
        }

        int i = K-1;
        return v[i];
      
   
    }
};
