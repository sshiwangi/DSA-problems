/* Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V) */

//code
class Solution
{
public:
    // Function to check if the graph is bipartite or not
    bool checkBipartite(int src, vector<int>adj[], int color[]){
        queue<int>q;
        q.push(src);
        // if node not colored, color it and check for it's adjacent
        color[src] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                if(color[it] == -1){
                   color[it] = 1 - color[node];
                   q.push(it);
                }
                // if colored, then check if it doesn't have same color as it's adjacent
                else if(color[it] == color[node]) return false;
            }
        
        }
        
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int color[V];
	    memset(color,-1,sizeof color);
	    for(int i = 0; i<V; i++){
	        if(color[i] == -1){ // if the node is not colored
	            if(!checkBipartite(i,adj,color)){
	               return false; 
	            }
	        } 
	    }
	    return true;
	}

};
