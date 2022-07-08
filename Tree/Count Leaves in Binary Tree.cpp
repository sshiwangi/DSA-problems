/*
Given a Binary Tree of size N , You have to count leaves in it. For example, there are two leaves in following tree

        1
     /      \
   10      39
  /
5

Example 1:

Input:
Given Tree is 
               4
             /   \
            8     10
           /     /   \
          7     5     1
         /
        3 
Output:
3
Explanation: 
Three leaves are 3 , 5 and 1. */

// code

int countLeaves(Node* root)
{
  // Your code here
  if(root == NULL){
      return 0;
  }
  if(root->left == NULL && root->right == NULL){
      return 1;
  }
  int left = countLeaves(root->left);
  int right = countLeaves(root->right);
  
  return left+right;
}
