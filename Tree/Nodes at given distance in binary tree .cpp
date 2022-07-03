/*
Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. No parent pointers are available.

Example 1:

Input:      
          20
        /    \
      8       22 
    /   \
   4    12 
       /   \
      10    14
Target Node = 8
K = 2
Output: 10 14 22
Explanation: The three nodes at distance 2
from node 8 are 10, 14, 22.
*/

class Solution
{
private:
    Node* getNode;

public:
    // storing the parent of each node in hash map
    void markParents(Node* root, int target, unordered_map<Node*, Node*> &parent){
        
        queue<Node*> q;
        q.push(root);
        parent[root] = NULL;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr->data == target){
                getNode = curr;
            }
            if(curr->left){
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
   
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        unordered_map<Node*, Node*> parent;
        markParents(root,target,parent);
        unordered_map<Node*,bool> vis;
        queue<Node*> q;
        q.push(getNode);
        vis[getNode] = true;
        int curr_level = 0;
        while(!q.empty()){
            int size = q.size();
            if(curr_level++ == k)break;
            
            for(int i = 0; i<size; i++){
                Node* curr = q.front();
                q.pop();
                
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                
                if(parent[curr] && !vis[parent[curr]]){
                    q.push(parent[curr]);
                    vis[parent[curr]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            Node* curr =q.front();
            q.pop();
            ans.push_back(curr->data);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
