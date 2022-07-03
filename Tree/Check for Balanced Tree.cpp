/*
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5
Expected time complexity: O(N)
Expected auxiliary space: O(h) , where h = height of tree
*/


#include <iostream>
using namespace std;
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    public:
    
    int checkForBT(Node* root){
        if(root == NULL){
            return 0;
        }
        int leftHeight = checkForBT(root->left);
        // if any of the left subtree or right subtree returns -1, we will return -1 which means the tree is unbalanced
        if(leftHeight == -1){
            return -1;
        }
        int rightHeight = checkForBT(root->right);
        
        if(rightHeight == -1){
            return -1;
        }
        
        if(abs(leftHeight-rightHeight)>1){
            return -1;
        }
      // if the function returns the height of the tree, it will be balanced
        return max(leftHeight,rightHeight) + 1;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return checkForBT(root) != -1;
    }
};
int main() {
	// your code goes here
    int t;
    scanf("%d", &t);
    while(t--){
        string s,ch;
        getline(cin,s);

        Node* root = buildTree(s);
        Solution ob;
        cout<< ob.isBalanced(root) << endl;
    }
	return 0;
}
