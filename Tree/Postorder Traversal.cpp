/*
Given a binary tree, find the Postorder Traversal of it.
For Example, the postorder traversal of the following tree is:
5 10 39 1

        1
     /     \
   10     39
  /
5


Example 1:

Input:
        19
     /     \
    10      8
  /    \
 11    13
Output: 11 13 10 8 19 */

// code
void post(Node* root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    post(root->left,ans);
    post(root->right,ans);
    ans.push_back(root->data);
}
//Function to return a list containing the postorder traversal of the tree.
vector <int> postOrder(Node* root)
{
  // Your code here
  vector<int>ans;
  post(root,ans);
  return ans;
}
