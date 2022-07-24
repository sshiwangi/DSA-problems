/* Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

Expected Time Complexity: O(V+E).
Expected Auxiliary Space: O(V). */

//code
class Solution
{
	public:
	//Function to find topo sort of the graph
	void dfs(int node, stack<int> &st, vector<int>&vis, vector<int> adj[]){
	    vis[node] = 1;
	    for(auto it: adj[node]){
	        if(!vis[it]){
	            dfs(it,st,vis,adj);
	        }
	    }
	    st.push(node);
	}
	//Function to count number of strongly connected components in the graph
	void reverseDfs(int node, vector<int>& vis, vector<int> transpose[]){
	    
	    vis[node] = 1;
	    for(auto it: transpose[node]){
	        if(!vis[it]){
	            reverseDfs(it,vis,transpose);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //finding topo sort
        stack<int> st;
        vector<int> vis(V,0);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i,st,vis,adj);
            }
        }
        // vector to store transpose of the graph
        vector<int> transpose[V];
        for(int i = 0; i<V; i++){
            vis[i] = 0;
            for(auto it: adj[i]){
                transpose[it].push_back(i);
            }
        }
        int count = 0;
        // take out the elements of stack one by one and call reverse dfs if it is not visited
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                count++;
                reverseDfs(node,vis,transpose);
            }
        }
        return count;
    }
};
