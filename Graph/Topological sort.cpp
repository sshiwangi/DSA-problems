/* Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.
Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V). */

class Solution
{
	public:
	//Function to find topological sort of a graph
	void findTopoSort(int node,vector<int> &vis, stack<int> &st, vector<int> adj[] ){
	    vis[node] = 1;
	    for(auto it: adj[node]){
	        if(!vis[it]){
	            findTopoSort(it,vis,st,adj);
	        }
	    }
	    // if done with all the adjacent of a node, put it in the stack
	    st.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> st;
	    vector<int> vis(V,0);
	    for(int i = 0; i<V; i++){
	        if(vis[i]==0){
	            findTopoSort(i,vis,st,adj);
	        }
	    }
	    vector<int> topo; // stores the toplogical sort order of graph
	    while(!st.empty()){
	        topo.push_back(st.top());
	        st.pop();
	    }
	    return topo;
	}
};
