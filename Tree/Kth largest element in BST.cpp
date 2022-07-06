/*
Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.


Example 1:

Input:
      4
    /   \
   2     9
k = 2 
Output: 4


Expected Time Complexity: O(H + K).
Expected Auxiliary Space: O(H) */

// code

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    // Function to find the inorder traversal of a bst
    void inorder(Node* root, vector<int> &ans){
        if(root== NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
        return;
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        // we will store the inorder traversal of the bst in an answer vector 
        // then return the kth largest element
        vector<int> ans;
        if(root == NULL) return 0;
        inorder(root,ans);
        return ans[ans.size()-K];
    }
};
