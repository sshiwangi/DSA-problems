/*
Given a sorted array. Convert it into a Height balanced Binary Search Tree (BST). Find the preorder traversal of height balanced BST. If there exist many such balanced BST consider the tree whose preorder is lexicographically smallest.
Height balanced BST means a binary tree in which the depth of the left subtree and the right subtree of every node never differ by more than 1.

Example 1:

Input: nums = {1, 2, 3, 4}
Output: {2, 1, 3, 4}
Explanation: 
The preorder traversal of the following 
BST formed is {2, 1, 3, 4}:
           2
         /   \
           1     3
               \
                4
                
 Expected Time Complexity: O(n)
Expected Space Complexity: O(n)
*/

class Solution{
struct Node{
       int data;
       Node* left;
       Node* right;
       
       Node(int val){
           data = val;
           left = NULL;
           right = NULL;
       }
   };
public:
// Function to print preorder traversal of constructed bst
    void preorder(Node* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->data);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    // Function to build binary search tree from sorted array
    Node* buildBST(vector<int>& nums, int st, int end){
        
        if(st>end){// the array is empty
            return NULL;
        }
        // find the middle element and make it the root
        int mid = (st+end)/2;
        Node* root = new Node(nums[mid]);
        // ans.push_back(nums[mid]);
        root->left = buildBST(nums,st,mid-1);
        root->right = buildBST(nums,mid+1,end);
     
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int>ans;
        // buildBST(nums,0,nums.size()-1,ans);
        Node* root = buildBST(nums,0,nums.size()-1);
        preorder(root,ans);
        return ans;
    }
};
