/*
Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.

An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.


Example 1:

Input:
    3
  /   \    
 1     2

Output: 1
Explanation:
The sum of left subtree and right subtree is
1 + 2 = 3, which is the value of the root node.
Therefore,the given binary tree is a sum tree.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of the Tree) */

// code
// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    // Function to check if node's value is equal to left sum or not
    pair<bool,int> solve(Node* root){
        pair<bool,int> curr;
        // if tree is empty
        if(root==NULL){
            curr = {true,0};
            return curr;
            
        }
        // if it is a leaf node
        if(root->left == NULL && root->right == NULL){
            curr = {true,root->data};
            return curr;
        }
         
        pair<bool,int> leftAns = solve(root->left);
        pair<bool,int> rightAns = solve(root->right);
        
        bool left = leftAns.first;
        bool right = rightAns.first;
        
        int leftSum = leftAns.second;
        int rightSum = rightAns.second;
        // if the sum of left's data and right's data is equal to root, condn will be true
         bool condn = root->data == leftSum + rightSum;
         
         pair<bool,int> ans;
         // if left , right and the condn both are true
         if(left && right && condn){
             ans.first = true;
             ans.second = leftSum + rightSum + root->data;
         }
         else{
             ans.first = false;
         }
         
         return ans;
        
    }
         
    bool isSumTree(Node* root)
    {
         return solve(root).first;
         
    }
};
