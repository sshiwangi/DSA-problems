/*
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.
 

Example 1:

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation:
First case represents a tree with 3 nodes
and 2 edges where root is 1, left child of
1 is 3 and right child of 1 is 2.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N). */

// code

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,int> mp; // this map will store the last node on the line when viewed from the bottom
        // we don't need to store all values of node in the vector on every line in the map, we will
        // simply overwrite the next nodes on the line.
        vector<int> ans;
        
        if(!root) return ans;
        queue<pair<Node*, int >> q;
        q.push({root, 0});
        while(!q.empty()){
            Node* temp= q.front().first;
            int line = q.front().second;
            mp[line] = temp->data; // if the line has more than one node, the map contains the last node
            q.pop();
            if(temp->left) q.push({temp->left,line-1});
            if(temp->right) q.push({temp->right,line+1});
        }
        for(auto it: mp) ans.push_back(it.second);
        return ans;
    }
};
