/* Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.
 
Example 1:

Input: 

Output: 0
Explanation: According to the given edges, all 
nodes can be reaced from nodes from 0, 1 and 2. 
But, since 0 is minimum among 0,1 and 3, so 0 
is the output.

Expected Time Complexity: O(V + E)
Expected Space Compelxity: O(V) */

//code
class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // the idea here is that if we are able to traverse all the nodes starting from any vertex
	    // we will get our possible solution.
	   // declare a visited array
	    vector<int> vis(V+1, 0);
	    int ans = INT_MAX;
	    // do a bfs traversal
	    for(int i = 0; i<V; i++){ // start from 0 vertex
	        if(!vis[i]){
	            queue<int> q;
	            q.push(i);
	            vis[i] = 1;
	            
	            while(!q.empty()){
	                int node = q.front();
	                q.pop();
	                for(auto it: adj[node]){
	                    if(!vis[it]){
	                        q.push(it);
	                        vis[it] = 1;
	                        
	                    }
	                }
	            }
	        }
	        // if after traversing across all it's adjacent, the visited array for all the vertex
	        // is marked true then store the O vertex in our answer
	        for(int i = 0; i<V; i++){
	            if(vis[i] == 1){
	                ans = min(ans, i);
	            }
	            // else store -1
	            else ans = -1;
	        }
	        
	    }
	    // return the minimum vertex answer
	    return ans;
	}
};
