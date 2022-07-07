/*
Given two binary trees with head reference as T and S having at most N nodes. The task is to check if S is present as subtree in T.
A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.

Example 1:

Input:
T:      1          S:   3
      /   \            /
     2     3          4
   /  \    /
  N    N  4
Output: 1 
Explanation: S is present in T

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N). */

// code
class Solution
{
  public:
  // Function to check if the trees are identical or not
  bool treeSame(Node* T, Node* S){
        if(T == NULL && S == NULL) return true;
        if(T == NULL || S ==NULL) return false;
        
        bool left,right;
        
        if(T->data == S->data){
            left = treeSame(T->left,S->left);
            right = treeSame(T->right, S->right);
            
            return left&&right;
            
        }
        return false;
  }
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {
      // if T is null there is no way s exists as a subtree in it
        if(T==NULL){
            return false;
        }
        // if s is a null, its always present in the tree t
        if(S==NULL){
            return true;
        }
        
        // if both trees are identical
        if(treeSame(T,S)){
            return true;
        } 
        // if trees are not identical, check the tree s in the left then in the right of the t
        bool left = isSubTree(T->left,S);
        bool right = isSubTree(T->right,S);
        // if we find the subree s in any of the left and right of the tree t, return true;    
        return left || right;
    
        
    }
};
