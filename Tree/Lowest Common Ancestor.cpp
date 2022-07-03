/* problem link: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1#
Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

Example 1:

Input:
n1 = 2 , n2 = 3  
       1 
      / \ 
     2   3
Output: 1
Explanation:
LCA of 2 and 3 is 1.

Expected Time Complexity:O(N).
Expected Auxiliary Space:O(Height of Tree). */

//code
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        // base case
       //if the root is null or equal to any of the given nodes, we will return the node
       if(root == NULL || root->data == n1 || root->data == n2){
           return root;
       }
       
       Node* left = lca(root->left,n1,n2);
       Node* right = lca(root->right,n1,n2);
       
       // if the returned values, say left is null then return right one and vice versa
       if(left == NULL){
           return right;
       }
       else if(right == NULL){
           return left;
       }
       // if none of them are null we found our answer, so return the root 
       else{
           return root;
       }
    }
};
