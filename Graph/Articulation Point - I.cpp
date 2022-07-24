/* Given an undirected connected graph with V vertices and adjacency list adj. 
You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

Your Task:
You don't need to read or print anything. Your task is to complete the function articulationPoints() which takes V and adj as input parameters and returns a list 
containing all the vertices removing which turn the graph into two or more disconnected components in sorted order. If there are no such vertices then returns a list 
containing -1.
 

Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V) */

//code
class Solution {
  public:
    void dfs(int node, int parent, vector<int>&vis, vector<int> &tin, vector<int>&low, int &timer,
    vector<int> adj[], vector<int> &isArticulation){
        vis[node] = 1; // mark the node to be visited
        tin[node] = low[node] = timer++; // increase tin and low
        int child = 0; // to store it's individual child
        for(auto it: adj[node]){ // traverse along its adjacent
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it,node,vis,tin,low,timer,adj,isArticulation);
                low[node] = min(low[node], low[it]); // if any of its adjacent has lower time of insertion, update its lower time of insertion
                if(low[it]>= tin[node] && parent!=-1){ // if the node is an articulation point
                    isArticulation[node] = 1; // mark it to be true
                }
                child++;
            }// if node visited
            else{
                low[node] = min(low[node],tin[it]);
            }
        }
        if(parent == -1 && child>1){
            isArticulation[node] = 1;
        }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> tin(V,-1); // declare time of insertion vector and initialize it with -1
        vector<int> low(V,-1); // lowest time of insertion among all adjacent
        vector<int> vis(V,0); // visited array
        vector<int> isArticulation(V,0); // initialize it with 0
        int timer = 0;
        // simple dfs call
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i, -1, vis, tin, low, timer,adj, isArticulation);
            }
        }
        vector<int> ans;
        for(int i = 0; i<V; i++){
            if(isArticulation[i] == 1){
                ans.push_back(i);
            }
            
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};
