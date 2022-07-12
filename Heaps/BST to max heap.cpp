/* Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Max Heap.

Example 1:

Input :
                 4
               /   \
              2     6
            /  \   /  \
           1   3  5    7  

Output : 1 2 3 4 5 6 7 
Exaplanation :
               7
             /   \
            3     6
          /   \  /   \
         1    2 4     5
The given BST has been transformed into a
Max Heap and it's postorder traversal is
1 2 3 4 5 6 7.

Expected Time Complexity : O(n)
Expected Auxiliary Space : O(n)
  */

// code
// Condition of max heap is: N > L and N > R
// and the question's condition is: L < R
// So merging the two condition, we will have L < R < N which is postorder
// Traverse in the inorder array and fill the tree by traversing in the postorder traversal
// technique that is left, right, node
class Solution{
  public:
    void findInorder(Node* root, vector<int> &inorder){
        // base case
        if(root == NULL){
            return;
        }
        findInorder(root->left,inorder);
        inorder.push_back(root->data);
        findInorder(root->right,inorder);
    }
    void fillpostorder(Node* root, vector<int> &inorder, int &idx){
        //base case
        if(root == NULL){
            return;
        }
        fillpostorder(root->left,inorder,idx);
        fillpostorder(root->right,inorder,idx);
        root->data = inorder[idx];
        idx++;
    }
    void convertToMaxHeapUtil(Node* root)
    {
        // Your code goes here
        int i = 0;
        vector<int> inorder;
        findInorder(root,inorder);
        fillpostorder(root,inorder,i);
    }    
};
