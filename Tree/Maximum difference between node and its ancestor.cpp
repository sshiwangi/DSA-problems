/* Given a Binary Tree, you need to find the maximum value which you can get by subtracting the value of node B from the value of node A,
where A and B are two nodes of the binary tree and A is an ancestor of B. 

Example 1:

Input:
    5
 /    \
2      1
Output: 4
Explanation:The maximum difference we can
get is 4, which is bewteen 5 and 1.
Example 2:

Input:
      1
    /    \
   2      3
           \
            7
Output: -1
Explanation:The maximum difference we can
get is -1, which is between 1 and 2.
Your Task:
The task is to complete the function maxDiff() which finds the maximum difference between the node and its ancestor.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree.

Constraints:
2 <= Number of edges <= 104
0 <= Data of a node <= 105 */

//code
/* A binary tree node

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
int solve(Node* root, int &ans){
    if(!root)return INT_MAX;
    int left = solve(root->left,ans);
    int right = solve(root->right,ans);
    ans = max(ans, max(root->data-left, root->data-right));
    return min(left, min(right,root->data));
}
//Function to return the maximum difference between any node and its ancestor.
int maxDiff(Node* root)
{
    // Your code here 
    int ans = INT_MIN;
    solve(root,ans);
    return ans;
}
