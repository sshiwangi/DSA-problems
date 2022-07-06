/*
Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST. 
Note: If K is already present in the BST, don't modify the BST.


Example 1:

Input:
     2
   /   \
  1     3
K = 4
Output: 1 2 3 4
Explanation: After inserting the node 4
Inorder traversal will be 1 2 3 4.

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST). */

//code

// Function to insert a node in a BST.
Node* insert(Node* root, int Key) {
    // if root is null,return key as node
    if(!root) return new Node(Key);
    
    Node* curr = root;
    // if curr exists
    while(curr){
        // if key is present, break and return root
        if(curr->data == Key){
            break;
        }
        // if key is less than left node
        if(Key<curr->data){
            if(curr->left == NULL){
                curr->left = new Node(Key);
                break;
            }
            else{
                curr = curr->left;
            }
        }
        // if key is greater than  right node
        else{
            if(curr->right == NULL){
                curr->right = new Node(Key);
                break;
            }
            else{
                curr = curr->right;
            }
        }
    }
    return root;
   
}
