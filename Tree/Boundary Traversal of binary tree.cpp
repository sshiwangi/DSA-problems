/*
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3

Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(Height of the Tree). */

// code
class Solution {
public:
    // function to check if the node is leaf node or not
    bool isLeaf(Node * root) {
  return !root -> left && !root -> right;
}
    
    // function to add left boundary nodes
    void addLeftBoundary(Node* root, vector<int> &res){
        Node* curr = root->left;
        while(curr){
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    // function to add right boundary nodes
    void addRightBoundary(Node* root, vector<int> &res){
        Node* curr = root->right;
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        // adding the nodes in reverse order
        for(int i = temp.size()-1; i>=0; --i){
            res.push_back(temp[i]);
        }
    }
    
    // function to add leaves
    void addLeaves(Node* root, vector<int> &res){
        // simple inorder traversal
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left) addLeaves(root->left,res);
        if(root->right) addLeaves(root->right,res);
    }
    
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> res;
        // if it is an empty tree
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root,res);
        addLeaves(root,res);
        addRightBoundary(root,res);
        return res;
    }
};
