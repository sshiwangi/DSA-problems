/*
Given a binary tree, find its height.


Example 1:

Input:
     1
    /  \
   2    3
Output: 2

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)*/

// code

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if(node == NULL){
            return 0;
        }
        int lh = height(node->left);
        int rh = height(node->right);
        return max(lh,rh) + 1;
    }
};
