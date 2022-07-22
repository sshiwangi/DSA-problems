/* Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V) */

//code
class Solution
{
 public:
    // Function to check cycle in a directed graph
    bool checkCycle(int node, vector<int> adj[], int vis[], int dfsvis[]){
        vis[node] = 1; // mark it in visited array
        dfsvis[node] = 1; // and mark it in dfsvisited array
        
        for(auto it: adj[node]){ // check its adjacent node
            if(!vis[it]){ // if not visited
                if(checkCycle(it,adj,vis,dfsvis)) return true;
                
            }
            // if its mark in visited array and also marked in dfsvis then return true
            else if(dfsvis[it]){
                return true;
            }
        }
        // the node and it's adjacent doesnot return true, return and while returning unmark dfsvis array
        dfsvis[node] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // maintain two arrays
        int vis[V], dfsvis[V];
        memset(vis,0,sizeof vis);
        memset(dfsvis,0,sizeof dfsvis);
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){ // if the node is not visited
                if(checkCycle(i,adj,vis,dfsvis)){
                    return true;
                }
            }
        }
        return false;
    }
};
