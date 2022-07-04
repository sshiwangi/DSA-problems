// Function to search a node in BST.
bool search(Node* root, int x) {
    // Your code here
    if(root == NULL) return false;
    
    if(root->data == x){
        return true;
    }
    // if the node is less than the root node, check in its left sub tree
    if(x<root->data){
        return search(root->left,x);
    }
    // otherwise check in its right subtree
    return search(root->right,x);
}
