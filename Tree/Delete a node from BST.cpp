/*
Given a Binary Search Tree and a node value X. Delete the node with the given value X from the BST. If no node with value x exists, then do not make any change. 

Example 1:

Input:
      2
    /   \
   1     3
X = 12
Output: 1 2 3
Explanation: In the given input there
is no node with value 12 , so the tree
will remain same.

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).*/

// code
//keep going across right and return last right
Node* findLastRight(Node* root){
    if(root->right == NULL){
        return root;
    }
    return findLastRight(root->right);
}
// this function will delete the node and return the new rearranged part of the tree
// which will get attached to the left or right pointer
Node* helper(Node* root){
    if(root->left == NULL){
        return root->right;
    }
    else if(root->right == NULL){
        return root->left;
    }
    Node* rightChild = root->right;
    Node* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}
// Function to delete a node from BST.
Node *deleteNode(Node *root, int X) {
    // your code goes here
    if(root == NULL){
        return NULL;
    }
    if(root->data == X){
        return helper(root);
    }
    // since we are traversing, the root might be lost so store it in a dummy node
    Node* dummy = root;
    while(root!=NULL){
        if(root->data > X){
            if(root->left!=NULL && root->left->data == X){
                root->left = helper(root->left);
                break;
            }else{
                root = root->left;
            }
        }
        else{
            if(root->right!=NULL && root->right->data == X){
                root->right = helper(root->right);
                break;
            }else{
                root = root->right;
            }
        }
    }
    return dummy;

}
