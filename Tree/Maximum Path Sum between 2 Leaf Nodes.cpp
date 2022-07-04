/*
Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one leaf node to another leaf node.

Note: Here Leaf node is a node which is connected to exactly one different node.


Example 1:

Input:      
           3                               
         /    \                          
       4       5                     
      /  \      
    -10   4                          
Output: 16
Explanation:
Maximum Sum lies between leaf node 4 and 5.
4 + 4 + 3 + 5 = 16.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of Tree) */

// code


class Solution {
public:
    int solve(Node* root, int& maxSum){
        // if the tree is empty
      if(root == NULL){
          return 0;
      }
      
      int left = solve(root->left, maxSum);
      int right = solve(root->right, maxSum);
      
      // left child is null
      if(root->left==NULL){
          return right+root->data;
      }
      // right child is null
      if(root->right==NULL){
          return left+root->data;
      }
      // maximum sum path through current node
      int curr = left + right + root->data;
      
      //update the maxsum path found so far
      int temp = max(left,right) + root->data;
      maxSum = max(curr,maxSum);
      
      // when both child exists
      return temp; // this value will be used by recursive calls
  }
    int maxPathSum(Node* root)
    {
        int maxSum=INT_MIN;
        if(!root->left)
           root->left = new Node(0);
       if(!root->right)
           root->right = new Node(0);
        solve(root,maxSum); ;
       
        return maxSum;
    }
};
