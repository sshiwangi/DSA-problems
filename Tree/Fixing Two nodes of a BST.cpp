/*
You are given the root of a binary search tree(BST), where exactly two nodes were swapped by mistake. Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be reflected in the original linked list.
 
Example 1:
Input:
       10
     /    \
    5      8
   / \
  2   20
Output: 1

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1) */

class Solution {
    Node* first; // stores the first violated element
    Node* middle; //stores adjacent element
    Node* prev; //stores the previous or last element in inorder traversal
    Node* last; //stores the second violated element
    
    void inorder(Node* root){
        if(root == NULL)return;
        
        inorder(root->left);
        
        // main task goes here
        
        if(prev!=NULL && root->data < prev->data){
            //if this is the first violation, mark these two nodes as 'first', and middle
            if(first == NULL){
                first = prev;
                middle = root;
            }
            // if this is second violation, mark this node as last
            else{
                last = root;
            }
        }
        // mark this node as previous
        prev = root;
        inorder(root->right);
    }
  public:
    void correctBST( struct Node* root )
    {
        // add code here.
        first = middle = last = NULL;
        prev = new Node(INT_MIN);
        inorder(root);
        // if the swapped nodes are not adjacent
        if(first && last) swap(first->data,last->data);
        // if the swapped nodes are adjacent
        else if(first && middle) swap(first->data,middle->data);
    }
};
