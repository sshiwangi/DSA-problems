/*
Given two binary trees, the task is to find if both of them are identical or not. 


Example 2:

Input:
     1          1
   /   \      /   \
  2     3    2     3
Output: Yes
Explanation: There are two trees both
having 3 nodes and 2 edges, both trees
are identical having the root as 1,
left child of 1 is 2 and right child
of 1 is 3. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree). */

// code

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1==NULL && r2 == NULL){
            return true;
        }
        else if(r1 == NULL || r2 == NULL){
            return false;
        }
        else{
            bool cond1 = (r1->data == r2->data);
            bool cond2 = isIdentical(r1->left, r2->left);
            bool cond3 = isIdentical(r1->right, r2->right);
            
            if(cond1 && cond2 && cond3){
                return true;
            }
            return false;
        }
    }
};
