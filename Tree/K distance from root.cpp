/*
Given a Binary Tree of size N and an integer K. Print all nodes that are at distance k from root (root is considered at distance 0 from itself). Nodes should be printed from left to right. If k is more that height of tree, nothing should be printed.

For example, if below is given tree and k is 2. Output should be 4 5 6.

          1
       /     \
     2        3
   /         /   \
  4        5    6 
     \
      8

Example 1:

Input:
K = 0
      1
    /   \
   3     2
Output: 1
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree). */

//code
void NodesAtDistanceK(Node* root, int k, vector<int> &ans){
    if(root == NULL){
        return;
    }
    // if root is the answer
    if(k==0){
        ans.push_back(root->data);
        return;
    }
    // check in left subtree and keep decreasing k by 1
    NodesAtDistanceK(root->left,k-1,ans);
    // check in right subtree
    NodesAtDistanceK(root->right,k-1,ans);
   
    
}
// function should print the nodes at k distance from root
vector<int> Kdistance(struct Node *root, int k)
{
  // Your code here
  vector<int> ans;
  NodesAtDistanceK(root,k,ans);
  return ans;
}
