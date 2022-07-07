/*
Given a binary tree, find its preorder traversal.

Example 1:

Input:
        1      
      /          
    4    
  /    \   
4       2
Output: 1 4 4 2 */

// code
void pre(Node* root, vector<int>&ans){
    if(root == NULL){
      return;
    }
    ans.push_back(root->data);
    pre(root->left,ans);
    pre(root->right,ans);
}
//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
  // Your code here
  vector<int>ans;
  pre(root,ans);
  
  return ans;
}
