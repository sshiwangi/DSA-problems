/* Given a Directed Graph with V vertices and E edges, Find the members of strongly connected components in the graph.

Your Task:
You don't need to read input or print anything. Your task is to complete the function tarjans() which takes the number of vertices V and adjacency list of the graph 
as input parameters and returns a list of list of integers denoting the members of strongly connected components in the given graph.
Note: A single strongly connected component must be represented in the form of a list if integers sorted in the ascending order. 
The resulting list should consist of a list of all SCCs which must be sorted in a way such that a lexicographically smaller list of integers appears first.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V). */

//code
class Solution
{
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
	void reverseDfs(int node, vector<int>& vis, vector<int> transpose[], vector<int> &component){
	    component.push_back(node);
	    vis[node] = 1;
	    for(auto it: transpose[node]){
	        if(!vis[it]){
	            reverseDfs(it,vis,transpose,component);
	        }
	    }
	}
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
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
        vector<vector<int>> res;
        // take out the elements of stack one by one and call reverse dfs if it is not visited
        while(!st.empty()){
            int node = st.top();
            st.pop();
            vector<int> component;
            if(!vis[node]){
                reverseDfs(node,vis,transpose,component);
                
            }
            if(component.size()!=0){
                sort(component.begin(),component.end());
                res.push_back(component);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
