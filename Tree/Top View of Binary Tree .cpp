/*
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N). */

// code
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // we will solve this problem using level order traversal
        vector<int> ans;
        if(root == NULL) return ans;
        // take a map that will store top view of the binary tree that is the first node
        // coming on the line while seeing the tree from the top
        map<int,int> mp;
        // queue will store all the nodes existing on the line
        queue<pair<Node*, int>> q;
        // first push root with the line number that is 0
        q.push({root,0});
        // if q is not empty
        while(!q.empty()){
            // take out the front element
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            // if the line doesnot exist in the map, insert it with the first node coming on it
            if(mp.find(line) == mp.end()){
                mp[line] = node->data;
            }
            // then check for its left and right
            if(node->left != NULL){
                q.push({node->left,line - 1});
            }
            
            if(node->right != NULL){
                q.push({node->right,line + 1});
            }
        }
        // iterate in the map and print the top view of the binary tree
        for(auto it: mp){
            ans.push_back(it.second);
        }
        // return the result
        return ans;
    }

};
