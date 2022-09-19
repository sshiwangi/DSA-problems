/* Given a BST and a value k, the task is to delete the nodes having values greater than or equal to k.

Example 1:

Input:
    4   
   / \  
  1   9 
k = 2 
Output:
1
Your Task:
The task is to complete the function deleteNode() which takes root, k as the argument, and returns the root of tree after deleting values greater than or equal to k. 
The driver code will print the inorder traversal of the updated tree in output itself.

Expected Time Complexity: O(Size of tree)
Expected Auxiliary Space: O(1). */

//code

class Solution{
  public:
    /*The function should return the root of the modified tree*/
    Node* deleteNode(Node* root, int k)
    {
        //Your code here
        if(root == NULL)return NULL;
        if(root->data >= k){
            root = deleteNode(root->left,k);
        }
        else if(root->data < k){
            root->right = deleteNode(root->right,k);
        }
        return root;
    }
};
