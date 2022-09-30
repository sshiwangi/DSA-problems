/* Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level.

Example 1:

Input :
        1
      /   \
     3     2

Output: 3 2 1
Explanation:
Traversing level 1 : 3 2
Traversing level 0 : 1
Example 2:

Input :
       10
      /  \
     20   30
    / \ 
   40  60

Output: 40 60 20 30 10
Explanation:
Traversing level 2 : 40 60
Traversing level 1 : 20 30
Traversing level 0 : 10

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N) */

//code
/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int>ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* topEle = q.front();
        q.pop();
        ans.push_back(topEle->data);
        if(topEle->right)q.push(topEle->right);
        if(topEle->left)q.push(topEle->left);
    }
    reverse(ans.begin(), ans.end());
    return ans;
    
}
