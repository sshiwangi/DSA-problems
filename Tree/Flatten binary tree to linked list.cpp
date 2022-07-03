/*
Given a binary tree, flatten it into linked list in-place. Usage of auxiliary data structure is not allowed. After flattening, left of each node should point to NULL and right should contain next node in preorder.

Example 1:

Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6
Output :
1 2 3 4 5 6 
Explanation: 
After flattening, the tree looks 
like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 2 3 4 5 6.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1) */

class Solution
{
    public:
    void flatten(Node *root)
    {
        //STEPS: on the left subtree, find out the last node and connect it to the right of the root
        
        
        Node* curr = root;
        while(curr!=NULL){
            if(curr->left!=NULL){ // we can reach the last node of left subtree only if left subtree exists
                Node* prev = curr->left; 
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
            
        }
        
    }
};
