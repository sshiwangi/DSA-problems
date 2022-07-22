/* Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

Example 1:

Input:  
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
Output: 1

NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.
Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V) */

//code
class Solution
{
  public:
    // Function to detect cycle in undirected graph using DFS
    bool checkCycle(int node, int parent, vector<int> &vis, vector<int> adj[]){
        vis[node] = 1; // mark 1 in visited array
        for(auto it: adj[node]){ // and check for it's adjacent nodes
            if(!vis[it]){
                if(checkCycle(it,node,vis,adj)){
                    return true;
                }
            }
            // if the adjacent node is visited and not parent, then it forms a cycle so return true
            else if(it!=parent) return true;
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // create a visited array
        vector<int> vis(V + 1,0);
        for(int i = 0; i<V; i++){
            if(!vis[i]){ // if node not visited
                if(checkCycle(i,-1, vis, adj)){ // check if this component forms a cycle or not
                    return true;
                }
            }
        }
        return false;
    }
};
