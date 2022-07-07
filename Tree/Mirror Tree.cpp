/* Given a Binary Tree, convert it into its mirror.
Example 1:

Input:
      1
    /  \
   2    3
Output: 3 1 2
Explanation: The tree is
   1    (mirror)  1
 /  \    =>      /  \
2    3          3    2
The inorder of mirror is 3 1 2

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree). */

// code

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(node==NULL) return;
        mirror(node->left);
        mirror(node->right);
        swap(node->left,node->right);
        // node->left = node->right;
        // node->right = node->left;
        return;
    }
};
