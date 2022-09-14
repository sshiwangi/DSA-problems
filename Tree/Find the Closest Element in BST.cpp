/* Given a BST and an integer. Find the least absolute difference between any node value of the BST and the given integer.

Example 1:

Input:
        10
      /   \
     2    11
   /  \ 
  1    5
      /  \
     3    6
      \
       4
K = 13
Output: 2
Explanation: K=13. The node that has
value nearest to K is 11. so the answer
is 2
Example 2:

Input:
      8
    /   \
   1     9
    \     \
     4    10
    /
   3
K = 9
Output: 0
Explanation: K=9. The node that has
value nearest to K is 9. so the answer
is 0.

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= Number of nodes <= 100000 */

//code
class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
	void solve(Node* root, int K, int &ans){
	    if(root==NULL){
	        return;
	    }
	    if(abs(root->data - K)<ans){
	        ans = abs(root->data - K);
	    }
	    solve(root->left,K,ans);
	    solve(root->right,K,ans);
	}
    int minDiff(Node *root, int K)
    {
        //Your code here
        int ans = INT_MAX;
        solve(root,K,ans);
        return ans;
    }
};
