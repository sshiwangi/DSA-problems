/*
Given a binary tree and two node values your task is to find the minimum distance between them.

Example 1:

Input:
        1
      /  \
     2    3
a = 2, b = 3
Output: 2
Explanation: The tree formed is:
       1
     /   \ 
    2     3
We need the distance between 2 and 3.
Being at node 2, we need to take two
steps ahead in order to reach node 3.
The path followed will be:
2 -> 1 -> 3. Hence, the result is 2. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree). */

// code

class Solution{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* LCA(Node* root ,int n1 ,int n2 )
    {
        // base case
       //if the root is null or equal to any of the given nodes, we will return the node
       if(root == NULL || root->data == n1 || root->data == n2){
           return root;
       }
       
       Node* left = LCA(root->left,n1,n2);
       Node* right = LCA(root->right,n1,n2);
       
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
   // function to find the distance of a node form the root
    int findDistance(Node *root, int val, int level) {
       if(root == NULL) {
           return -1;
       }
       if(root->data == val) {
           return level;
       }
       int left = findDistance(root->left, val, level+1);
       if(left == -1) {
           int right = findDistance(root->right, val, level+1);
           return right;
       }
       return left;
   }
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        // Your code here
        // find the lowest common ancestor of both nodes
        
        Node* lca = LCA(root,a,b);
        
        return  findDistance(lca,a,0) +  findDistance(lca,b,0);
        
        
    }
};
