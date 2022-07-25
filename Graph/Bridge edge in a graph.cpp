/* Given a Graph of V vertices and E edges and another edge(c - d), the task is to find if the given edge is a Bridge. i.e., removing the edge disconnects the graph.
c = 1, d = 2
Output:
1
Explanation:
From the graph, we can clearly see that
blocking the edge 1-2 will result in 
disconnection of the graph. So, it is 
a Bridge and thus the Output 1.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V). */

//code
class Solution
{
	public:
	// Function to find the bridges in graph
	void dfs(int node, int parent, vector<int>&vis, vector<int>&tin, vector<int> &low, int &timer,
	 vector<int>adj[]){
	     vis[node] = 1;
	     tin[node] = low[node] = timer++;
	     for(auto it: adj[node]){
	         if(it == parent) continue;
	         if(!vis[it]){
	             dfs(it,node,vis,tin,low,timer,adj);
	             low[node] = min(low[node],low[it]);
	             
	         }
	         else{
	             low[node] = min(low[node],tin[it]);
	         }
	     }
	 }
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int> tin(V,-1);
        vector<int> low(V,-1);
        vector<int> vis(V,0);
        int timer = 0;
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i,-1,vis,tin,low,timer,adj);
            }
        }
        // if lowest time of insertion of adjacent node is greater than time of insertion of node,
        //we'll get our cut vertex
        if(low[c]>tin[d] || low[d] > tin[c]) return 1;
        else return 0;
    }
};
