/*
Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:

Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

*/

//code

{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        // map will store all nodes lying on a line
        map<int,vector<int>> mp;
        // queue will store node and line pair one by one
        // we will first store the root with its line number {root,0} in the queue then
        // we will take out the nodes out of the queue until it becomes empty then
        //and then we will push it in map
        // we will check for its left and right and if they exist we will insert them.
        queue<pair<Node*, int>> q;
        vector<int> ans;
        if(root == NULL) return ans;
        q.push({root,0});
        while(!q.empty()){
            Node* temp = q.front().first;
            int line = q.front().second;
            mp[line].push_back(temp->data);
            q.pop();
            if(temp->left) q.push({temp->left,line-1});
            if(temp->right) q.push({temp->right,line+1});
        }
        // iterate in the map and store the nodes in the answer vector
        for(auto it: mp){
            for(auto i:it.second){
                ans.push_back(i);
            }
        }
        return ans;
    }

};
