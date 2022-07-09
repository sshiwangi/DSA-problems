/*
Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

Example 1:

Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N) */

//code

#include <iostream>
using namespace std;

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  int countNodes(Node* root){
      if(root == NULL){
          return 0;
      }
      return 1+ countNodes(root->left) + countNodes(root->right);
  }
  bool isMaxheap(struct Node* root){
      // if it is a leaf node
      if(root->left == NULL && root->right == NULL){
          return true;
      }
      // if only root's left exists
      if(!root->right){
          return (root->data>root->left->data);
      }
      // if both child exists
      else{
          bool left = isMaxheap(root->left);
          bool right = isMaxheap(root->right);
          // all three condition should satisfy for the node to be maxheap
          return (left && right && (root->left->data<root->data && root->right->data<root->data));
      }
   
  }
  bool isCBT(struct Node* root, int index, int n){
      if(root == NULL){
          return true;
      }
      // if at any time the left and right index becomes greater than no of nodes, return false
      if(index>=n){
          return false;
      }
      else{
          bool left = isCBT(root->left, 2*index + 1, n);
          bool right = isCBT(root->right,2*index + 2, n);
          return (left && right);
      }
     
  }
    bool isHeap(struct Node* tree) {
        // code here
        int count = countNodes(tree);
        int i = 0;
        if(isCBT(tree,i,count) && isMaxheap(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};

int main() {
	// your code goes here
    int tc;
    scanf("%d",&tc);
    while(tc--){
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node* root = buildTree(treeString);
        if(ob.isHeap(root)){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
	return 0;
}
